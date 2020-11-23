using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.WebSockets;
using System.Threading;
using System.Threading.Tasks;

namespace zoom_sdk_demo
{
    public static class Extensions
    {
        public static K? Map<T, K>(this T? value, Func<T, K> transform) where T : struct where K : struct
            => value.HasValue ? transform.Invoke(value.Value) : (K?)null;

        public static async Task<(WebSocketMessageType type, ArraySegment<byte> data)?> ReceiveFullMessageAsync(
            this WebSocket socket,
            CancellationToken cancel = default
            )
        {
            var extraBuffer = new MemoryStream();
            var buffer = new ArraySegment<byte>(new byte[100 * 1024]);
            while (ReadingStates.Contains(socket.State) && !cancel.IsCancellationRequested)
            {
                var res = await socket.ReceiveAsync(buffer, cancel).ConfigureAwait(false);
                // use the extraBuffer if couldn't receive entire message with one operation
                if (res.Count > 0 && (extraBuffer.Length > 0 || !res.EndOfMessage))
                {
                    extraBuffer.Write(buffer.Array, (int)extraBuffer.Length, res.Count);
                }
                // close frame can arrive in a middle of a data frame - in this case we drop the data frame
                if (res.MessageType == WebSocketMessageType.Close)
                {
                    // we don't support data for the close frame
                    return (
                        type: res.MessageType,
                        data: new ArraySegment<byte>(new byte[0])
                    );
                }
                if (res.EndOfMessage)
                {
                    ArraySegment<byte> segment;
                    if (extraBuffer.Length > 0)
                    {
                        segment = new ArraySegment<byte>(extraBuffer.GetBuffer());
                    }
                    else
                    {
                        segment = new ArraySegment<byte>(buffer.Array.Take(res.Count).ToArray());
                    }
                    return (
                        type: res.MessageType,
                        data: segment
                    );
                }
            }
            return null;
        }

        public static readonly IReadOnlyList<WebSocketState> ReadingStates = new[] {
            WebSocketState.Open, WebSocketState.CloseSent
        };
    }
}
