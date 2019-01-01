#pragma once

using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/premeeting_service_wrap.h"
#include "schedule_meeting_item_dotnet_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public delegate void onListMeeting(PreMeetingAPIResult result, array<unsigned __int64>^ lstMeetings);
	public delegate void onScheduleOrEditMeeting(PreMeetingAPIResult result, unsigned __int64 meetingUniqueId);
	public delegate void onDeleteMeeting(PreMeetingAPIResult result);

	public interface class IPreMeetingServiceDotNetWrap
	{
	public:
		IScheduleMeetingItemDotNetWrap^ CreateScheduleMeetingItem();
		void DestoryScheduleMeetingItem(IScheduleMeetingItemDotNetWrap^ pMeeting);
		IScheduleMeetingItemDotNetWrap^ CreateEditMeetingItem(unsigned __int64 meetingUniqueID);
		void DestoryEditMeetingItem(IScheduleMeetingItemDotNetWrap^ pMeeting);
		SDKError ScheduleMeeting(IScheduleMeetingItemDotNetWrap^ pItem);
		SDKError ScheduleMeeting(WndPosition& wndParam);
		SDKError EditMeeting(IScheduleMeetingItemDotNetWrap^ pItem);
		SDKError EditMeeting(WndPosition& wndParam, unsigned __int64 meetingUniqueID);
		SDKError DeleteMeeting(unsigned __int64 meetingUniqueID);
		SDKError ListMeeting();
		IMeetingItemInfoDotNetWrap^ GetMeetingItem(unsigned __int64 meetingUniqueID);

		void Add_CB_onListMeeting(onListMeeting^ cb);
		void Add_CB_onScheduleOrEditMeeting(onScheduleOrEditMeeting^ cb);
		void Add_CB_onDeleteMeeting(onDeleteMeeting^ cb);
		void Remove_CB_onListMeeting(onListMeeting^ cb);
		void Remove_CB_onScheduleOrEditMeeting(onScheduleOrEditMeeting^ cb);
		void Remove_CB_onDeleteMeeting(onDeleteMeeting^ cb);
	};

	private ref class CPreMeetingServiceDotNetWrap sealed : public IPreMeetingServiceDotNetWrap
	{
	public:
		static property CPreMeetingServiceDotNetWrap^ Instance
		{
			CPreMeetingServiceDotNetWrap^ get() { return m_Instance; }
		}

		virtual IScheduleMeetingItemDotNetWrap^ CreateScheduleMeetingItem();
		virtual void DestoryScheduleMeetingItem(IScheduleMeetingItemDotNetWrap^ pMeeting);
		virtual IScheduleMeetingItemDotNetWrap^ CreateEditMeetingItem(unsigned __int64 meetingUniqueID);
		virtual void DestoryEditMeetingItem(IScheduleMeetingItemDotNetWrap^ pMeeting);
		virtual SDKError ScheduleMeeting(IScheduleMeetingItemDotNetWrap^ pItem);
		virtual SDKError ScheduleMeeting(WndPosition& wndParam);
		virtual SDKError EditMeeting(IScheduleMeetingItemDotNetWrap^ pItem);
		virtual SDKError EditMeeting(WndPosition& wndParam, unsigned __int64 meetingUniqueID);
		virtual SDKError DeleteMeeting(unsigned __int64 meetingUniqueID);
		virtual SDKError ListMeeting();
		virtual IMeetingItemInfoDotNetWrap^ GetMeetingItem(unsigned __int64 meetingUniqueID);

		virtual void Add_CB_onListMeeting(onListMeeting^ cb)
		{
			event_onListMeeting += cb;
		}
		virtual void Remove_CB_onListMeeting(onListMeeting^ cb)
		{
			event_onListMeeting -= cb;
		}
		virtual void Add_CB_onScheduleOrEditMeeting(onScheduleOrEditMeeting^ cb)
		{
			event_onScheduleOrEditMeeting += cb;
		}
		virtual void Remove_CB_onScheduleOrEditMeeting(onScheduleOrEditMeeting^ cb)
		{
			event_onScheduleOrEditMeeting -= cb;
		}
		virtual void Add_CB_onDeleteMeeting(onDeleteMeeting^ cb)
		{
			event_onDeleteMeeting += cb;
		}
		virtual void Remove_CB_onDeleteMeeting(onDeleteMeeting^ cb)
		{
			event_onDeleteMeeting -= cb;
		}

		void BindEvent();
		void ProcListMeeting(PreMeetingAPIResult result, array<unsigned __int64>^ lstMeetings);
		void ProcScheduleOrEditMeeting(PreMeetingAPIResult result, unsigned __int64 meetingUniqueId);
		void ProcDeleteMeeting(PreMeetingAPIResult result);

	private:
		CPreMeetingServiceDotNetWrap() {};
		virtual ~CPreMeetingServiceDotNetWrap() {};
		event onListMeeting^ event_onListMeeting;
		event onScheduleOrEditMeeting^ event_onScheduleOrEditMeeting;
		event onDeleteMeeting^ event_onDeleteMeeting;
		static CPreMeetingServiceDotNetWrap^ m_Instance = gcnew CPreMeetingServiceDotNetWrap;
	};
}
