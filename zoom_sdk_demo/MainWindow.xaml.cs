using System;
using System.ComponentModel; // CancelEventArgs
using System.Threading.Tasks;
using System.Windows;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var args = Environment.GetCommandLineArgs();
            AuthSDK(args[1], args[2], args[3]);
        }

        private void AuthSDK(
            string zoomKey,
            string zoomSecret,
            string meetingId
            )
        {
            CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().Add_CB_onAuthenticationReturn((ret) =>
            {
                if (AuthResult.AUTHRET_SUCCESS == ret)
                {
                    Task.Run(() => JoinRoom(meetingId));
                }
                else//error handle.todo
                {

                }
            });
            AuthParam param = new ZOOM_SDK_DOTNET_WRAP.AuthParam {
                appKey = zoomKey,
                appSecret = zoomSecret
            };
            var res = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().SDKAuth(param);
        }

        private void JoinRoom(string meetingId)
        {
            RegisterCallBack();
            ZOOM_SDK_DOTNET_WRAP.JoinParam param = new ZOOM_SDK_DOTNET_WRAP.JoinParam();
            param.userType = ZOOM_SDK_DOTNET_WRAP.SDKUserType.SDK_UT_WITHOUT_LOGIN;
            ZOOM_SDK_DOTNET_WRAP.JoinParam4WithoutLogin join_api_param = new ZOOM_SDK_DOTNET_WRAP.JoinParam4WithoutLogin();
            join_api_param.meetingNumber = UInt64.Parse(meetingId);
            join_api_param.userName = "Rev.ai Zoom SDK";
            param.withoutloginJoin = join_api_param;

            // Settings to disable video and audio on join and minimize screen
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetSettingServiceWrap()
                .GetVideoSettings().EnableAutoTurnOffVideoWhenJoinMeeting(true);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetSettingServiceWrap()
                .GetAudioSettings().EnableAutoJoinAudio(true);
            ZOOM_SDK_DOTNET_WRAP.SDKError err = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Join(param);

            if (ZOOM_SDK_DOTNET_WRAP.SDKError.SDKERR_SUCCESS == err)
            {
                _receiver = new RevAudioReceiver();
                var res = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAudioRawDataChannelWrap().Start(RawDataMemoryMode.RawDataMemoryMode_Stack, _receiver);
                Console.WriteLine($"Raw data channel start with {res}");
                //CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingAudioController()
                //    .Add_CB_onUserActiveAudioChange((list) =>
                //    {
                //        if (list == null || list.Length == 0)
                //        {
                //            return;
                //        }
                //        var users = list.Select(userId => CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingParticipantsController().GetUserByUserID(userId));

                //        var usernames = users.Select(u => u.GetUserNameW());
                //        Console.WriteLine($"Active speakers: {string.Join(" ", usernames)}");
                //    });
            }
            else//error handle
            { }
        }

        //ZOOM_SDK_DOTNET_WRAP.onMeetingStatusChanged
        private void onMeetingStatusChanged(MeetingStatus status, int iResult)
        {
            switch (status)
            {
                case ZOOM_SDK_DOTNET_WRAP.MeetingStatus.MEETING_STATUS_ENDED:
                case ZOOM_SDK_DOTNET_WRAP.MeetingStatus.MEETING_STATUS_FAILED:
                    {
                        if (_receiver != null)
                            _receiver.Finish();
                        System.Windows.Application.Current.Shutdown();
                    }
                    break;
                default://todo
                    break;
            }
        }

        private void onUserJoin(Array lstUserID)
        {
            if (lstUserID is null)
                return;

            for (int i = lstUserID.GetLowerBound(0); i <= lstUserID.GetUpperBound(0); i++)
            {
                UInt32 userid = (UInt32)lstUserID.GetValue(i);
                ZOOM_SDK_DOTNET_WRAP.IUserInfoDotNetWrap user = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                    GetMeetingParticipantsController().GetUserByUserID(userid);
                if (user is object)
                {
                    string name = user.GetUserNameW();
                    Console.Write(name);
                }
            }
        }

        public void onUserLeft(Array lstUserID)
        {
            //todo
        }
        public void onHostChangeNotification(UInt32 userId)
        {
            //todo
        }
        public void onLowOrRaiseHandStatusChanged(bool bLow, UInt32 userid)
        {
            //todo
        }
        public void onUserNameChanged(UInt32 userId, string userName)
        {
            //todo
        }

        private void RegisterCallBack()
        {
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Add_CB_onMeetingStatusChanged(onMeetingStatusChanged);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                GetMeetingParticipantsController().Add_CB_onHostChangeNotification(onHostChangeNotification);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                GetMeetingParticipantsController().Add_CB_onLowOrRaiseHandStatusChanged(onLowOrRaiseHandStatusChanged);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                GetMeetingParticipantsController().Add_CB_onUserJoin(onUserJoin);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                GetMeetingParticipantsController().Add_CB_onUserLeft(onUserLeft);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                GetMeetingParticipantsController().Add_CB_onUserNameChanged(onUserNameChanged);
        }

        private RevAudioReceiver _receiver;

        void Wnd_Closing(object sender, CancelEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
    }
}
