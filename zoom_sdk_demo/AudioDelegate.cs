using System;
using System.Collections.Generic;
using System.Threading.Channels;
using System.Threading.Tasks;
using System.IO;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    public class AudioDelegate : IZoomSDKAudioRawDataDotNetDelegate
    {
        public AudioDelegate(
            string captionUrl
            )
        {
            Stream = Channel.CreateUnbounded<(uint, byte[])>();
            _streamers = new Dictionary<uint, RevAiStreamer>();
            _captioner = new ZoomCaptioner(captionUrl);
        }

        public void onMixedAudioRawDataReceived(
            DotNetAudioRawData data_
            )
        {
            //if (!_streamers.ContainsKey(1))
            //{
            //    var streamer = new RevAiStreamer(
            //        "name"
            //    );
            //    streamer.StartAsync().Wait();
            //    _streamers.Add(1, streamer);
            //}

            //_streamers[1].ByteChannel.Writer.TryWrite(data_.GetBuffer());
        }

        public void onOneWayAudioRawDataReceived(
            DotNetAudioRawData data_,
            uint node_id
            )
        {
            if (!_streamers.ContainsKey(node_id))
            {
                var streamer = new RevAiStreamer(
                    CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingParticipantsController()
                        .GetUserByUserID(node_id).GetUserNameW(),
                    _captioner
                );
                streamer.StartAsync().Wait();
                _streamers.Add(node_id, streamer);
            }

            _streamers[node_id].ByteChannel.Writer.TryWrite(data_.GetBuffer());
        }

        public Channel<(uint, byte[])> Stream { get; set; }

        private readonly Dictionary<uint, RevAiStreamer> _streamers;
        private readonly ZoomCaptioner _captioner;
    }
}
