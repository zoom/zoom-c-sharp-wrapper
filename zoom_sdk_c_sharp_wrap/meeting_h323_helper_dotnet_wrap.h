#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public enum class H323CalloutStatus : int
	{
		H323Callout_Unknown,
		H323Callout_Success,
		H323Callout_Ring,
		H323Callout_Timeout,
		H323Callout_Failed,
	};

	public enum class H323ParingResult : int
	{
		H323Paring_Unknown,
		H323Paring_Success,
		H323Paring_Meeting_Not_Exist,
		H323Paring_Paringcode_Not_Exist,
		H323Paring_No_Privilege,
		H323Paring_Other_Error,
	};

	public enum class H323DeviceType : int
	{
		H323DeviceType_Unknown,
		H323DeviceType_H323,
		H323DeviceType_SIP,
	};

	public value class H323Device
	{
	public:
		String^ name;
		String^ ip;
		String^ e164num;
		H323DeviceType	type;
	};

	public delegate void onCalloutStatusNotify(H323CalloutStatus status);
	public delegate void onParingH323Result(H323ParingResult result);

	public interface class IMeetingH323HelperDotNetWrap
	{
	public:
		array<String^ >^ GetH323Address();
		String^ GetH323Password();
		SDKError SendMeetingParingCode(unsigned __int64 meetingNum, String^ paringCode);
		array<H323Device^ >^ GetCalloutH323DviceList();
		SDKError CallOutH323(H323Device deviceInfo);
		SDKError CancelCallOutH323();

		void Add_CB_onCalloutStatusNotify(onCalloutStatusNotify^ cb);
		void Add_CB_onParingH323Result(onParingH323Result^ cb);
	};

	private ref class CMeetingH323HelperDotNetWrap sealed : public IMeetingH323HelperDotNetWrap
	{
	public:
		static property CMeetingH323HelperDotNetWrap^ Instance
		{
			CMeetingH323HelperDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procCalloutStatusNotify(H323CalloutStatus status);
		void procParingH323Result(H323ParingResult result);

		virtual array<String^ >^ GetH323Address();
		virtual String^ GetH323Password();
		virtual SDKError SendMeetingParingCode(unsigned __int64 meetingNum, String^ paringCode);
		virtual array<H323Device^ >^ GetCalloutH323DviceList();
		virtual SDKError CallOutH323(H323Device deviceInfo);
		virtual SDKError CancelCallOutH323();
		virtual void Add_CB_onCalloutStatusNotify(onCalloutStatusNotify^ cb)
		{
			event_onCalloutStatusNotify += cb;
		}

		virtual void Add_CB_onParingH323Result(onParingH323Result^ cb)
		{
			event_onParingH323Result += cb;
		}
	private:
		event onCalloutStatusNotify^ event_onCalloutStatusNotify;
		event onParingH323Result^ event_onParingH323Result;
		static CMeetingH323HelperDotNetWrap^ m_Instance = gcnew CMeetingH323HelperDotNetWrap;
	};
}