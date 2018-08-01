#include "stdafx.h"
#include "auth_service_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	//translate account info
	private ref class IAccountInfoImpl sealed : public IAccountInfo
	{
	public:
		IAccountInfoImpl()
		{
			m_pCPlusObject = NULL;
		}

		IAccountInfoImpl(ZOOM_SDK_NAMESPACE::IAccountInfo* pInfo)
		{
			m_pCPlusObject = pInfo;
		}

		virtual String^ GetDisplayName()
		{
			if (m_pCPlusObject)
				return WChar2PlatformString(m_pCPlusObject->GetDisplayName());

			return nullptr;
		}

		virtual LoginType GetLoginType()
		{
			if (m_pCPlusObject)
				return (LoginType)m_pCPlusObject->GetLoginType();

			return LoginType::LoginType_Unknown;
		}
	private:
		ZOOM_SDK_NAMESPACE::IAccountInfo* m_pCPlusObject;
	};

	IAccountInfo^ TranslateAccountInfo(ZOOM_SDK_NAMESPACE::IAccountInfo* pInfo)
	{
		//to do
		if (pInfo)
		{
			return gcnew IAccountInfoImpl(pInfo);
		}
		return nullptr;
	}
	//

	//Translate event
	class AuthEventHanlder
	{
	public:
		static AuthEventHanlder& GetInst()
		{
			static AuthEventHanlder inst;
			return inst;
		}

		void onAuthenticationReturn(ZOOM_SDK_NAMESPACE::AuthResult ret)
		{
			if (ZOOM_SDK_NAMESPACE::AUTHRET_SUCCESS == ret)
			{
				ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& meetingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
				meetingWrap.Init();

				ZOOM_SDK_NAMESPACE::IMeetingConfigurationWrap& config = meetingWrap.GetMeetingConfiguration();
				config.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingUIControllerWrap& uiCtrl = meetingWrap.GetUIController();
				uiCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IAnnotationControllerWrap& annoCtrl = meetingWrap.GetAnnotationController();
				annoCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingVideoControllerWrap& videoCtrl = meetingWrap.GetMeetingVideoController();
				videoCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingRemoteControllerWrap& remoteCtrl = meetingWrap.GetMeetingRemoteController();
				remoteCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingShareControllerWrap& shareCtrl = meetingWrap.GetMeetingShareController();
				shareCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingAudioControllerWrap& autioCtrl = meetingWrap.GetMeetingAudioController();
				autioCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingRecordingControllerWrap& recCtrl = meetingWrap.GetMeetingRecordingController();
				recCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingChatControllerWrap& chatCtrl = meetingWrap.GetMeetingChatController();
				chatCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingWaitingRoomControllerWrap& waitingroomCtrl = meetingWrap.GetMeetingWaitingRoomController();
				waitingroomCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingH323HelperWrap& h323Ctrl = meetingWrap.GetH323Helper();
				h323Ctrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingPhoneHelperWrap& phoneCtrl = meetingWrap.GetMeetingPhoneHelper();
				phoneCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingBreakoutRoomsControllerWrap& breakoutRoomsCtrl = meetingWrap.GetMeetingBreakoutRoomsController();
				breakoutRoomsCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingParticipantsControllerWrap& participantsCtrl = meetingWrap.GetMeetingParticipantsController();
				participantsCtrl.Init(&meetingWrap);
			}
	
			//post msg

			CAuthServiceDotNetWrap::Instance->ProcAuthenticationReturn((AuthResult)ret);
		}

		void onLoginRet(ZOOM_SDK_NAMESPACE::LOGINSTATUS ret, ZOOM_SDK_NAMESPACE::IAccountInfo* pAccountInfo)
		{
			//post msg
			CAuthServiceDotNetWrap::Instance->ProcLoginRet((LOGINSTATUS)ret, TranslateAccountInfo(pAccountInfo));
		}

		void onLogout()
		{
			//post msg
			CAuthServiceDotNetWrap::Instance->ProcLogout();
		}

		void onZoomIdentityExpired()
		{
			CAuthServiceDotNetWrap::Instance->ProcZoomIdentityExpired();
		}
	private:
		AuthEventHanlder() {}
	};

	
	//
	CAuthServiceDotNetWrap::CAuthServiceDotNetWrap()
	{
	}

	CAuthServiceDotNetWrap::~CAuthServiceDotNetWrap()
	{
	}

	SDKError CAuthServiceDotNetWrap::SDKAuth(AuthParam authParam)
	{
		ZOOM_SDK_NAMESPACE::AuthParam param_;
		param_.appKey = PlatformString2WChar(authParam.appKey);
		param_.appSecret = PlatformString2WChar(authParam.appSecret);

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SDKAuth(param_);
	}

	AuthResult CAuthServiceDotNetWrap::GetAuthResult()
	{
		return (AuthResult)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetAuthResult();
	}

	String^ CAuthServiceDotNetWrap::GetSDKIdentity()
	{
		return WChar2PlatformString(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetSDKIdentity());
	}
	SDKError CAuthServiceDotNetWrap::Login(LoginParam param)
	{
		//to do
		ZOOM_SDK_NAMESPACE::LoginParam param_c;
		param_c.loginType = (ZOOM_SDK_NAMESPACE::LoginType)param.loginType;
		switch (param.loginType)
		{
		case LoginType::LoginType_Email:
		{
			if (nullptr == param.emailLogin)
				return SDKError::SDKERR_INVALID_PARAMETER;
			param_c.ut.emailLogin.bRememberMe = param.emailLogin->bRememberMe;
			param_c.ut.emailLogin.password = PlatformString2WChar(param.emailLogin->password);
			param_c.ut.emailLogin.userName = PlatformString2WChar(param.emailLogin->userName);
		}
		break;
		case LoginType::LoginType_SSO:
		{
			if (nullptr == param.ssoLogin)
				return SDKError::SDKERR_INVALID_PARAMETER;
			param_c.ut.ssoLogin.ssoToken = PlatformString2WChar(param.ssoLogin->ssoToken);
		}
		break;
		default:
			break;
		}

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Login(param_c);
	}
	SDKError CAuthServiceDotNetWrap::LogOut()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().LogOut();
	}

	IAccountInfo^ CAuthServiceDotNetWrap::GetAccountInfo()
	{
		return TranslateAccountInfo(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetAccountInfo());
	}

	LOGINSTATUS CAuthServiceDotNetWrap::GetLoginStatus()
	{
		return (LOGINSTATUS)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetLoginStatus();
	}

	////handle event
	void CAuthServiceDotNetWrap::ProcAuthenticationReturn(AuthResult ret)
	{
		event_onAuthenticationReturn(ret);
	}

	void CAuthServiceDotNetWrap::ProcLoginRet(LOGINSTATUS ret, IAccountInfo^ pAccountInfo)
	{
		event_onLoginRet(ret, pAccountInfo);
	}

	void CAuthServiceDotNetWrap::ProcLogout()
	{
		event_onLogout();
	}

	void CAuthServiceDotNetWrap::ProcZoomIdentityExpired()
	{
		event_onZoomIdentityExpired();
	}

	void CAuthServiceDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonAuthenticationReturn =
			std::bind(&AuthEventHanlder::onAuthenticationReturn, &AuthEventHanlder::GetInst(), std::placeholders::_1);
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonLoginRet = 
			std::bind(&AuthEventHanlder::onLoginRet, &AuthEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonLogout =
			std::bind(&AuthEventHanlder::onLogout, &AuthEventHanlder::GetInst());
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonZoomIdentityExpired =
			std::bind(&AuthEventHanlder::onZoomIdentityExpired, &AuthEventHanlder::GetInst());
	}
}