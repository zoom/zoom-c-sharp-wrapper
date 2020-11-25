using System;

namespace zoom_dotnet
{
    class Program
    {
        static void Main(string[] args)
        {
            ZOOM_SDK_DOTNET_WRAP.InitParam param = new ZOOM_SDK_DOTNET_WRAP.InitParam();
            param.web_domain = "https://zoom.us";
            ZOOM_SDK_DOTNET_WRAP.SDKError err = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.Initialize(param);
        }
    }
}
