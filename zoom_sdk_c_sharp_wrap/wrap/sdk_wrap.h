#pragma once
#include "auth_service_wrap.h"
#include "meeting_service_wrap.h"
#include "calender_service_wrap.h"
#include "premeeting_service_wrap.h"
#include "setting_service_wrap.h"
#include "network_connection_handler_wrap.h"
#include "ui_hook_wrap.h"
#include "embedded_browser_wrap.h"

BEGIN_ZOOM_SDK_NAMESPACE
class CSDKWrap
{
public:
	static CSDKWrap& GetInst();
	SDKError InitSDK(const wchar_t* sdkpath, InitParam& initParam);
	SDKError CleanUPSDK();
	const wchar_t* GetVersion();
	INetworkConnectionHelperWrap& GetNetworkConnectionHelperWrap();
	IAuthServiceWrap& GetAuthServiceWrap();
	IMeetingServiceWrap& GetMeetingServiceWrap();
	ICalenderServiceWrap& GetCalenderServiceWrap();
	IPreMeetingServiceWrap& GetPreMeetingServiceWrap();
	ISettingServiceWrap& GetSettingServiceWrap();
private:
	CSDKWrap();
};

class CSDKExtWrap
{
public:
	static CSDKExtWrap& GetInst();
	IUIHookerWrap& GetUIHookerWrap();
	IEmbeddedBrowserWrap* CreateEmbeddedBrowserWrap(HWND hwnd);
	void DestroyEmbeddedBrowserWrap(IEmbeddedBrowserWrap* pObj);
private:
	CSDKExtWrap();
};
END_ZOOM_SDK_NAMESPACE