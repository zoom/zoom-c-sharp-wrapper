using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace zoom_sdk_demo
{
    public class ZoomCaptioner
    {
        public ZoomCaptioner(
            string baseUrl
            )
        {
            _baseUrl = baseUrl;
        }

        public async Task SendCaptionAsync(
            string captionContent
            )
        {
            await _semaphore.WaitAsync().ConfigureAwait(false);
            try
            {
                await InternalPostCaptionAsync(captionContent, _sequence);
            }
            catch(Exception ex)
            {
                Console.WriteLine($"Zoom caption posting failed {ex}");
            }
            finally
            {
                _sequence += 1;
                _semaphore.Release();
            }
        }

        private async Task InternalPostCaptionAsync(
            string captionContent,
            long sequenceNumber
            )
        {
            using var timeout = new CancellationTokenSource(CaptionTimeout);

            var captionUrl = _baseUrl + $"&lang=en-US&seq={sequenceNumber}";
            using var response = await _client.PostAsync(
                captionUrl,
                new StringContent(captionContent),
                timeout.Token
            );

            if (response.IsSuccessStatusCode)
                return;

            if (IgnoreableZoomCaptionFailureResponseCodes.Contains(response.StatusCode))
                Console.WriteLine("Zoom caption has failed to post with status code: {statusCode}", response.StatusCode);
            else
                Console.WriteLine("Zoom caption has failed to post with status code: {statusCode}", response.StatusCode);
        }

        private static readonly HttpStatusCode[] IgnoreableZoomCaptionFailureResponseCodes = {
            HttpStatusCode.BadRequest,
            HttpStatusCode.Forbidden,
            HttpStatusCode.MethodNotAllowed,
            HttpStatusCode.RequestTimeout,
            HttpStatusCode.InternalServerError,
            HttpStatusCode.BadGateway,
            HttpStatusCode.ServiceUnavailable,
            HttpStatusCode.GatewayTimeout,
        };

        private int _sequence;
        private string _baseUrl;
        private static readonly HttpClient _client = new HttpClient();
        private static readonly TimeSpan CaptionTimeout = TimeSpan.FromSeconds(2);
        private static SemaphoreSlim _semaphore = new SemaphoreSlim(1, 1);
    }
}
