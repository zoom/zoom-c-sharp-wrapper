using System;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoomapp
{
    public class RevAudioReceiver : IAudioRawDataReceiverDotNetWrap
    {
        public void onMixedAudioRawDataReceived(DotNetAudioRawData data_)
        {
            //var bytes = string.Join(", ", data_.GetBuffer());
            //Console.WriteLine($"mixed audio received {bytes}");
        }

        public void onOneWayAudioRawDataReceived(DotNetAudioRawData data_, uint node_id)
        {
            var user = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap()
                .GetMeetingParticipantsController().GetUserByUserID(node_id);
            Console.WriteLine(node_id);
            Console.WriteLine($"one way audio received from {user.GetUserNameW()}");
        }
    }
}
