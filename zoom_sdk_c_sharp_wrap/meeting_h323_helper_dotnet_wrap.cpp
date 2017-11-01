#include "stdafx.h"
#include "meeting_h323_helper_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//Translate event
	class MeetingH323HelperEventHanlder
	{
	public:
		static MeetingH323HelperEventHanlder& GetInst()
		{
			static MeetingH323HelperEventHanlder inst;
			return inst;
		}
		void onCalloutStatusNotify(ZOOM_SDK_NAMESPACE::H323CalloutStatus status)
		{
			if (CMeetingH323HelperDotNetWrap::Instance)
				CMeetingH323HelperDotNetWrap::Instance->procCalloutStatusNotify((H323CalloutStatus)status);
		}

		void onParingH323Result(ZOOM_SDK_NAMESPACE::H323ParingResult result)
		{
			if (CMeetingH323HelperDotNetWrap::Instance)
				CMeetingH323HelperDotNetWrap::Instance->procParingH323Result((H323ParingResult)result);
		}

	private:
		MeetingH323HelperEventHanlder() {}
	};
	//
	void CMeetingH323HelperDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingH323HelperWrap& meetingH323 = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetH323Helper();
		meetingH323.m_cbonCalloutStatusNotify =
			std::bind(&MeetingH323HelperEventHanlder::onCalloutStatusNotify,
				&MeetingH323HelperEventHanlder::GetInst(), std::placeholders::_1);

		meetingH323.m_cbonParingH323Result =
			std::bind(&MeetingH323HelperEventHanlder::onParingH323Result,
				&MeetingH323HelperEventHanlder::GetInst(), std::placeholders::_1);
	}

	void CMeetingH323HelperDotNetWrap::procCalloutStatusNotify(H323CalloutStatus status)
	{
		event_onCalloutStatusNotify(status);
	}
	void CMeetingH323HelperDotNetWrap::procParingH323Result(H323ParingResult result)
	{
		event_onParingH323Result(result);
	}

	array<String^ >^ CMeetingH323HelperDotNetWrap::GetH323Address()
	{
		ZOOM_SDK_NAMESPACE::IList<const wchar_t* >* lstH323 = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetH323Helper().GetH323Address();

		return Convert(lstH323);
	}

	String^ CMeetingH323HelperDotNetWrap::GetH323Password()
	{
		return WChar2PlatformString(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetH323Helper().GetH323Password());
	}

	SDKError CMeetingH323HelperDotNetWrap::SendMeetingParingCode(unsigned __int64 meetingNum, String^ paringCode)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetH323Helper().
			SendMeetingParingCode(meetingNum, const_cast<wchar_t*>(PlatformString2WChar(paringCode)));
	}

	SDKError CMeetingH323HelperDotNetWrap::CallOutH323(H323Device deviceInfo)
	{
		ZOOM_SDK_NAMESPACE::H323Device deviceInfo_c;
		deviceInfo_c.e164num = const_cast<wchar_t*>(PlatformString2WChar(deviceInfo.e164num));
		deviceInfo_c.ip = const_cast<wchar_t*>(PlatformString2WChar(deviceInfo.ip));
		deviceInfo_c.name = const_cast<wchar_t*>(PlatformString2WChar(deviceInfo.name));
		deviceInfo_c.type = (ZOOM_SDK_NAMESPACE::H323DeviceType)deviceInfo.type;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetH323Helper().CallOutH323(deviceInfo_c);
	}

	SDKError CMeetingH323HelperDotNetWrap::CancelCallOutH323()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetH323Helper().CancelCallOutH323();
	}
}