using System;
using System.Linq;
using System.Windows;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private void Application_Startup(object sender, StartupEventArgs e)
        {
            //init sdk
            InitParam param = new InitParam {
                web_domain = "https://zoom.us",
                enable_log = true
            };
            SDKError err = CZoomSDKeDotNetWrap.Instance.Initialize(param);
            if (SDKError.SDKERR_SUCCESS == err)
            {             
            }
            else//error handle.todo
            {
                Console.WriteLine(err);
            }   
        }
        private void Application_Exit(object sender, ExitEventArgs e)
        {
            //clean up sdk
            CZoomSDKeDotNetWrap.Instance.CleanUp();
        }
    }
}
