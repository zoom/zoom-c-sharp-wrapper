#pragma once

using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap\schedule_meeting_item_wrap.h"
#include "premeeting_service_dotnet_wrap_def.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public interface class IScheduleMeetingItemDotNet
		: public IMeetingItemInfoSelectHelperDotNetWrap
		, public IMeetingItemInfoQueryHelperDotNetWrap
	{
	public:
	};

	// ---------------------------------------------------------
	// Translate IScheduleMeetingItem
	//
	private ref class IScheduleMeetingItemDotNetWrapImpl sealed
		: public IScheduleMeetingItemDotNet, IMeetingItemInfoSelectHelperDotNetWrap, IMeetingItemInfoQueryHelperDotNetWrap
	{
	public:
		IScheduleMeetingItemDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pObj)
		{
			m_pSDKObj = pObj;
		}

		IScheduleMeetingItemDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		~IScheduleMeetingItemDotNetWrapImpl()
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().DestoryScheduleMeetingItem(m_pSDKObj->GetSDKObj());
				m_pSDKObj = NULL;
			}
		}

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* GetSDKObj()
		{
			return m_pSDKObj;
		}

		// ---------------------------------------------------------
		// IMeetingItemInfoQueryHelperDotNetWrap
		//
		virtual Nullable<DateTime> GetCurrentStartTime()
		{
			if (m_pSDKObj)
			{
				Nullable<DateTime> time = time_t2DateTime(m_pSDKObj->GetCurrentStartTime());
				return time;
			}

			return Nullable<DateTime>();
		}

		virtual int GetDurationInMinutes()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetDurationInMinutes();
			}

			return 0;
		}

		virtual bool IsRecurringMeetingSelected()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsRecurringMeetingSelected();
			}

			return false;
		}

		virtual bool IsHostVideoOnOrOff()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsHostVideoOnOrOff();
			}

			return false;
		}

		virtual bool IsAttendeeVideoOnOrOff()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsAttendeeVideoOnOrOff();
			}

			return false;
		}

		virtual SDKError GetSelectedAudioType(ScheduleAudioType% audioType)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::SCHEDULEAUDIOTYPE audioType_native;
				SDKError result = (SDKError)m_pSDKObj->GetSelectedAudioType(audioType_native);
				audioType = (ScheduleAudioType)audioType_native;
				return result;
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual IQueryMeetingItemTelAudioInfoHelperDotNetWrap^ GetQueryTelAudioInfoHelper()
		{
			if (m_pSDKObj)
			{
				return gcnew IQueryMeetingItemTelAudioInfoHelperDotNetWrapImpl(m_pSDKObj->GetQueryTelAudioInfoHelper());
			}

			return nullptr;
		}

		virtual String^ GetMeetingTopic()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetMeetingTopic());
			}

			return nullptr;
		}

		virtual bool IsMeetingPasswordEnabled(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsMeetingPasswordEnabled(canChange);
			}

			return false;
		}

		virtual String^ GetMeetingPassword()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetMeetingPassword());
			}

			return nullptr;
		}

		virtual bool IsJoinBeforeHostEnabled(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsJoinBeforeHostEnabled(canChange);
			}

			return false;
		}

		virtual bool IsMuteUponEntryEnabled(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsMuteUponEntryEnabled(canChange);
			}

			return false;
		}

		virtual bool IsScheduleWithPmiEnabled(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsScheduleWithPmiEnabled(canChange);
			}

			return false;
		}

		virtual bool IsOnlySignedInUserCanJoinEnabled(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsOnlySignedInUserCanJoinEnabled(canChange);
			}

			return false;
		}

		virtual String^ GetSpecifiedDomainCanJoin(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetSpecifiedDomainCanJoin(canChange));
			}

			return nullptr;
		}

		virtual bool IsHostInChinaEnabled(bool& canChange)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsHostInChinaEnabled(canChange);
			}

			return false;
		}

		virtual bool IsAutoRecordEnabled(bool& canChange, int& supportRecordType)
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsAutoRecordEnabled(canChange, supportRecordType);
			}

			return false;
		}

		virtual ScheduleRecordType GetSelectedAutoRecordType()
		{
			if (m_pSDKObj)
			{
				return (ScheduleRecordType)m_pSDKObj->GetSelectedAutoRecordType();
			}

			return ScheduleRecordType::ScheduleRecordType_None;
		}

		virtual IQueryMeetingItemScheduleForHelperDotNetWrap^ GetQueryScheduleForHelper()
		{
			if (m_pSDKObj)
			{
				return gcnew IQueryMeetingItemScheduleForHelperDotNetWrapImpl(m_pSDKObj->GetQueryScheduleForHelper());
			}

			return nullptr;
		}

		// ---------------------------------------------------------
		// IMeetingItemInfoDotNetWrap
		//
		virtual unsigned __int64 GetUniqueMeetingId()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetUniqueMeetingID();
			}

			return 0;
		}

		virtual unsigned __int64 GetMeetingId()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetMeetingID();
			}

			return 0;
		}

		virtual bool IsPMI()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsPMI();
			}

			return false;
		}

		virtual bool IsWebinar()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsWebinar();
			}

			return false;
		}

		virtual String^ GetInviteEmailContent()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetInviteEmailContent());
			}

			return nullptr;
		}

		virtual String^ GetInviteEmailSubject()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetInviteEmailSubject());
			}

			return nullptr;
		}

		virtual String^ GetJoinMeetingUrl()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetJoinMeetingUrl());
			}

			return nullptr;
		}

		// ---------------------------------------------------------
		// IMeetingItemInfoSelectHelperDotNetWrap
		//
		virtual SDKError SelectStartTime(DateTime time)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectStartTime(DateTime2time_t(time));
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SetDurationInMinutes(int duration)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetDurationInMinutes(duration);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectRecurringMeeting(bool select)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectRecurringMeeting(select);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectHostVideoOnOrOff(bool on)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectHostVideoOnOrOff(on);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectAttendeeVideoOnOrOff(bool on)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectAttendeeVideoOnOrOff(on);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError IsSupportAudioType(ScheduleAudioType audioType)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->IsSupportAudioType((ZOOM_SDK_NAMESPACE::SCHEDULEAUDIOTYPE)audioType);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectAudioType(ScheduleAudioType audioType)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectAudioType((ZOOM_SDK_NAMESPACE::SCHEDULEAUDIOTYPE)audioType);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual ISelectMeetingItemTelAudioHelperDotNetWrap^ GetScheduleTelAudioHelper()
		{
			if (m_pSDKObj)
			{
				return gcnew ISelectMeetingItemTelAudioHelperDotNetWrapImpl(m_pSDKObj->GetScheduleTelAudioHelper());
			}

			return nullptr;
		}

		virtual SDKError SetMeetingTopic(String^ topic)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetMeetingTopic(PlatformString2WChar(topic));
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableMeetingPassword(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableMeetingPassword(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SetMeetingPassword(String^ password)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetMeetingPassword(PlatformString2WChar(password));
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableJoinBeforeHost(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableJoinBeforeHost(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableMuteUponEntry(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableMuteUponEntry(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableScheduleWithPmi(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableScheduleWithPmi(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableOnlySignedInUserCanJoin(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableOnlySignedInUserCanJoin(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SetSpecifiedDomainCanJoin(String^ domain)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetSpecifiedDomainCanJoin(PlatformString2WChar(domain));
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableHostInChina(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableHostInChina(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError EnableAutoRecord(bool enable)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableAutoRecord(enable);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectAutoRecordType(ScheduleRecordType type)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectAutoRecordType((ZOOM_SDK_NAMESPACE::SCHEDULERECTYPE)type);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual ISelectMeetingItemScheduleForHelperDotNetWrap^ GetScheduleForHelper()
		{
			if (m_pSDKObj)
			{
				return gcnew ISelectMeetingItemScheduleForHelperDotNetWrapImpl(m_pSDKObj->GetScheduleForHelper());
			}

			return nullptr;
		}

	private:
		ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* m_pSDKObj;
	};

	public delegate void onSupportTelAudioNotification(bool canUse);
	public delegate void onMeetingPasswordEnabledStatusNotification(bool enable, String^ defaultPassword);
	public delegate void onJoinBeforeHostEnabledStatusNotification(bool enable);
	public delegate void onMuteUponEntryEnabledStatusNotification(bool enable);
	public delegate void onScheduleWithPmiEnabledStatusNotification(bool enable);
	public delegate void onOnlySignedInUserCanJoinEnabledStatusNotification(bool enable, String^ defaultDomain);
	public delegate void onHostInChinaEnabledStatusNotification(bool enable);
	public delegate void onAutoRecordEnabledStatusNotification(bool enable, ScheduleRecordType& defaultType);
	public delegate void onSupportScheduleForNotification(bool canUse);
	public delegate void onScheduleMeetingItemDestroyed();

	public interface class IScheduleMeetingItemDotNetWrap
	{
	public:
		SDKError SelectStartTime(DateTime time);
		SDKError SetDurationInMinutes(int duration);
		SDKError SelectRecurringMeeting(bool select);
		SDKError SelectHostVideoOnOrOff(bool on);
		SDKError SelectAttendeeVideoOnOrOff(bool on);
		SDKError IsSupportAudioType(ScheduleAudioType audioType);
		SDKError SelectAudioType(ScheduleAudioType audioType);
		ISelectMeetingItemTelAudioHelperDotNetWrap^ GetScheduleTelAudioHelper();
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
		Nullable<DateTime> GetCurrentStartTime();
		int GetDurationInMinutes();
		bool IsRecurringMeetingSelected();
		bool IsHostVideoOnOrOff();
		bool IsAttendeeVideoOnOrOff();
		SDKError GetSelectedAudioType(ScheduleAudioType% type);
		IQueryMeetingItemTelAudioInfoHelperDotNetWrap^ GetQueryTelAudioInfoHelper();
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
		unsigned __int64 GetUniqueMeetingId();
		unsigned __int64 GetMeetingId();
		bool IsPMI();
		bool IsWebinar();
		String^ GetInviteEmailContent();
		String^ GetInviteEmailSubject();
		String^ GetJoinMeetingUrl();

		void Add_CB_onSupportTelAudioNotification(onSupportTelAudioNotification^ cb);
		void Add_CB_onMeetingPasswordEnabledStatusNotification(onMeetingPasswordEnabledStatusNotification^ cb);
		void Add_CB_onJoinBeforeHostEnabledStatusNotification(onJoinBeforeHostEnabledStatusNotification^ cb);
		void Add_CB_onMuteUponEntryEnabledStatusNotification(onMuteUponEntryEnabledStatusNotification^ cb);
		void Add_CB_onScheduleWithPmiEnabledStatusNotification(onScheduleWithPmiEnabledStatusNotification^ cb);
		void Add_CB_onOnlySignedInUserCanJoinEnabledStatusNotification(onOnlySignedInUserCanJoinEnabledStatusNotification^ cb);
		void Add_CB_onHostInChinaEnabledStatusNotification(onHostInChinaEnabledStatusNotification^ cb);
		void Add_CB_onAutoRecordEnabledStatusNotification(onAutoRecordEnabledStatusNotification^ cb);
		void Add_CB_onSupportScheduleForNotification(onSupportScheduleForNotification^ cb);
		void Add_CB_onScheduleMeetingItemDestroyed(onScheduleMeetingItemDestroyed^ cb);

		void Remove_CB_onSupportTelAudioNotification(onSupportTelAudioNotification^ cb);
		void Remove_CB_onMeetingPasswordEnabledStatusNotification(onMeetingPasswordEnabledStatusNotification^ cb);
		void Remove_CB_onJoinBeforeHostEnabledStatusNotification(onJoinBeforeHostEnabledStatusNotification^ cb);
		void Remove_CB_onMuteUponEntryEnabledStatusNotification(onMuteUponEntryEnabledStatusNotification^ cb);
		void Remove_CB_onScheduleWithPmiEnabledStatusNotification(onScheduleWithPmiEnabledStatusNotification^ cb);
		void Remove_CB_onOnlySignedInUserCanJoinEnabledStatusNotification(onOnlySignedInUserCanJoinEnabledStatusNotification^ cb);
		void Remove_CB_onHostInChinaEnabledStatusNotification(onHostInChinaEnabledStatusNotification^ cb);
		void Remove_CB_onAutoRecordEnabledStatusNotification(onAutoRecordEnabledStatusNotification^ cb);
		void Remove_CB_onSupportScheduleForNotification(onSupportScheduleForNotification^ cb);
		void Remove_CB_onScheduleMeetingItemDestroyed(onScheduleMeetingItemDestroyed^ cb);
	};

	class ScheduleMeetingItemEventHandler;
	private ref class CScheduleMeetingItemDotNetWrap sealed : public IScheduleMeetingItemDotNetWrap
	{
	public:
		CScheduleMeetingItemDotNetWrap(ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pWrap);

		void BindEvent();
		void ProcSupportTelAudioNotification(bool canUse);
		void ProcMeetingPasswordEnabledStatusNotification(bool enable, String^ defaultPassword);
		void ProcJoinBeforeHostEnabledStatusNotification(bool enable);
		void ProcMuteUponEntryEnabledStatusNotification(bool enable);
		void ProcScheduleWithPmiEnabledStatusNotification(bool enable);
		void ProcOnlySignedInUserCanJoinEnabledStatusNotification(bool enable, String^ defaultDomain);
		void ProcHostInChinaEnabledStatusNotification(bool enable);
		void ProcAutoRecordEnabledStatusNotification(bool enable, ScheduleRecordType& defaultType);
		void ProcSupportScheduleForNotification(bool canUse);
		void ProcScheduleMeetingItemDestroyed();

		IScheduleMeetingItemDotNetWrapImpl^ Inner();

		virtual SDKError SelectStartTime(DateTime time);
		virtual SDKError SetDurationInMinutes(int duration);
		virtual SDKError SelectRecurringMeeting(bool select);
		virtual SDKError SelectHostVideoOnOrOff(bool on);
		virtual SDKError SelectAttendeeVideoOnOrOff(bool on);
		virtual SDKError IsSupportAudioType(ScheduleAudioType audioType);
		virtual SDKError SelectAudioType(ScheduleAudioType audioType);
		virtual ISelectMeetingItemTelAudioHelperDotNetWrap^ GetScheduleTelAudioHelper();
		virtual SDKError SetMeetingTopic(String^ topic);
		virtual SDKError EnableMeetingPassword(bool enable);
		virtual SDKError SetMeetingPassword(String^ password);
		virtual SDKError EnableJoinBeforeHost(bool enable);
		virtual SDKError EnableMuteUponEntry(bool enable);
		virtual SDKError EnableScheduleWithPmi(bool enable);
		virtual SDKError EnableOnlySignedInUserCanJoin(bool enable);
		virtual SDKError SetSpecifiedDomainCanJoin(String^ domain);
		virtual SDKError EnableHostInChina(bool enable);
		virtual SDKError EnableAutoRecord(bool enable);
		virtual SDKError SelectAutoRecordType(ScheduleRecordType type);
		virtual ISelectMeetingItemScheduleForHelperDotNetWrap^ GetScheduleForHelper();
		virtual Nullable<DateTime> GetCurrentStartTime();
		virtual int GetDurationInMinutes();
		virtual bool IsRecurringMeetingSelected();
		virtual bool IsHostVideoOnOrOff();
		virtual bool IsAttendeeVideoOnOrOff();
		virtual SDKError GetSelectedAudioType(ScheduleAudioType% type);
		virtual IQueryMeetingItemTelAudioInfoHelperDotNetWrap^ GetQueryTelAudioInfoHelper();
		virtual String^ GetMeetingTopic();
		virtual bool IsMeetingPasswordEnabled(bool& canChange);
		virtual String^ GetMeetingPassword();
		virtual bool IsJoinBeforeHostEnabled(bool& canChange);
		virtual bool IsMuteUponEntryEnabled(bool& canChange);
		virtual bool IsScheduleWithPmiEnabled(bool& canChange);
		virtual bool IsOnlySignedInUserCanJoinEnabled(bool& canChange);
		virtual String^ GetSpecifiedDomainCanJoin(bool& canChange);
		virtual bool IsHostInChinaEnabled(bool& canChange);
		virtual bool IsAutoRecordEnabled(bool& canChange, int& supportRecordType);
		virtual ScheduleRecordType GetSelectedAutoRecordType();
		virtual IQueryMeetingItemScheduleForHelperDotNetWrap^ GetQueryScheduleForHelper();
		virtual unsigned __int64 GetUniqueMeetingId();
		virtual unsigned __int64 GetMeetingId();
		virtual bool IsPMI();
		virtual bool IsWebinar();
		virtual String^ GetInviteEmailContent();
		virtual String^ GetInviteEmailSubject();
		virtual String^ GetJoinMeetingUrl();

		virtual void Add_CB_onSupportTelAudioNotification(onSupportTelAudioNotification^ cb)
		{
			event_onSupportTelAudioNotification += cb;
		}

		virtual void Remove_CB_onSupportTelAudioNotification(onSupportTelAudioNotification^ cb)
		{
			event_onSupportTelAudioNotification -= cb;
		}

		virtual void Add_CB_onMeetingPasswordEnabledStatusNotification(onMeetingPasswordEnabledStatusNotification^ cb)
		{
			event_onMeetingPasswordEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onMeetingPasswordEnabledStatusNotification(onMeetingPasswordEnabledStatusNotification^ cb)
		{
			event_onMeetingPasswordEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onJoinBeforeHostEnabledStatusNotification(onJoinBeforeHostEnabledStatusNotification^ cb)
		{
			event_onJoinBeforeHostEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onJoinBeforeHostEnabledStatusNotification(onJoinBeforeHostEnabledStatusNotification^ cb)
		{
			event_onJoinBeforeHostEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onMuteUponEntryEnabledStatusNotification(onMuteUponEntryEnabledStatusNotification^ cb)
		{
			event_onMuteUponEntryEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onMuteUponEntryEnabledStatusNotification(onMuteUponEntryEnabledStatusNotification^ cb)
		{
			event_onMuteUponEntryEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onScheduleWithPmiEnabledStatusNotification(onScheduleWithPmiEnabledStatusNotification^ cb)
		{
			event_onScheduleWithPmiEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onScheduleWithPmiEnabledStatusNotification(onScheduleWithPmiEnabledStatusNotification^ cb)
		{
			event_onScheduleWithPmiEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onOnlySignedInUserCanJoinEnabledStatusNotification(onOnlySignedInUserCanJoinEnabledStatusNotification^ cb)
		{
			event_onOnlySignedInUserCanJoinEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onOnlySignedInUserCanJoinEnabledStatusNotification(onOnlySignedInUserCanJoinEnabledStatusNotification^ cb)
		{
			event_onOnlySignedInUserCanJoinEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onHostInChinaEnabledStatusNotification(onHostInChinaEnabledStatusNotification^ cb)
		{
			event_onHostInChinaEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onHostInChinaEnabledStatusNotification(onHostInChinaEnabledStatusNotification^ cb)
		{
			event_onHostInChinaEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onAutoRecordEnabledStatusNotification(onAutoRecordEnabledStatusNotification^ cb)
		{
			event_onAutoRecordEnabledStatusNotification += cb;
		}

		virtual void Remove_CB_onAutoRecordEnabledStatusNotification(onAutoRecordEnabledStatusNotification^ cb)
		{
			event_onAutoRecordEnabledStatusNotification -= cb;
		}

		virtual void Add_CB_onSupportScheduleForNotification(onSupportScheduleForNotification^ cb)
		{
			event_onSupportScheduleForNotification += cb;
		}

		virtual void Remove_CB_onSupportScheduleForNotification(onSupportScheduleForNotification^ cb)
		{
			event_onSupportScheduleForNotification -= cb;
		}

		virtual void Add_CB_onScheduleMeetingItemDestroyed(onScheduleMeetingItemDestroyed^ cb)
		{
			event_onScheduleMeetingItemDestroyed += cb;
		}

		virtual void Remove_CB_onScheduleMeetingItemDestroyed(onScheduleMeetingItemDestroyed^ cb)
		{
			event_onScheduleMeetingItemDestroyed -= cb;
		}

	private:
		CScheduleMeetingItemDotNetWrap();
		virtual ~CScheduleMeetingItemDotNetWrap();
		event onSupportTelAudioNotification^ event_onSupportTelAudioNotification;
		event onMeetingPasswordEnabledStatusNotification^ event_onMeetingPasswordEnabledStatusNotification;
		event onJoinBeforeHostEnabledStatusNotification^ event_onJoinBeforeHostEnabledStatusNotification;
		event onMuteUponEntryEnabledStatusNotification^ event_onMuteUponEntryEnabledStatusNotification;
		event onScheduleWithPmiEnabledStatusNotification^ event_onScheduleWithPmiEnabledStatusNotification;
		event onOnlySignedInUserCanJoinEnabledStatusNotification^ event_onOnlySignedInUserCanJoinEnabledStatusNotification;
		event onHostInChinaEnabledStatusNotification^ event_onHostInChinaEnabledStatusNotification;
		event onAutoRecordEnabledStatusNotification^ event_onAutoRecordEnabledStatusNotification;
		event onSupportScheduleForNotification^ event_onSupportScheduleForNotification;
		event onScheduleMeetingItemDestroyed^ event_onScheduleMeetingItemDestroyed;

		IScheduleMeetingItemDotNetWrapImpl^ m_dotNetWrapImpl;
		ScheduleMeetingItemEventHandler* m_pEvents;
	};

	// Translate events
	// Unlike most of the event handlers in the wrapper project, this is not a static class.
	// Because the dot net wrapper class that is the event target isn't static, it must be 
	// implemented as a member of the dot net wrapper class.
	class ScheduleMeetingItemEventHandler
	{
	public:
		ScheduleMeetingItemEventHandler(CScheduleMeetingItemDotNetWrap^ pTarget)
		{
			m_Target = pTarget;
		}

		virtual void onSupportTelAudioNotification(bool canUse)
		{
			m_Target->ProcSupportTelAudioNotification(canUse);
		}

		virtual void onMeetingPasswordEnabledStatusNotification(bool enable, const wchar_t* defaultPassword)
		{
			m_Target->ProcMeetingPasswordEnabledStatusNotification(enable, WChar2PlatformString(defaultPassword));
		}

		virtual void onJoinBeforeHostEnabledStatusNotification(bool enable)
		{
			m_Target->ProcJoinBeforeHostEnabledStatusNotification(enable);
		}

		virtual void onMuteUponEntryEnabledStatusNotification(bool enable)
		{
			m_Target->ProcMuteUponEntryEnabledStatusNotification(enable);
		}

		virtual void onScheduleWithPmiEnabledStatusNotification(bool enable)
		{
			m_Target->ProcScheduleWithPmiEnabledStatusNotification(enable);
		}

		virtual void onOnlySignedInUserCanJoinEnabledStatusNotification(bool enable, const wchar_t* defaultDomain)
		{
			m_Target->ProcOnlySignedInUserCanJoinEnabledStatusNotification(enable, WChar2PlatformString(defaultDomain));
		}

		virtual void onHostInChinaEnabledStatusNotification(bool enable)
		{
			m_Target->ProcHostInChinaEnabledStatusNotification(enable);
		}

		virtual void onAutoRecordEnabledStatusNotification(bool enable, ZOOM_SDK_NAMESPACE::SCHEDULERECTYPE& defaultType)
		{
			m_Target->ProcAutoRecordEnabledStatusNotification(enable, (ScheduleRecordType&)defaultType);
		}

		virtual void onSupportScheduleForNotification(bool canUse)
		{
			m_Target->ProcSupportScheduleForNotification(canUse);
		}

		virtual void onScheduleMeetingItemDestroyed()
		{
			m_Target->ProcScheduleMeetingItemDestroyed();
		}

	private:
		ScheduleMeetingItemEventHandler() {}

		gcroot<CScheduleMeetingItemDotNetWrap^> m_Target;
	};
}
