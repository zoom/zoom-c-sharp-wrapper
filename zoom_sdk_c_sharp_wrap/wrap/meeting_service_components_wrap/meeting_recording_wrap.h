#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingRecordingController* InitIMeetingRecordingControllerFunc(IMeetingRecordingCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingRecordingControllerFunc(IMeetingRecordingController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingRecordingController, IMeetingRecordingCtrlEvent)
NORMAL_CLASS(IMeetingRecordingController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingRecordingController, IMeetingServiceWrap)

//virtual SDKError StartRecording(time_t& startTimestamp, wchar_t* recPath) = 0;
DEFINE_FUNC_2(StartRecording, SDKError, time_t&, startTimestamp, wchar_t*, recPath)
//virtual SDKError StopRecording(time_t& stopTimestamp) = 0;
DEFINE_FUNC_1(StopRecording, SDKError, time_t&, stopTimestamp)

//virtual void onRecording2MP4Done(bool bsuccess, int iResult, const wchar_t* szPath) = 0;
CallBack_FUNC_3(onRecording2MP4Done, bool, bsuccess, int, iResult, const wchar_t*, szPath)
//virtual void onRecording2MP4Processing(int iPercentage) = 0;
CallBack_FUNC_1(onRecording2MP4Processing, int, iPercentage)
//virtual void onRecordingStatus(RecordingStatus status) = 0;
CallBack_FUNC_1(onRecordingStatus, RecordingStatus, status)
//virtual void onRecordPriviligeChanged(bool bCanRec) = 0;
CallBack_FUNC_1(onRecordPriviligeChanged, bool, bCanRec)
END_CLASS_DEFINE(IMeetingRecordingController)
END_ZOOM_SDK_NAMESPACE