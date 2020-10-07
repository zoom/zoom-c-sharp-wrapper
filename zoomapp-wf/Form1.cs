using System;
using System.Linq;
using System.Windows.Forms;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoomapp_wf
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void StartZoom(
            string zoomKey,
            string zoomSecret,
            string meetingId
            )
        {

            InitializeComponent();
            InitParam param = new InitParam {
                web_domain = "https://zoom.us",
                enable_log = true
            };
            SDKError err = CZoomSDKeDotNetWrap.Instance.Initialize(param);
            if (SDKError.SDKERR_SUCCESS == err)
            {
                Console.WriteLine("initalize success");
                CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().Add_CB_onAuthenticationReturn((ret) =>
                {
                    if (AuthResult.AUTHRET_SUCCESS == ret)
                    {
                        Console.WriteLine($"Auth returned {ret}");
                        JoinRoom(meetingId);
                    }
                    else//error handle.todo
                    {
                    }
                });
                AuthParam authParam = new ZOOM_SDK_DOTNET_WRAP.AuthParam {
                    appKey = zoomKey,
                    appSecret = zoomSecret
                };
                CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().SDKAuth(authParam);
            }
            else//error handle.todo
            {

            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            var args = Environment.GetCommandLineArgs();
            var zoomKey = args[1];
            var zoomSecret = args[2];
            var meetingId = args[3];
            StartZoom(zoomKey, zoomSecret, meetingId);
        }

        private void JoinRoom(string meetingId)
        {
            CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Add_CB_onMeetingStatusChanged((status, iResult) => {
                switch (status)
                {
                    case ZOOM_SDK_DOTNET_WRAP.MeetingStatus.MEETING_STATUS_ENDED:
                    case ZOOM_SDK_DOTNET_WRAP.MeetingStatus.MEETING_STATUS_FAILED:
                        {
                            Console.WriteLine("Closing application");
                            Application.Exit();
                        }
                        break;
                    default://todo
                        break;
                }
            });

            JoinParam param = new JoinParam {
                userType = SDKUserType.SDK_UT_WITHOUT_LOGIN
            };
            JoinParam4WithoutLogin join_api_param = new ZOOM_SDK_DOTNET_WRAP.JoinParam4WithoutLogin {
                meetingNumber = ulong.Parse(meetingId),
                userName = "Rev.ai SDK Demo"
            };
            param.withoutloginJoin = join_api_param;

            // Settings to disable video and audio on join and minimize screen
            CZoomSDKeDotNetWrap.Instance.GetSettingServiceWrap()
                .GetVideoSettings().EnableAutoTurnOffVideoWhenJoinMeeting(true);
            CZoomSDKeDotNetWrap.Instance.GetSettingServiceWrap()
                .GetAudioSettings().EnableAutoJoinAudio(true);
            SDKError err = CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Join(param);

            if (SDKError.SDKERR_SUCCESS == err)
            {
                Hide();
                var res = CZoomSDKeDotNetWrap.Instance.GetAudioRawDataChannelWrap().Start(RawDataMemoryMode.RawDataMemoryMode_Stack, new RevAudioReceiver());
                Console.WriteLine($"Raw data channel start with {res}");
                CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingAudioController()
                    .Add_CB_onUserActiveAudioChange((list) =>
                    {
                        if (list == null || list.Length == 0)
                        {
                            return;
                        }
                        var users = list.Select(userId => CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingParticipantsController().GetUserByUserID(userId));

                        var usernames = users.Select(u => u.GetUserNameW());
                        Console.WriteLine($"Active speakers: {string.Join(" ", usernames)}");
                    });
            }
            else//error handle
            { }
        }
    }
}
