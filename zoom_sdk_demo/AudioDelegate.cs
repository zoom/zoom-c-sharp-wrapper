using System;
using System.Collections.Generic;
using System.Threading.Channels;
using System.Threading.Tasks;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    public class AudioDelegate : IZoomSDKAudioRawDataDotNetDelegate
    {
        public AudioDelegate()
        {
            Stream = Channel.CreateUnbounded<(uint, DotNetAudioRawData)>();
            _streamers = new Dictionary<uint, RevAiStreamer>();
        }

        public void onMixedAudioRawDataReceived(
            DotNetAudioRawData data_
            )
        {
        }

        public void onOneWayAudioRawDataReceived(
            DotNetAudioRawData data_,
            uint node_id
            )
        {
            Stream.Writer.TryWrite((node_id, data_));
        }

        public async Task StartStreamingAsync()
        {
            while(!Stream.Reader.Completion.IsCompleted)
            {
                var (id, data) = await Stream.Reader.ReadAsync();

                if (!_streamers.ContainsKey(id))
                {
                    var streamer = new RevAiStreamer(
                        CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingParticipantsController()
                            .GetUserByUserID(id).GetUserNameW()
                    );
                    await streamer.StartAsync();
                    _streamers.Add(id, streamer);
                }

                await _streamers[id].SendDataAsync(data.GetBuffer());
            }
        }

        public Channel<(uint, DotNetAudioRawData)> Stream { get; set; }

        private readonly Dictionary<uint, RevAiStreamer> _streamers;
    }
}
