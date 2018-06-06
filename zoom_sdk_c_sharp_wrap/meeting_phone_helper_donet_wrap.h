#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class CALLINNUMTYPE : int
	{
		CALLINNUMTYPE_NONE,
		CALLINNUMTYPE_TOLL,
		CALLINNUMTYPE_TOLLFREE,
	};

	public enum class PhoneStatus : int
	{
		PhoneStatus_None,
		PhoneStatus_Calling,
		PhoneStatus_Ringing,
		PhoneStatus_Accepted,
		PhoneStatus_Success,
		PhoneStatus_Failed,
		PhoneStatus_Canceling,
		PhoneStatus_Canceled,
		PhoneStatus_Cancel_Failed,
		PhoneStatus_Timeout,
	};

	public enum class PhoneFailedReason : int
	{
		PhoneFailedReason_None,
		PhoneFailedReason_Busy,
		PhoneFailedReason_Not_Available,
		PhoneFailedReason_User_Hangup,
		PhoneFailedReason_Other_Fail,
		PhoneFailedReason_No_Answer,
		PhoneFailedReason_Block_No_Host,
		PhoneFailedReason_Block_High_Rate,
		PhoneFailedReason_Block_Too_Frequent,
	};

	public interface class IMeetingPhoneSupportCountryInfoDotNetWrap
	{
	public:
		String^ GetCountryID();
		String^ GetCountryName();
		String^ GetCountryCode();
	};

	public interface class IMeetingCallInPhoneNumberInfoDotNetWrap
	{
	public:
		String^ GetID();
		String^ GetCode();
		String^ GetName();
		String^ GetNumber();
		String^ GetDisplayNumber();
		CALLINNUMTYPE  GetType();
	};

	public delegate void onInviteCallOutUserStatus(PhoneStatus status, PhoneFailedReason reason);
	public delegate void onCallMeStatus(PhoneStatus status, PhoneFailedReason reason);

	public interface class IMeetingPhoneHelperDotNetWrap
	{
	public:
		bool IsSupportPhoneFeature();
		array<IMeetingPhoneSupportCountryInfoDotNetWrap^ >^ GetSupportCountryInfo();
		SDKError InviteCallOutUser(String^ countryCode, String^ phoneNumber, String^ name);
		SDKError CancelCallOut();
		PhoneStatus GetInviteCalloutUserStatus();
		SDKError CallMe(String^ countryCode, String^ phoneNumber);
		SDKError Hangup();
		PhoneStatus GetCallMeStatus();
		array<IMeetingCallInPhoneNumberInfoDotNetWrap^ >^ GetCurrentMeetingCallinNumber();
		unsigned int GetCurrentMeetingCallinParticipantID();

		void Add_CB_onInviteCallOutUserStatus(onInviteCallOutUserStatus^ cb);
		void Add_CB_onCallMeStatus(onCallMeStatus^ cb);
	};

	private ref class CMeetingPhoneHelperDotNetWrap sealed : public IMeetingPhoneHelperDotNetWrap
	{
	public:
		static property CMeetingPhoneHelperDotNetWrap^ Instance
		{
			CMeetingPhoneHelperDotNetWrap^ get() { return m_Instance; }
		}

		virtual bool IsSupportPhoneFeature();
		virtual array<IMeetingPhoneSupportCountryInfoDotNetWrap^ >^ GetSupportCountryInfo();
		virtual SDKError InviteCallOutUser(String^ countryCode, String^ phoneNumber, String^ name);
		virtual SDKError CancelCallOut();
		virtual PhoneStatus GetInviteCalloutUserStatus();
		virtual SDKError CallMe(String^ countryCode, String^ phoneNumber);
		virtual SDKError Hangup();
		virtual PhoneStatus GetCallMeStatus();
		virtual array<IMeetingCallInPhoneNumberInfoDotNetWrap^ >^ GetCurrentMeetingCallinNumber();
		virtual unsigned int GetCurrentMeetingCallinParticipantID();

		virtual void Add_CB_onInviteCallOutUserStatus(onInviteCallOutUserStatus^ cb)
		{
			event_onInviteCallOutUserStatus += cb;
		}

		virtual void Add_CB_onCallMeStatus(onCallMeStatus^ cb)
		{
			event_onCallMeStatus += cb;
		}

		void BindEvent();
		void procInviteCallOutUserStatus(PhoneStatus status, PhoneFailedReason reason);
		void procCallMeStatus(PhoneStatus status, PhoneFailedReason reason);
	private:

		event onInviteCallOutUserStatus^ event_onInviteCallOutUserStatus;
		event onCallMeStatus^ event_onCallMeStatus;
		static CMeetingPhoneHelperDotNetWrap^ m_Instance = gcnew CMeetingPhoneHelperDotNetWrap;
	};
}