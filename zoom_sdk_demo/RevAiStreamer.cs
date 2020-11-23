using Newtonsoft.Json;
using System;
using System.Linq;
using System.Net.WebSockets;
using System.Text;
using System.Threading.Tasks;

namespace zoom_sdk_demo
{
    public class RevAiStreamer
    {
        public RevAiStreamer(
            string speaker
            )
        {
            _speaker = speaker;
            _socket = new ClientWebSocket();
        }

        private readonly string _speaker;
        private readonly ClientWebSocket _socket;

        public async Task StartAsync()
        {
            var url = new Uri($"{Url}?access_token={AccessToken}&content_type=audio/x-raw;layout=interleaved;rate=32000;format=S16LE;channels=1");
            await _socket.ConnectAsync(url, default).ConfigureAwait(false);
            try
            {
                var id = await ConnectHandshakeAsync().ConfigureAwait(false);
                _ = StartReceiveLoopAsync().ConfigureAwait(false);
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine($"Failed to connect to rev.ai - {ex.Message}");
            }
        }

        public async Task SendDataAsync(
            byte[] data
            )
        {
            if (_socket.State == WebSocketState.Open)
            {
                await _socket.SendAsync(new ArraySegment<byte>(data), WebSocketMessageType.Binary, true, default)
                    .ConfigureAwait(false);
            }
        }

        internal async Task StartReceiveLoopAsync()
        {
            while (Extensions.ReadingStates.Contains(_socket.State))
                switch (await _socket.ReceiveFullMessageAsync(default).ConfigureAwait(false))
                {
                    case null:
                        Console.WriteLine("Socket in closed state");
                        return;
                    case var received when received.Value.type == WebSocketMessageType.Text:
                        var message = ParseMessage<RevAiMessage>(received.Value.data);
                        if (message.Type == "final")
                        {
                            var textTranscript = $"{_speaker}: {String.Join("", message.Elements.Select(e => e.Value))}";
                            Console.WriteLine(textTranscript);
                        }                        
                        continue;
                    case var close when close.Value.type == WebSocketMessageType.Close:
                        Console.WriteLine("Close received");
                        return;
                    default:
                        Console.WriteLine("Unexpected data received");
                        break;
                }
            return;
        }

        private async Task<string> ConnectHandshakeAsync()
        {
            switch (await _socket.ReceiveFullMessageAsync(default).ConfigureAwait(false))
            {
                case var received when received.Value.type == WebSocketMessageType.Text:
                    var message = ParseMessage<ConnectedMessage>(received.Value.data);
                    if (message?.Type != "connected")
                    {
                        throw new Exception("Unexpected format of the connected message");
                    }
                    return message.Id;
                case null:
                    throw new Exception("Unexpected data received");
                case var close when close.Value.type == WebSocketMessageType.Close:
                    throw new Exception($"WebSocket closed with {(int)_socket.CloseStatus} {_socket.CloseStatus} during connection handshake. {_socket.CloseStatusDescription}");
                default:
                    throw new Exception("Unexpected data received");
            }
        }

        private T ParseMessage<T>(
            ArraySegment<byte> data
            )
        {
            return JsonConvert.DeserializeObject<T>(Encoding.UTF8.GetString(data.Array));
        }

        private const string Url = "wss://api.rev.ai/speechtotext/v1/stream";
        private const string AccessToken = "02kQoXp3YkWGIg5lkvV3EtdNB3vOsOYSfq0MUnlQioSLD54awVYU_1Lt9viYHnX5yhhXXZuHAzkmIeNqJI0pi2dGVQWSA";
    }
}
