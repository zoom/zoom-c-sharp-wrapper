#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingRemoteController* InitIMeetingRemoteControllerFunc(IMeetingRemoteCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingRemoteControllerFunc(IMeetingRemoteController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingRemoteController, IMeetingRemoteCtrlEvent)
NORMAL_CLASS(IMeetingRemoteController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingRemoteController, IMeetingServiceWrap)

//virtual SDKError RequestRemoteControl(unsigned int userId) = 0;
DEFINE_FUNC_1(RequestRemoteControl, SDKError, unsigned int, userId)
//virtual SDKError GiveupRemoteControl(unsigned int userId) = 0;
DEFINE_FUNC_1(GiveupRemoteControl, SDKError, unsigned int, userId)
//virtual SDKError GiveRemoteControlTo(unsigned int userId) = 0;
DEFINE_FUNC_1(GiveRemoteControlTo, SDKError, unsigned int, userId)
//virtual SDKError DeclineRemoteControlRequest(unsigned int userId) = 0;
DEFINE_FUNC_1(DeclineRemoteControlRequest, SDKError, unsigned int, userId)
//virtual SDKError RevokeRemoteControl() = 0;
DEFINE_FUNC_0(RevokeRemoteControl, SDKError)
//virtual SDKError GetCurrentRemoteController(unsigned int& userId) = 0;
DEFINE_FUNC_1(GetCurrentRemoteController, SDKError, unsigned int&, userId)

//virtual void onRemoteControlStatus(RemoteControlStatus status, unsigned int userId) = 0;
CallBack_FUNC_2(onRemoteControlStatus, RemoteControlStatus, status, unsigned int, userId)

END_CLASS_DEFINE(IMeetingRemoteController)
END_ZOOM_SDK_NAMESPACE