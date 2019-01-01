#include "stdafx.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "schedule_meeting_item_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	CScheduleMeetingItemDotNetWrap::CScheduleMeetingItemDotNetWrap()
	{
		m_dotNetWrapImpl = nullptr;
		m_pEvents = NULL;
	}

	CScheduleMeetingItemDotNetWrap::CScheduleMeetingItemDotNetWrap(ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pWrap)
	{
		m_dotNetWrapImpl = gcnew IScheduleMeetingItemDotNetWrapImpl(pWrap);
		m_pEvents = new ScheduleMeetingItemEventHandler(this);
	}

	CScheduleMeetingItemDotNetWrap::~CScheduleMeetingItemDotNetWrap()
	{
	}

	void CScheduleMeetingItemDotNetWrap::BindEvent()
	{
		m_dotNetWrapImpl->GetSDKObj()->m_cbonSupportTelAudioNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onSupportTelAudioNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonMeetingPasswordEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onMeetingPasswordEnabledStatusNotification, *m_pEvents, std::placeholders::_1, std::placeholders::_2);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonJoinBeforeHostEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onJoinBeforeHostEnabledStatusNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonMuteUponEntryEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onMuteUponEntryEnabledStatusNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonScheduleWithPmiEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onScheduleWithPmiEnabledStatusNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonOnlySignedInUserCanJoinEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onOnlySignedInUserCanJoinEnabledStatusNotification, *m_pEvents, std::placeholders::_1, std::placeholders::_2);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonHostInChinaEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onHostInChinaEnabledStatusNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonAutoRecordEnabledStatusNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onAutoRecordEnabledStatusNotification, *m_pEvents, std::placeholders::_1, std::placeholders::_2);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonSupportScheduleForNotification =
			std::bind(&ScheduleMeetingItemEventHandler::onSupportScheduleForNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonScheduleMeetingItemDestroyed =
			std::bind(&ScheduleMeetingItemEventHandler::onScheduleMeetingItemDestroyed, *m_pEvents);
	}

	void CScheduleMeetingItemDotNetWrap::ProcSupportTelAudioNotification(bool canUse)
	{
		event_onSupportTelAudioNotification(canUse);
	}
	void CScheduleMeetingItemDotNetWrap::ProcMeetingPasswordEnabledStatusNotification(bool enable, String^ defaultPassword)
	{
		event_onMeetingPasswordEnabledStatusNotification(enable, defaultPassword);
	}
	void CScheduleMeetingItemDotNetWrap::ProcJoinBeforeHostEnabledStatusNotification(bool enable)
	{
		event_onJoinBeforeHostEnabledStatusNotification(enable);
	}
	void CScheduleMeetingItemDotNetWrap::ProcMuteUponEntryEnabledStatusNotification(bool enable)
	{
		event_onMuteUponEntryEnabledStatusNotification(enable);
	}
	void CScheduleMeetingItemDotNetWrap::ProcScheduleWithPmiEnabledStatusNotification(bool enable)
	{
		event_onScheduleWithPmiEnabledStatusNotification(enable);
	}
	void CScheduleMeetingItemDotNetWrap::ProcOnlySignedInUserCanJoinEnabledStatusNotification(bool enable, String^ defaultDomain)
	{
		event_onOnlySignedInUserCanJoinEnabledStatusNotification(enable, defaultDomain);
	}
	void CScheduleMeetingItemDotNetWrap::ProcHostInChinaEnabledStatusNotification(bool enable)
	{
		event_onHostInChinaEnabledStatusNotification(enable);
	}
	void CScheduleMeetingItemDotNetWrap::ProcAutoRecordEnabledStatusNotification(bool enable, ScheduleRecordType& defaultType)
	{
		event_onAutoRecordEnabledStatusNotification(enable, defaultType);
	}

	void CScheduleMeetingItemDotNetWrap::ProcSupportScheduleForNotification(bool canUse)
	{
		event_onSupportScheduleForNotification(canUse);
	}

	void CScheduleMeetingItemDotNetWrap::ProcScheduleMeetingItemDestroyed()
	{
		event_onScheduleMeetingItemDestroyed();
	}

	IScheduleMeetingItemDotNetWrapImpl^ CScheduleMeetingItemDotNetWrap::Inner()
	{
		return m_dotNetWrapImpl;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SelectStartTime(DateTime time)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SelectStartTime(time);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SetDurationInMinutes(int duration)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetDurationInMinutes(duration);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SelectRecurringMeeting(bool select)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SelectRecurringMeeting(select);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SelectHostVideoOnOrOff(bool on)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SelectHostVideoOnOrOff(on);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SelectAttendeeVideoOnOrOff(bool on)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SelectAttendeeVideoOnOrOff(on);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::IsSupportAudioType(ScheduleAudioType audioType)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsSupportAudioType(audioType);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SelectAudioType(ScheduleAudioType audioType)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SelectAudioType(audioType);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	ISelectMeetingItemTelAudioHelperDotNetWrap^ CScheduleMeetingItemDotNetWrap::GetScheduleTelAudioHelper()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetScheduleTelAudioHelper();
		}

		return nullptr;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SetMeetingTopic(String^ topic)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetMeetingTopic(topic);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableMeetingPassword(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableMeetingPassword(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SetMeetingPassword(String^ password)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetMeetingPassword(password);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableJoinBeforeHost(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableJoinBeforeHost(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableMuteUponEntry(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableMuteUponEntry(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableScheduleWithPmi(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableScheduleWithPmi(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableOnlySignedInUserCanJoin(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableOnlySignedInUserCanJoin(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SetSpecifiedDomainCanJoin(String^ domain)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetSpecifiedDomainCanJoin(domain);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableHostInChina(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableHostInChina(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::EnableAutoRecord(bool enable)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->EnableAutoRecord(enable);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CScheduleMeetingItemDotNetWrap::SelectAutoRecordType(ScheduleRecordType type)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SelectAutoRecordType(type);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	ISelectMeetingItemScheduleForHelperDotNetWrap^ CScheduleMeetingItemDotNetWrap::GetScheduleForHelper()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetScheduleForHelper();
		}

		return nullptr;
	}

	Nullable<DateTime> CScheduleMeetingItemDotNetWrap::GetCurrentStartTime()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetCurrentStartTime();
		}

		return Nullable<DateTime>();
	}

	int CScheduleMeetingItemDotNetWrap::GetDurationInMinutes()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetDurationInMinutes();
		}

		return 0;
	}

	bool CScheduleMeetingItemDotNetWrap::IsRecurringMeetingSelected()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsRecurringMeetingSelected();
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsHostVideoOnOrOff()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsHostVideoOnOrOff();
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsAttendeeVideoOnOrOff()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsAttendeeVideoOnOrOff();
		}

		return false;
	}

	SDKError CScheduleMeetingItemDotNetWrap::GetSelectedAudioType(ScheduleAudioType% type)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetSelectedAudioType(type);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	IQueryMeetingItemTelAudioInfoHelperDotNetWrap^ CScheduleMeetingItemDotNetWrap::GetQueryTelAudioInfoHelper()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetQueryTelAudioInfoHelper();
		}

		return nullptr;
	}

	String^ CScheduleMeetingItemDotNetWrap::GetMeetingTopic()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetMeetingTopic();
		}

		return nullptr;
	}

	bool CScheduleMeetingItemDotNetWrap::IsMeetingPasswordEnabled(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsMeetingPasswordEnabled(canChange);
		}

		return false;
	}

	String^ CScheduleMeetingItemDotNetWrap::GetMeetingPassword()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetMeetingPassword();
		}

		return nullptr;
	}

	bool CScheduleMeetingItemDotNetWrap::IsJoinBeforeHostEnabled(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsJoinBeforeHostEnabled(canChange);
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsMuteUponEntryEnabled(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsMuteUponEntryEnabled(canChange);
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsScheduleWithPmiEnabled(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsScheduleWithPmiEnabled(canChange);
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsOnlySignedInUserCanJoinEnabled(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsOnlySignedInUserCanJoinEnabled(canChange);
		}

		return false;
	}

	String^ CScheduleMeetingItemDotNetWrap::GetSpecifiedDomainCanJoin(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetSpecifiedDomainCanJoin(canChange);
		}

		return nullptr;
	}

	bool CScheduleMeetingItemDotNetWrap::IsHostInChinaEnabled(bool& canChange)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsHostInChinaEnabled(canChange);
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsAutoRecordEnabled(bool& canChange, int& supportRecordType)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsAutoRecordEnabled(canChange, supportRecordType);
		}

		return false;
	}

	ScheduleRecordType CScheduleMeetingItemDotNetWrap::GetSelectedAutoRecordType()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetSelectedAutoRecordType();
		}

		return ScheduleRecordType::ScheduleRecordType_None;
	}

	IQueryMeetingItemScheduleForHelperDotNetWrap^ CScheduleMeetingItemDotNetWrap::GetQueryScheduleForHelper()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetQueryScheduleForHelper();
		}

		return nullptr;
	}

	unsigned __int64 CScheduleMeetingItemDotNetWrap::GetUniqueMeetingId()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetUniqueMeetingId();
		}

		return 0;
	}

	unsigned __int64 CScheduleMeetingItemDotNetWrap::GetMeetingId()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetMeetingId();
		}

		return 0;
	}

	bool CScheduleMeetingItemDotNetWrap::IsPMI()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsPMI();
		}

		return false;
	}

	bool CScheduleMeetingItemDotNetWrap::IsWebinar()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->IsWebinar();
		}

		return false;
	}

	String^ CScheduleMeetingItemDotNetWrap::GetInviteEmailContent()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetInviteEmailContent();
		}

		return nullptr;
	}

	String^ CScheduleMeetingItemDotNetWrap::GetInviteEmailSubject()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetInviteEmailSubject();
		}

		return nullptr;
	}

	String^ CScheduleMeetingItemDotNetWrap::GetJoinMeetingUrl()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetJoinMeetingUrl();
		}

		return nullptr;
	}
}

