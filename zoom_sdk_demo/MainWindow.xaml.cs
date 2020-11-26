using System.ComponentModel; // CancelEventArgs
using System.Windows;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        start_join_meeting start_meeting_wnd = new start_join_meeting();
        public MainWindow()
        {
            InitializeComponent();
            //register callback
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().Add_CB_onAuthenticationReturn(onAuthenticationReturn);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().Add_CB_onLoginRet(onLoginRet);
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().Add_CB_onLogout(onLogout);
            //
            ZOOM_SDK_DOTNET_WRAP.AuthParam param = new ZOOM_SDK_DOTNET_WRAP.AuthParam();
            param.appKey = "MfgQItI2gIPgSkBrjbVHmH9hDL1Ct2CHrVDT"; //textBox_key.Text;
            param.appSecret = "XeUOrpLUoKDsHr4WJWJj02pohMPBAODIgPML"; // textBox_secret.Text;
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().SDKAuth(param);

            ZOOM_SDK_DOTNET_WRAP.AuthParam authParam = new ZOOM_SDK_DOTNET_WRAP.AuthParam();
            authParam.appKey = "MfgQItI2gIPgSkBrjbVHmH9hDL1Ct2CHrVDT"; //textBox_key.Text;
            authParam.appSecret = "XeUOrpLUoKDsHr4WJWJj02pohMPBAODIgPML"; // textBox_secret.Text;
            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().SDKAuth(authParam);
            Hide();
        }

        //callback
        public void onAuthenticationReturn(AuthResult ret)
        {
            if (ZOOM_SDK_DOTNET_WRAP.AuthResult.AUTHRET_SUCCESS == ret)
            {
                start_meeting_wnd.Show();
            }
            else//error handle.todo
            {
                Show();
            }
        }
        public void onLoginRet(LOGINSTATUS ret, IAccountInfo pAccountInfo)
        {
            //todo
        }
        public void onLogout()
        {
            //todo
        }
        private void button_auth_Click(object sender, RoutedEventArgs e)
        {
            
        }

        void Wnd_Closing(object sender, CancelEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
    }
}
