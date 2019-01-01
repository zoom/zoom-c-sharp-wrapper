#pragma once

using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class PreMeetingAPIResult : int
	{
		PreMeeting_API_Result_Unknown,
		PreMeeting_API_Result_Success
	};

	public interface class IQueryMeetingItemDateInfoHelperDotNetWrap
	{
	public:
		Nullable<DateTime> GetCurrentStartTime();
		int GetDurationInMinutes();
		bool IsRecurringMeetingSelected();
	};

	public interface class ISelectMeetingItemDateHelperDotNetWrap
	{
	public:
		SDKError SelectStartTime(DateTime time);
		SDKError SetDurationInMinutes(int duration);
		SDKError SelectRecurringMeeting(bool select);
	};

	public enum class ScheduleAudioType : int
	{
		ScheduleAudioType_None = 0,
		ScheduleAudioType_Telephony = (1 << 1),
		ScheduleAudioType_VOIP = (1 << 2),
		ScheduleAudioType_Both = (1 << 3),
		ScheduleAudioType_3rd = (1 << 4),
	};

	public interface class IQueryMeetingItemTelAudioInfoHelperDotNetWrap
	{
	public:
		array<String^>^ GetAvailableDialingCountryCode();
		array<String^>^ GetSelectedDialingCountryCode();
		bool IsIncludeTollFree();
	};

	public interface class ISelectMeetingItemTelAudioHelperDotNetWrap
	{
	public:
		SDKError SelectDefaultDialInCountry(String^ countryId);
		SDKError EnableIncludeTollFree(bool enable);
	};

	public interface class IQueryMeetingItemAudioOptionHelperDotNetWrap
	{
	public:
		SDKError GetSelectedAudioType(ScheduleAudioType% audioType);
		IQueryMeetingItemTelAudioInfoHelperDotNetWrap^ GetQueryTelAudioInfoHelper();
	};

	public interface class ISelectMeetingItemAudioOptionHelperDotNetWrap
	{
	public:
		SDKError IsSupportAudioType(ScheduleAudioType audioType);
		SDKError  SelectAudioType(ScheduleAudioType audioType);
		ISelectMeetingItemTelAudioHelperDotNetWrap^ GetScheduleTelAudioHelper();
	};

	public interface class IQueryMeetingItemVideoOptionHelperDotNetWrap
	{
	public:
		bool IsHostVideoOnOrOff();
		bool IsAttendeeVideoOnOrOff();
	};

	public interface class ISelectMeetingItemVideoOptionHelperDotNetWrap
	{
	public:
		SDKError SelectHostVideoOnOrOff(bool on);
		SDKError SelectAttendeeVideoOnOrOff(bool on);
	};

	public enum class ScheduleRecordType : int
	{
		ScheduleRecordType_None = 0,
		SCHEDULERecordType_Cloud = 1,
		SCHEDULERecordType_Local = (1 << 1),
	};

	public interface class IScheduleForUserDotNetWrap
	{
	public:
		String^ GetEmail();
		String^ GetDisplayName();
		unsigned __int64 GetPMINumber();
	};

	public interface class IQueryMeetingItemScheduleForHelperDotNetWrap
	{
	public:
		IScheduleForUserDotNetWrap^ GetCurrentSelectedScheduleForUser();
	};

	public interface class ISelectMeetingItemScheduleForHelperDotNetWrap
	{
	public:
		array<IScheduleForUserDotNetWrap^>^ GetAvailableScheduleForList(bool& canSelectScheduleFor);
		SDKError SelectScheduleForUser(IScheduleForUserDotNetWrap^ alternateHost);
	};

	public interface class IQueryMeetingItemMeetingOptionHelperDotNetWrap
	{
	public:
		String^ GetMeetingTopic();
		bool IsMeetingPasswordEnabled(bool& canChange);
		String^ GetMeetingPassword();
		bool IsJoinBeforeHostEnabled(bool& canChange);
		bool IsMuteUponEntryEnabled(bool& canChange);
		bool IsScheduleWithPmiEnabled(bool& canChange);
		bool IsOnlySignedInUserCanJoinEnabled(bool& canChange);
		String^ GetSpecifiedDomainCanJoin(bool& canChange);
		bool IsHostInChinaEnabled(bool& canChange);
		bool IsAutoRecordEnabled(bool& canChange, int& supportRecordType);
		ScheduleRecordType GetSelectedAutoRecordType();
		IQueryMeetingItemScheduleForHelperDotNetWrap^ GetQueryScheduleForHelper();
	};

	public interface class ISelectMeetingItemMeetingOptionHelperDotNetWrap
	{
	public:
		SDKError SetMeetingTopic(String^ topic);
		SDKError EnableMeetingPassword(bool enable);
		SDKError SetMeetingPassword(String^ password);
		SDKError EnableJoinBeforeHost(bool enable);
		SDKError EnableMuteUponEntry(bool enable);
		SDKError EnableScheduleWithPmi(bool enable);
		SDKError EnableOnlySignedInUserCanJoin(bool enable);
		SDKError SetSpecifiedDomainCanJoin(String^ domain);
		SDKError EnableHostInChina(bool enable);
		SDKError EnableAutoRecord(bool enable);
		SDKError SelectAutoRecordType(ScheduleRecordType type);
		ISelectMeetingItemScheduleForHelperDotNetWrap^ GetScheduleForHelper();
	};

	public interface class IMeetingItemInfoDotNetWrap
		: public IQueryMeetingItemDateInfoHelperDotNetWrap
		, public IQueryMeetingItemVideoOptionHelperDotNetWrap
		, public IQueryMeetingItemAudioOptionHelperDotNetWrap
		, public IQueryMeetingItemMeetingOptionHelperDotNetWrap
	{
	public:
		unsigned __int64 GetUniqueMeetingId();
		unsigned __int64 GetMeetingId();
		bool IsPMI();
		bool IsWebinar();
		String^ GetInviteEmailContent();
		String^ GetInviteEmailSubject();
		String^ GetJoinMeetingUrl();
	};

	public interface class IMeetingItemInfoQueryHelperDotNetWrap : public IMeetingItemInfoDotNetWrap
	{
	public:
	};

	public interface class IMeetingItemInfoSelectHelperDotNetWrap
		: public ISelectMeetingItemDateHelperDotNetWrap
		, public ISelectMeetingItemVideoOptionHelperDotNetWrap
		, public ISelectMeetingItemAudioOptionHelperDotNetWrap
		, public ISelectMeetingItemMeetingOptionHelperDotNetWrap
	{
	public:
	};

	// ---------------------------------------------------------
	// Translate IQueryMeetingItemTelAudioInfoHelper
	//
	public ref class IQueryMeetingItemTelAudioInfoHelperDotNetWrapImpl sealed : public IQueryMeetingItemTelAudioInfoHelperDotNetWrap
	{
	public:
		IQueryMeetingItemTelAudioInfoHelperDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IQueryMeetingItemTelAudioInfoHelper* pObj)
		{
			m_pSDKObj = pObj;
		}

		IQueryMeetingItemTelAudioInfoHelperDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		virtual array<String^>^ GetAvailableDialingCountryCode()
		{
			if (m_pSDKObj)
			{
				return Convert(m_pSDKObj->GetAvailableDialinCountryCode());
			}

			return nullptr;
		}

		virtual array<String^>^ GetSelectedDialingCountryCode()
		{
			if (m_pSDKObj)
			{
				return Convert(m_pSDKObj->GetSelectedDialinCountryCode());
			}

			return nullptr;
		}

		virtual bool IsIncludeTollFree()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsIncludeTollFree();
			}

			return false;
		}

	private:
		ZOOM_SDK_NAMESPACE::IQueryMeetingItemTelAudioInfoHelper* m_pSDKObj;
	};

	// ---------------------------------------------------------
	// Translate IScheduleForUser
	//
	public ref class IScheduleForUserDotNetWrapImpl sealed : public IScheduleForUserDotNetWrap
	{
	public:
		IScheduleForUserDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IScheduleForUser* pObj)
		{
			m_pSDKObj = pObj;
		}

		IScheduleForUserDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		virtual String^ GetEmail()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetEmail());
			}

			return nullptr;
		}

		virtual String^ GetDisplayName()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetDisplayName());
			}

			return nullptr;
		}

		virtual unsigned __int64 GetPMINumber()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetPMINumber();
			}

			return 0;
		}

	private:
		ZOOM_SDK_NAMESPACE::IScheduleForUser* m_pSDKObj;
	};

	// ---------------------------------------------------------
	// Translate IQueryMeetingItemTelAudioInfoHelper
	//
	public ref class IQueryMeetingItemScheduleForHelperDotNetWrapImpl sealed : public IQueryMeetingItemScheduleForHelperDotNetWrap
	{
	public:
		IQueryMeetingItemScheduleForHelperDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IQueryMeetingItemScheduleForHelper* pObj)
		{
			m_pSDKObj = pObj;
		}

		IQueryMeetingItemScheduleForHelperDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		virtual IScheduleForUserDotNetWrap^ GetCurrentSelectedScheduleForUser()
		{
			if (m_pSDKObj)
			{
				return gcnew IScheduleForUserDotNetWrapImpl(m_pSDKObj->GetCurrentSelectedScheduleForUser());
			}

			return nullptr;
		}

	private:
		ZOOM_SDK_NAMESPACE::IQueryMeetingItemScheduleForHelper* m_pSDKObj;
	};

	// ---------------------------------------------------------
	// Translate ISelectMeetingItemTelAudioHelper
	//
	public ref class ISelectMeetingItemTelAudioHelperDotNetWrapImpl sealed : public ISelectMeetingItemTelAudioHelperDotNetWrap
	{
	public:
		ISelectMeetingItemTelAudioHelperDotNetWrapImpl(ZOOM_SDK_NAMESPACE::ISelectMeetingItemTelAudioHelper* pObj)
		{
			m_pSDKObj = pObj;
		}

		ISelectMeetingItemTelAudioHelperDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		virtual SDKError SelectDefaultDialInCountry(String^ countryId)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectDefaultDialInCountry(PlatformString2WChar(countryId));
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableIncludeTollFree(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableIncludeTollFree(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

	private:
		ZOOM_SDK_NAMESPACE::ISelectMeetingItemTelAudioHelper* m_pSDKObj;
	};

	// ---------------------------------------------------------
	// Translate ISelectMeetingItemScheduleForHelper
	//
	public ref class ISelectMeetingItemScheduleForHelperDotNetWrapImpl sealed : public ISelectMeetingItemScheduleForHelperDotNetWrap
	{
	public:
		ISelectMeetingItemScheduleForHelperDotNetWrapImpl(ZOOM_SDK_NAMESPACE::ISelectMeetingItemScheduleForHelper* pObj)
		{
			m_pSDKObj = pObj;
		}

		ISelectMeetingItemScheduleForHelperDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		virtual array<IScheduleForUserDotNetWrap^>^ GetAvailableScheduleForList(bool& canSelectScheduleFor)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IScheduleForUser*>* lstItems = m_pSDKObj->GetAvailableScheduleForList(canSelectScheduleFor);
				if (lstItems && lstItems->GetCount() > 0)
				{
					int nCount = lstItems->GetCount();
					array<IScheduleForUserDotNetWrap^>^ lstItems_dotnet = gcnew array<IScheduleForUserDotNetWrap^>(nCount);
					if (lstItems_dotnet)
					{
						for (int i(0); i < nCount; i++)
						{
							lstItems_dotnet[i] = gcnew IScheduleForUserDotNetWrapImpl(lstItems->GetItem(i));
						}

						return lstItems_dotnet;
					}
				}

				return nullptr;
			}

			return nullptr;
		}

		virtual SDKError SelectScheduleForUser(IScheduleForUserDotNetWrap^ alternateHost)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::IScheduleForUserImpl alternateHost_c;
				if (alternateHost != nullptr)
				{
					alternateHost_c.SetEmail(PlatformString2WChar(alternateHost->GetEmail()));
					alternateHost_c.SetDisplayName(PlatformString2WChar(alternateHost->GetDisplayName()));
					alternateHost_c.SetPMINumber(alternateHost->GetPMINumber());
					return (SDKError)m_pSDKObj->SelectScheduleForUser(&alternateHost_c);
				}
			}
		}

	private:
		ZOOM_SDK_NAMESPACE::ISelectMeetingItemScheduleForHelper* m_pSDKObj;
	};
}
