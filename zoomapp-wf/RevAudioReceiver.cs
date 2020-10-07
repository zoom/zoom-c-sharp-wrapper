using System;
using System.Collections.Generic;
using System.IO;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoomapp_wf
{
    public class RevAudioReceiver : IAudioRawDataReceiverDotNetWrap
    {
        public RevAudioReceiver()
        {
            _dataStreams = new Dictionary<uint, FileStream>();
        }

        public void onMixedAudioRawDataReceived(DotNetAudioRawData data_)
        {
            Console.WriteLine($"Sample Rate: {data_.GetSampleRate()}");
        }

        public void onOneWayAudioRawDataReceived(DotNetAudioRawData data_, uint node_id)
        {
            Console.WriteLine(node_id);
            //if (!_dataStreams.ContainsKey(node_id))
            //{
            //    var path = Path.GetTempFileName();
            //    _dataStreams.Add(node_id, new FileStream(path, FileMode.OpenOrCreate));
            //}
            //_dataStreams[node_id].Write(data_.GetBuffer(), 0, (int)data_.GetBufferLen());
        }

        private readonly Dictionary<uint, FileStream> _dataStreams;
    }
}
