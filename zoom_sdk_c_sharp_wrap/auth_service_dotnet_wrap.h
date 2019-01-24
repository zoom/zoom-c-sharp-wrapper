#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public enum class AuthResult : int
	{
		AUTHRET_SUCCESS,///< Auth Success 
		AUTHRET_KEYORSECRETEMPTY,///< Key or Secret is empty
		AUTHRET_KEYORSECRETWRONG,///< Key or Secret is wrong
		AUTHRET_ACCOUNTNOTSUPPORT,///< Client Account does not support
		AUTHRET_ACCOUNTNOTENABLESDK,///< Client account does not enable SDK
		AUTHRET_UNKNOWN,///< Auth Unknown error
		AUTHRET_SERVICE_BUSY,///< service busy
		AUTHRET_NONE,///< Initial status
	};

	public enum class LOGINSTATUS : int
	{
		LOGIN_IDLE,///< Not login
		LOGIN_PROCESSING,///< Login in processing
		LOGIN_SUCCESS,///< Login success
		LOGIN_FAILED,///< Login failed
	};

	public enum class LoginType : int
	{
		LoginType_Unknown,
		LoginType_Email,///<Login with work email
		LoginType_SSO,///<Login with SSO token
	};

	public interface class IAccountInfo
	{
	public:
		String^ GetDisplayName();
		LoginType GetLoginType();
	};

	public value class AuthParam sealed
	{
	public:
		String^ appKey;///< APP Key string
		String^ appSecret;///< APP Secret string
	};

	public value class LoginParam4Email sealed
	{
	public:
		String^ userName;///< Account name. email or something else
		String^ password;///< Account password
		bool bRememberMe;
	};

	public value class LoginParam4SSO sealed
	{
	public:
		String^ ssoToken;///< Account SSO token when Login
	};

	public value class LoginParam sealed
	{
	public:
		LoginType loginType;
		LoginParam4Email^ emailLogin;
		LoginParam4SSO^ ssoLogin;
	};

	public delegate void onAuthenticationReturn(AuthResult ret);
	public delegate void onLoginRet(LOGINSTATUS ret, IAccountInfo^ pAccountInfo);
	public delegate void onLogout();
	public delegate void onZoomIdentityExpired();

	public interface class IAuthServiceDotNetWrap
	{
	public:
		SDKError SDKAuth(AuthParam authParam);
		AuthResult GetAuthResult();
		String^ GetSDKIdentity();
		SDKError Login(LoginParam param);
		SDKError LogOut();
		IAccountInfo^ GetAccountInfo();
		LOGINSTATUS GetLoginStatus();
		void Add_CB_onAuthenticationReturn(onAuthenticationReturn^ cb);
		void Add_CB_onLoginRet(onLoginRet^ cb);
		void Add_CB_onLogout(onLogout^ cb);
	};
	private ref class CAuthServiceDotNetWrap sealed: public IAuthServiceDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
 		static property CAuthServiceDotNetWrap^ Instance
 		{
 			CAuthServiceDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError SDKAuth(AuthParam authParam);
		virtual AuthResult GetAuthResult();
		virtual String^ GetSDKIdentity();
		virtual SDKError Login(LoginParam param);
		virtual SDKError LogOut();
		virtual IAccountInfo^ GetAccountInfo();
		virtual LOGINSTATUS GetLoginStatus();
		virtual void Add_CB_onAuthenticationReturn(onAuthenticationReturn^ cb)
		{
			event_onAuthenticationReturn += cb;
		}
		virtual void Add_CB_onLoginRet(onLoginRet^ cb)
		{
			event_onLoginRet += cb;
		}

		virtual void Add_CB_onLogout(onLogout^ cb)
		{
			event_onLogout += cb;
		}

		virtual void Add_CB_onZoomIdentityExpired(onZoomIdentityExpired^ cb)
		{
			event_onZoomIdentityExpired += cb;
		}
		//
		void ProcAuthenticationReturn(AuthResult ret);
		void ProcLoginRet(LOGINSTATUS ret, IAccountInfo^ pAccountInfo);
		void ProcLogout();
		void ProcZoomIdentityExpired();

		void BindEvent();
	private:
		CAuthServiceDotNetWrap();
		virtual ~CAuthServiceDotNetWrap();
		event onAuthenticationReturn^ event_onAuthenticationReturn;
		event onLoginRet^ event_onLoginRet;
		event onLogout^ event_onLogout;
		event onZoomIdentityExpired^ event_onZoomIdentityExpired;
		static CAuthServiceDotNetWrap^ m_Instance = gcnew CAuthServiceDotNetWrap;
	};
}
