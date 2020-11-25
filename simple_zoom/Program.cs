using System;
using System.Threading.Tasks;

namespace simple_zoom
{
    class Program
    {
        static async Task Main(string[] args)
        {
            _ = BackgroundAsync();

            Console.ReadLine();
        }

        private static async Task BackgroundAsync()
        {
            await Task.Yield();
            ZOOM_SDK_DOTNET_WRAP.InitParam param = new ZOOM_SDK_DOTNET_WRAP.InitParam {
                web_domain = "https://zoom.us"
            };
            ZOOM_SDK_DOTNET_WRAP.SDKError err = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.Initialize(param);


            ZOOM_SDK_DOTNET_WRAP.AuthParam authParam = new ZOOM_SDK_DOTNET_WRAP.AuthParam {
                appKey = "MfgQItI2gIPgSkBrjbVHmH9hDL1Ct2CHrVDT", //textBox_key.Text;
                appSecret = "XeUOrpLUoKDsHr4WJWJj02pohMPBAODIgPML" // textBox_secret.Text;
            };
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().SDKAuth(authParam);

            ZOOM_SDK_DOTNET_WRAP.JoinParam joinParam = new ZOOM_SDK_DOTNET_WRAP.JoinParam {
                userType = ZOOM_SDK_DOTNET_WRAP.SDKUserType.SDK_UT_WITHOUT_LOGIN
            };
            ZOOM_SDK_DOTNET_WRAP.JoinParam4WithoutLogin join_api_param = new ZOOM_SDK_DOTNET_WRAP.JoinParam4WithoutLogin();
            join_api_param.meetingNumber = UInt64.Parse("94091188136");
            join_api_param.userName = "Test User";
            joinParam.withoutloginJoin = join_api_param;

            ZOOM_SDK_DOTNET_WRAP.SDKError joinErr = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Join(joinParam);
            if (ZOOM_SDK_DOTNET_WRAP.SDKError.SDKERR_SUCCESS == err)
            {
                //var audioDelegate = new AudioDelegate();
                //CZoomSDKeDotNetWrap.Instance.GetRawAudioHelper().subscribe(audioDelegate);
                //_ = audioDelegate.StartStreamingAsync();
            }
        }
    }
}
