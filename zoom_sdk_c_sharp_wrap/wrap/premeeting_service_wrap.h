#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IPreMeetingService* InitIPreMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IPreMeetingServiceEvent* pEvent);
void UninitIPreMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IPreMeetingService* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IPreMeetingService, IPreMeetingServiceEvent)
STAITC_CLASS(IPreMeetingService)
INIT_UNINIT_WITHEVENT(IPreMeetingService)
//virtual IScheduleMeetingItem* CreateScheduleMeetingItem() = 0;
DEFINE_FUNC_0(CreateScheduleMeetingItem, IScheduleMeetingItem*)
//virtual void DestoryScheduleMeetingItem(IScheduleMeetingItem* pMeeting) = 0;
DEFINE_FUNC_1(DestoryScheduleMeetingItem, void, IScheduleMeetingItem*, pMeeting)

//virtual IScheduleMeetingItem* CreateEditMeetingItem(UINT64 meetingUniqueID) = 0;
DEFINE_FUNC_1(CreateEditMeetingItem, IScheduleMeetingItem*, UINT64, meetingUniqueID)
//virtual void DestoryEditMeetingItem(IScheduleMeetingItem* pMeeting) = 0;
DEFINE_FUNC_1(DestoryEditMeetingItem, void, IScheduleMeetingItem*, pMeeting)
//virtual SDKError ScheduleMeeting(IScheduleMeetingItem* pItem) = 0;
DEFINE_FUNC_1(ScheduleMeeting, SDKError, IScheduleMeetingItem*, pItem)
//virtual SDKError ScheduleMeeting(WndPosition& wndParam) = 0;
DEFINE_FUNC_1(ScheduleMeeting, SDKError, WndPosition&, wndParam)
//virtual SDKError EditMeeting(IScheduleMeetingItem* pItem) = 0;
DEFINE_FUNC_1(EditMeeting, SDKError, IScheduleMeetingItem*, pItem)
//virtual SDKError EditMeeting(WndPosition& wndParam, UINT64 meetingUniqueID) = 0;
DEFINE_FUNC_2(EditMeeting, SDKError, WndPosition&, wndParam, UINT64, meetingUniqueID)
//virtual SDKError DeleteMeeting(UINT64 meetingUniqueID) = 0;
DEFINE_FUNC_1(DeleteMeeting, SDKError, UINT64, meetingUniqueID)
//virtual SDKError ListMeeting() = 0;
//virtual IMyMeetingItem* GetMeeingItem(UINT64 meetingUniqueID) = 0;
DEFINE_FUNC_1(GetMeeingItem, IMeetingItemInfo*, UINT64, meetingUniqueID)

//virtual void onListMeeting(PremeetingAPIResult result, IList<UINT64 >* lstMeetingList) = 0;
CallBack_FUNC_2(onListMeeting, PremeetingAPIResult, result, IList<UINT64 >*, lstMeetingList)
//virtual void onScheduleOrEditMeeting(PremeetingAPIResult result, UINT64 meetingUniqueID) = 0;
CallBack_FUNC_2(onScheduleOrEditMeeting, PremeetingAPIResult, result, UINT64, meetingUniqueID)
//virtual void onDeleteMeeting(PremeetingAPIResult result) = 0;
CallBack_FUNC_1(onDeleteMeeting, PremeetingAPIResult, result)
END_CLASS_DEFINE(IPreMeetingService)
END_ZOOM_SDK_NAMESPACE