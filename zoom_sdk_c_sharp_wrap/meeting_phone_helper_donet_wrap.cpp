#include "stdafx.h"
#include "meeting_phone_helper_donet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate event
	class MeetingPhoneHelperEventHanlder
	{
	public:
		static MeetingPhoneHelperEventHanlder& GetInst()
		{
			static MeetingPhoneHelperEventHanlder inst;
			return inst;
		}

		void onInviteCallOutUserStatus(ZOOM_SDK_NAMESPACE::PhoneStatus status, ZOOM_SDK_NAMESPACE::PhoneFailedReason reason)
		{
			if (CMeetingPhoneHelperDotNetWrap::Instance)
				CMeetingPhoneHelperDotNetWrap::Instance->procInviteCallOutUserStatus((PhoneStatus)status, (PhoneFailedReason)reason);
		}

		void onCallMeStatus(ZOOM_SDK_NAMESPACE::PhoneStatus status, ZOOM_SDK_NAMESPACE::PhoneFailedReason reason)
		{
			if (CMeetingPhoneHelperDotNetWrap::Instance)
				CMeetingPhoneHelperDotNetWrap::Instance->procCallMeStatus((PhoneStatus)status, (PhoneFailedReason)reason);
		}

	private:
		MeetingPhoneHelperEventHanlder() {};
	};
	//

	//
	private ref class IMeetingPhoneSupportCountryInfoDotNetWrapImpl sealed : public IMeetingPhoneSupportCountryInfoDotNetWrap
	{
	public:
		IMeetingPhoneSupportCountryInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IMeetingPhoneSupportCountryInfo* pInfo)
		{
			m_pInfo = pInfo;
		}

		virtual String^ GetCountryID()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetCountryID());

			return nullptr;
		}

		virtual String^ GetCountryName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetCountryName());

			return nullptr;
		}

		virtual String^ GetCountryCode()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetCountryCode());

			return nullptr;
		}
	private:
		ZOOM_SDK_NAMESPACE::IMeetingPhoneSupportCountryInfo* m_pInfo;
	};


	private ref class IMeetingCallInPhoneNumberInfoDotNetWrapImpl sealed : public IMeetingCallInPhoneNumberInfoDotNetWrap
	{
	public:
		IMeetingCallInPhoneNumberInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IMeetingCallInPhoneNumberInfo* pInfo)
		{
			m_pInfo = pInfo;
		}
		virtual String^ GetID()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetID());

			return nullptr;
		}

		virtual String^ GetCode()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetCode());

			return nullptr;
		}

		virtual String^ GetName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetName());

			return nullptr;
		}

		virtual String^ GetNumber()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetNumber());

			return nullptr;
		}

		virtual String^ GetDisplayNumber()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDisplayNumber());

			return nullptr;
		}

		virtual CALLINNUMTYPE  GetType()
		{
			if (m_pInfo)
				return (CALLINNUMTYPE)m_pInfo->GetType();

			return CALLINNUMTYPE::CALLINNUMTYPE_NONE;
		}

	private:
		ZOOM_SDK_NAMESPACE::IMeetingCallInPhoneNumberInfo* m_pInfo;
	};
	//
	bool CMeetingPhoneHelperDotNetWrap::IsSupportPhoneFeature()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().IsSupportPhoneFeature();
	}

	array<IMeetingPhoneSupportCountryInfoDotNetWrap^ >^ CMeetingPhoneHelperDotNetWrap::GetSupportCountryInfo()
	{
		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMeetingPhoneSupportCountryInfo* >* lstInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().GetSupportCountryInfo();
		if (lstInfo && lstInfo->GetCount() > 0)
		{
			int nCount = lstInfo->GetCount();
			array<IMeetingPhoneSupportCountryInfoDotNetWrap^ >^ lstInfo_dotnet = gcnew array<IMeetingPhoneSupportCountryInfoDotNetWrap^ >(nCount);
			if (lstInfo_dotnet)
			{
				for (int i = 0; i < nCount; i++)
				{

					lstInfo_dotnet[i] = gcnew IMeetingPhoneSupportCountryInfoDotNetWrapImpl(lstInfo->GetItem(i));
				}
				return lstInfo_dotnet;
			}
		}

		return nullptr;
	}

	SDKError CMeetingPhoneHelperDotNetWrap::InviteCallOutUser(String^ countryCode, String^ phoneNumber, String^ name)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().InviteCallOutUser(PlatformString2WChar(countryCode), PlatformString2WChar(phoneNumber), PlatformString2WChar(name));
	}

	SDKError CMeetingPhoneHelperDotNetWrap::CancelCallOut()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().CancelCallOut();
	}

	PhoneStatus CMeetingPhoneHelperDotNetWrap::GetInviteCalloutUserStatus()
	{
		return (PhoneStatus)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().GetInviteCalloutUserStatus();
	}

	SDKError CMeetingPhoneHelperDotNetWrap::CallMe(String^ countryCode, String^ phoneNumber)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().CallMe(PlatformString2WChar(countryCode), PlatformString2WChar(phoneNumber));
	}

	SDKError CMeetingPhoneHelperDotNetWrap::Hangup()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().Hangup();
	}

	PhoneStatus CMeetingPhoneHelperDotNetWrap::GetCallMeStatus()
	{
		return (PhoneStatus)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().GetCallMeStatus();
	}

	array<IMeetingCallInPhoneNumberInfoDotNetWrap^ >^ CMeetingPhoneHelperDotNetWrap::GetCurrentMeetingCallinNumber()
	{
		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMeetingCallInPhoneNumberInfo* >* lstInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().GetCurrentMeetingCallinNumber();
		if (lstInfo && lstInfo->GetCount() > 0)
		{
			int nCount = lstInfo->GetCount();
			array<IMeetingCallInPhoneNumberInfoDotNetWrap^ >^ lstInfo_dotnet = gcnew array<IMeetingCallInPhoneNumberInfoDotNetWrap^ >(nCount);
			if (lstInfo_dotnet)
			{
				for (int i = 0; i < nCount; i++)
				{

					lstInfo_dotnet[i] = gcnew IMeetingCallInPhoneNumberInfoDotNetWrapImpl(lstInfo->GetItem(i));
				}
				return lstInfo_dotnet;
			}
		}

		return nullptr;
	}

	unsigned int CMeetingPhoneHelperDotNetWrap::GetCurrentMeetingCallinParticipantID()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingPhoneHelper().GetCurrentMeetingCallinParticipantID();
	}


	void CMeetingPhoneHelperDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingPhoneHelperWrap& meetingPhone = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetMeetingPhoneHelper();
		meetingPhone.m_cbonCallMeStatus =
			std::bind(&MeetingPhoneHelperEventHanlder::onCallMeStatus,
				&MeetingPhoneHelperEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);

		meetingPhone.m_cbonInviteCallOutUserStatus =
			std::bind(&MeetingPhoneHelperEventHanlder::onInviteCallOutUserStatus,
				&MeetingPhoneHelperEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	void CMeetingPhoneHelperDotNetWrap::procInviteCallOutUserStatus(PhoneStatus status, PhoneFailedReason reason)
	{
		event_onInviteCallOutUserStatus(status, reason);
	}

	void CMeetingPhoneHelperDotNetWrap::procCallMeStatus(PhoneStatus status, PhoneFailedReason reason)
	{
		event_onCallMeStatus(status, reason);
	}
}
