using System;
using System.Collections.Generic;
using System.IO;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
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
            if (!_dataStreams.ContainsKey(0))
            {
                var path = Path.GetTempFileName();
                _dataStreams.Add(0, new FileStream(path, FileMode.OpenOrCreate));
            }
            if (data_.GetBufferLen() > 0)
            {
                var data = data_.GetBuffer();

                _dataStreams[0].Write(data, 0, data.Length);
            }
        }

        public void onOneWayAudioRawDataReceived(DotNetAudioRawData data_, uint node_id)
        {
            //Console.WriteLine(data_.GetSampleRate());
            //if (!_dataStreams.ContainsKey(node_id))
            //{
            //    var path = Path.GetTempFileName();
            //    _dataStreams.Add(node_id, new FileStream(path, FileMode.OpenOrCreate));
            //}
            //if (data_.GetBufferLen() > 0)
            //{
            //    var data = data_.GetBuffer();

            //    _dataStreams[node_id].Write(data, 0, data.Length);
            //}
        }

        public void Finish()
        {
            Console.WriteLine("Audio files written to:");
            foreach(var file in _dataStreams.Values)
            {
                Console.WriteLine($"{file.Name}");
            }
        }

        private readonly Dictionary<uint, FileStream> _dataStreams;
    }
}
