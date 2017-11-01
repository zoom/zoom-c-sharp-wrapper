#include "meeting_recording_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingRecordingController* InitIMeetingRecordingControllerFunc(IMeetingRecordingCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingRecordingController* pObj = pOwner->GetSDKObj()->GetMeetingRecordingController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingRecordingControllerFunc(IMeetingRecordingController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError StartRecording(time_t& startTimestamp, wchar_t* recPath) = 0;
IMPL_FUNC_2(IMeetingRecordingController, StartRecording, SDKError, time_t&, startTimestamp, wchar_t*, recPath, SDKERR_UNINITIALIZE)
//virtual SDKError StopRecording(time_t& stopTimestamp) = 0;
IMPL_FUNC_1(IMeetingRecordingController, StopRecording, SDKError, time_t&, stopTimestamp, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE