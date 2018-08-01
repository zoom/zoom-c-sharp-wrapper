using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.ComponentModel; // CancelEventArgs
using ZOOM_SDK_DOTNET_WRAP;

namespace zoom_sdk_demo
{
    /// <summary>
    /// Interaction logic for start_join_meeting.xaml
    /// </summary>
    public partial class start_join_meeting : Window
    {
        public start_join_meeting()
        {
            InitializeComponent();
        }

        //ZOOM_SDK_DOTNET_WRAP.onMeetingStatusChanged
        public void onMeetingStatusChanged(MeetingStatus status, int iResult)
        {
            switch(status)
            {
                case ZOOM_SDK_DOTNET_WRAP.MeetingStatus.MEETING_STATUS_ENDED:
                case ZOOM_SDK_DOTNET_WRAP.MeetingStatus.MEETING_STATUS_FAILED:
                    {
                        Show();
                    }
                    break;
                default://todo
                    break;
            }
        }

        public void onUserJoin(Array lstUserID)
        {
            if (null == (Object)lstUserID)
                return;

            for (int i = lstUserID.GetLowerBound(0); i <= lstUserID.GetUpperBound(0); i++)
            {
                UInt32 userid = (UInt32)lstUserID.GetValue(i);
                ZOOM_SDK_DOTNET_WRAP.IUserInfoDotNetWrap user = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().
                    GetMeetingParticipantsController().GetUserByUserID(userid);
                if (null != (Object)user)
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
        private void button_start_api_Click(object sender, RoutedEventArgs e)
        {
            RegisterCallBack();
            ZOOM_SDK_DOTNET_WRAP.StartParam param = new ZOOM_SDK_DOTNET_WRAP.StartParam();
            param.userType = ZOOM_SDK_DOTNET_WRAP.SDKUserType.SDK_UT_WITHOUT_LOGIN;
            ZOOM_SDK_DOTNET_WRAP.StartParam4WithoutLogin start_withoutlogin_param = new ZOOM_SDK_DOTNET_WRAP.StartParam4WithoutLogin();
            start_withoutlogin_param.meetingNumber = UInt64.Parse(textBox_meetingnumber_api.Text);
            start_withoutlogin_param.userID = textBox_userid_api.Text;
            start_withoutlogin_param.userToken = textBox_username_api.Text;
            start_withoutlogin_param.userZAK = textBox_AccessToken.Text;
            start_withoutlogin_param.userName = textBox_username_api.Text;
            start_withoutlogin_param.zoomuserType = ZOOM_SDK_DOTNET_WRAP.ZoomUserType.ZoomUserType_APIUSER;
            param.withoutloginStart = start_withoutlogin_param;

            ZOOM_SDK_DOTNET_WRAP.SDKError err = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Start(param);
            if (ZOOM_SDK_DOTNET_WRAP.SDKError.SDKERR_SUCCESS == err)
            {
                Hide();
            }
            else//error handle
            { }

        }

        private void button_join_api_Click(object sender, RoutedEventArgs e)
        {
            RegisterCallBack();
            ZOOM_SDK_DOTNET_WRAP.JoinParam param = new ZOOM_SDK_DOTNET_WRAP.JoinParam();
            param.userType = ZOOM_SDK_DOTNET_WRAP.SDKUserType.SDK_UT_APIUSER;
            ZOOM_SDK_DOTNET_WRAP.JoinParam4APIUser join_api_param = new ZOOM_SDK_DOTNET_WRAP.JoinParam4APIUser();
            join_api_param.meetingNumber = UInt64.Parse(textBox_meetingnumber_api.Text);
            join_api_param.userName = textBox_username_api.Text;
            param.apiuserJoin = join_api_param;

            ZOOM_SDK_DOTNET_WRAP.SDKError err = ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Join(param);
            if (ZOOM_SDK_DOTNET_WRAP.SDKError.SDKERR_SUCCESS == err)
            {
                Hide();
            }
            else//error handle
            { }
        }

        void Wnd_Closing(object sender, CancelEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
    }
}
