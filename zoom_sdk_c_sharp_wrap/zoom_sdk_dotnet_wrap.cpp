// This is the main DLL file.

#include "stdafx.h"
#include "zoom_sdk_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	void InitAllService()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Init();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Init();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().Init();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetCalenderServiceWrap().Init();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetNetworkConnectionHelperWrap().Init();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().Init();
	}

	void UninitAllService()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Uninit();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Uninit();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().Uninit();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetCalenderServiceWrap().Uninit();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetNetworkConnectionHelperWrap().Uninit();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().Uninit();
	}

	SDKError CZoomSDKeDotNetWrap::Initialize(InitParam initInfo)
	{
		const wchar_t* dll_path = PlatformString2WChar(initInfo.sdk_dll_path);
		
		ZOOM_SDK_NAMESPACE::InitParam param_;
		param_.strWebDomain = PlatformString2WChar(initInfo.web_domain);
		param_.strBrandingName = PlatformString2WChar(initInfo.brand_name);
		param_.strSupportUrl = PlatformString2WChar(initInfo.support_url);
		param_.hResInstance = initInfo.res_instance;
		param_.uiWindowIconSmallID = initInfo.window_small_icon_id;
		param_.uiWindowIconBigID = initInfo.window_big_icon_id;
		param_.emLanguageID = (ZOOM_SDK_NAMESPACE::SDK_LANGUAGE_ID)initInfo.language_id;
		PlatformString2CharHelper langinfo = PlatformString2CharHelper(initInfo.config_opts.customized_language.language_name);
		param_.obConfigOpts.customizedLang.langInfo = langinfo.c_str();
		PlatformString2CharHelper langname = PlatformString2CharHelper(initInfo.config_opts.customized_language.language_name);
		param_.obConfigOpts.customizedLang.langName = langname.c_str();
		param_.obConfigOpts.customizedLang.langType = (ZOOM_SDK_NAMESPACE::CustomizedLanguageType)initInfo.config_opts.customized_language.langType;

		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().InitSDK(dll_path, param_);

		InitAllService();

		return err;
	}

	SDKError CZoomSDKeDotNetWrap::CleanUp()
	{
		UninitAllService();
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().CleanUPSDK();
	}

	IAuthServiceDotNetWrap^ CZoomSDKeDotNetWrap::GetAuthServiceWrap()
 	{
		if (CAuthServiceDotNetWrap::Instance)
			CAuthServiceDotNetWrap::Instance->BindEvent();

		return CAuthServiceDotNetWrap::Instance;
 	}

	IMeetingServiceDotNetWrap^ CZoomSDKeDotNetWrap::GetMeetingServiceWrap()
	{
		if (CMeetingServiceDotNetWrap::Instance)
			CMeetingServiceDotNetWrap::Instance->BindEvent();

		return CMeetingServiceDotNetWrap::Instance;
	}

	ISettingServiceDotNetWrap^ CZoomSDKeDotNetWrap::GetSettingServiceWrap()
	{
		if (CSettingServiceDotNetWrap::Instance)
			CSettingServiceDotNetWrap::Instance->BindEvent();

		return CSettingServiceDotNetWrap::Instance;
	}
}