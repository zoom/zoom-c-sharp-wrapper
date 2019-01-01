#include "stdafx.h"
#include "premeeting_service_dotnet_wrap.h"
#include "wrap/premeeting_service_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
#include "premeeting_service_dotnet_wrap_def.h"
#include "schedule_meeting_item_dotnet_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	// ---------------------------------------------------------
	// Translate IMeetingItemInfo
	//
	private ref class IMeetingItemInfoDotNetWrapImpl sealed : public IMeetingItemInfoDotNetWrap
	{
	public:
		IMeetingItemInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IMeetingItemInfo* pObj)
		{
			m_pSDKObj = pObj;
		}

		IMeetingItemInfoDotNetWrapImpl()
		{
			m_pSDKObj = NULL;
		}

		~IMeetingItemInfoDotNetWrapImpl()
		{
			if (m_pSDKObj)
			{
			}
		}

		ZOOM_SDK_NAMESPACE::IMeetingItemInfo* GetSDKObj()
		{
			return m_pSDKObj;
		}

		// ---------------------------------------------------------
		// IQueryMeetingItemDateInfoHelperDotNetWrap
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

		// ---------------------------------------------------------
		// IQueryMeetingItemVideoOptionHelperDotNetWrap
		//
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

		// ---------------------------------------------------------
		// IQueryMeetingItemAudioOptionHelperDotNetWrap
		//
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

		// ---------------------------------------------------------
		// IQueryMeetingItemMeetingOptionHelperDotNetWrap
		//
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

	private:
		ZOOM_SDK_NAMESPACE::IMeetingItemInfo* m_pSDKObj;
	};


	class PreMeetingServiceEventHandler
	{
	public:
		static PreMeetingServiceEventHandler& GetInst()
		{
			static PreMeetingServiceEventHandler instance;
			return instance;
		}

		void onListMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, ZOOM_SDK_NAMESPACE::IList<UINT64>* lstMeetings)
		{
			if (CPreMeetingServiceDotNetWrap::Instance)
			{
				CPreMeetingServiceDotNetWrap::Instance->ProcListMeeting((PreMeetingAPIResult)result, Convert(lstMeetings));
			}
		}

		void onScheduleOrEditMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, UINT64 meetingUniqueId)
		{
			if (CPreMeetingServiceDotNetWrap::Instance)
			{
				CPreMeetingServiceDotNetWrap::Instance->ProcScheduleOrEditMeeting((PreMeetingAPIResult)result, (unsigned __int64)meetingUniqueId);
			}
		}

		void onDeleteMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result)
		{
			if (CPreMeetingServiceDotNetWrap::Instance)
			{
				CPreMeetingServiceDotNetWrap::Instance->ProcDeleteMeeting((PreMeetingAPIResult)result);
			}
		}

	private:
		PreMeetingServiceEventHandler() {}
	};

	IScheduleMeetingItemDotNetWrap^ CPreMeetingServiceDotNetWrap::CreateScheduleMeetingItem()
	{
		IScheduleMeetingItemDotNetWrap^ item = nullptr;

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItem* pItem = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().CreateScheduleMeetingItem();
		if (pItem)
		{
			// Create the wrapper
			ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pObjWrap(NULL);
			pObjWrap = new ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap;
			if (pObjWrap)
			{
				// And initialize with the SDK object
				pObjWrap->Init(pItem);

				item = gcnew CScheduleMeetingItemDotNetWrap(pObjWrap);
			}
		}

		return item;
	}

	void CPreMeetingServiceDotNetWrap::DestoryScheduleMeetingItem(IScheduleMeetingItemDotNetWrap^ item)
	{
		if (item == nullptr || ((CScheduleMeetingItemDotNetWrap^)item)->Inner() == nullptr)
		{
			return;
		}

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pItem = ((CScheduleMeetingItemDotNetWrap^)item)->Inner()->GetSDKObj();
		if (pItem)
		{
			ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().DestoryScheduleMeetingItem(pItem->GetSDKObj());
		}
	}

	IScheduleMeetingItemDotNetWrap^ CPreMeetingServiceDotNetWrap::CreateEditMeetingItem(unsigned __int64 meetingUniqueId)
	{
		IScheduleMeetingItemDotNetWrap^ item = nullptr;

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItem* pItem = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().CreateEditMeetingItem(meetingUniqueId);
		if (pItem)
		{
			// Create the wrapper
			ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pObjWrap(NULL);
			pObjWrap = new ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap;
			if (pObjWrap)
			{
				// And initialize with the SDK object
				pObjWrap->Init(pItem);

				item = gcnew CScheduleMeetingItemDotNetWrap(pObjWrap);
			}
		}

		return item;
	}

	void CPreMeetingServiceDotNetWrap::DestoryEditMeetingItem(IScheduleMeetingItemDotNetWrap^ item)
	{
		if (item == nullptr || ((CScheduleMeetingItemDotNetWrap^)item)->Inner() == nullptr)
		{
			return;
		}

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pItem = ((CScheduleMeetingItemDotNetWrap^)item)->Inner()->GetSDKObj();
		if (pItem)
		{
			ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().DestoryEditMeetingItem(pItem->GetSDKObj());
		}
	}


	SDKError CPreMeetingServiceDotNetWrap::ScheduleMeeting(IScheduleMeetingItemDotNetWrap^ item)
	{
		if (item == nullptr || ((CScheduleMeetingItemDotNetWrap^)item)->Inner() == nullptr)
		{
			return SDKError::SDKERR_INVALID_PARAMETER;
		}

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pItem = ((CScheduleMeetingItemDotNetWrap^)item)->Inner()->GetSDKObj();
		if (pItem)
		{
			return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().ScheduleMeeting(pItem->GetSDKObj());
		}

		return SDKError::SDKERR_INVALID_PARAMETER;
	}

	SDKError CPreMeetingServiceDotNetWrap::ScheduleMeeting(WndPosition& pos)
	{
		ZOOM_SDK_NAMESPACE::WndPosition pos_c;
		pos_c.hParent = (HWND)pos.hParent.value;
		pos_c.hSelfWnd = (HWND)pos.hSelfWnd.value;
		pos_c.left = pos.left;
		pos_c.top = pos.top;
		
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().ScheduleMeeting(pos_c);
	}

	SDKError CPreMeetingServiceDotNetWrap::EditMeeting(IScheduleMeetingItemDotNetWrap^ item)
	{
		if (item == nullptr || ((CScheduleMeetingItemDotNetWrap^)item)->Inner() == nullptr)
		{
			return SDKError::SDKERR_INVALID_PARAMETER;
		}

		ZOOM_SDK_NAMESPACE::IScheduleMeetingItemWrap* pItem = ((CScheduleMeetingItemDotNetWrap^)item)->Inner()->GetSDKObj();
		if (pItem)
		{
			return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().EditMeeting(pItem->GetSDKObj());
		}

		return SDKError::SDKERR_INVALID_PARAMETER;
	}

	SDKError CPreMeetingServiceDotNetWrap::EditMeeting(WndPosition& pos, unsigned __int64 meetingUniqueId)
	{
		ZOOM_SDK_NAMESPACE::WndPosition pos_c;
		pos_c.hParent = (HWND)pos.hParent.value;
		pos_c.hSelfWnd = (HWND)pos.hSelfWnd.value;
		pos_c.left = pos.left;
		pos_c.top = pos.top;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().EditMeeting(pos_c, meetingUniqueId);
	}

	SDKError CPreMeetingServiceDotNetWrap::DeleteMeeting(unsigned __int64 meetingUniqueId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().DeleteMeeting(meetingUniqueId);
	}

	SDKError CPreMeetingServiceDotNetWrap::ListMeeting()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().ListMeeting();
	}

	IMeetingItemInfoDotNetWrap^ CPreMeetingServiceDotNetWrap::GetMeetingItem(unsigned __int64 meetingUniqueId)
	{
		ZOOM_SDK_NAMESPACE::IMeetingItemInfo* pItem = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().GetMeeingItem(meetingUniqueId);
		if (pItem)
		{
			return gcnew IMeetingItemInfoDotNetWrapImpl(pItem);
		}

		return nullptr;
	}

	void CPreMeetingServiceDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IPreMeetingServiceWrap& wrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap();

		wrap.m_cbonListMeeting =
			std::bind(&PreMeetingServiceEventHandler::onListMeeting,
				&PreMeetingServiceEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);

		wrap.m_cbonDeleteMeeting =
			std::bind(&PreMeetingServiceEventHandler::onDeleteMeeting,
				&PreMeetingServiceEventHandler::GetInst(), std::placeholders::_1);

		wrap.m_cbonScheduleOrEditMeeting =
			std::bind(&PreMeetingServiceEventHandler::onScheduleOrEditMeeting,
				&PreMeetingServiceEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	void CPreMeetingServiceDotNetWrap::ProcListMeeting(PreMeetingAPIResult result, array<unsigned __int64>^ lstMeetings)
	{
		event_onListMeeting(result, lstMeetings);
	}

	void CPreMeetingServiceDotNetWrap::ProcScheduleOrEditMeeting(PreMeetingAPIResult result, unsigned __int64 meetingUniqueId)
	{
		event_onScheduleOrEditMeeting(result, meetingUniqueId);
	}

	void CPreMeetingServiceDotNetWrap::ProcDeleteMeeting(PreMeetingAPIResult result)
	{
		event_onDeleteMeeting(result);
	}
}
