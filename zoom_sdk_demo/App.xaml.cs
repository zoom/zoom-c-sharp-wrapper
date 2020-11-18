using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
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
            {
                ZOOM_SDK_DOTNET_WRAP.InitParam param = new ZOOM_SDK_DOTNET_WRAP.InitParam();
                param.web_domain = "https://zoom.us";
                ZOOM_SDK_DOTNET_WRAP.SDKError err = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.Initialize(param);
                if (ZOOM_SDK_DOTNET_WRAP.SDKError.SDKERR_SUCCESS == err)
                {

                }
                else//error handle.todo
                {

                }
            }
        }
        private void Application_Exit(object sender, ExitEventArgs e)
        {
            //clean up sdk
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.CleanUp();
        }
    }
}
