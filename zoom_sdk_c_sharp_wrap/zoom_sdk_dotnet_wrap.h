// zoom_sdk_c_sharp_wrap.h

#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "auth_service_dotnet_wrap.h"
#include "meeting_service_dotnet_wrap.h"
#include "setting_service_dotnet_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {
	public ref class CZoomSDKeDotNetWrap sealed
	{
		// TODO: Add your methods for this class here.
	public:
		static property CZoomSDKeDotNetWrap^ Instance
		{
			CZoomSDKeDotNetWrap^ get() { return m_Instance; }
		}

		SDKError Initialize(InitParam initInfo);
		SDKError CleanUp();
		IAuthServiceDotNetWrap^ GetAuthServiceWrap();
		IMeetingServiceDotNetWrap^ GetMeetingServiceWrap();
		ISettingServiceDotNetWrap^ GetSettingServiceWrap();

	private:
		static CZoomSDKeDotNetWrap^ m_Instance = gcnew CZoomSDKeDotNetWrap;
	};
}
