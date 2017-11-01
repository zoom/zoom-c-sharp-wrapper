#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingChatController* InitIMeetingChatControllerFunc(IMeetingChatCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingChatControllerFunc(IMeetingChatController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingChatController, IMeetingChatCtrlEvent)
NORMAL_CLASS(IMeetingChatController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingChatController, IMeetingServiceWrap)

//virtual SDKError SendChatTo(unsigned int receiver, wchar_t* content) = 0;
DEFINE_FUNC_2(SendChatTo, SDKError, unsigned int, receiver, wchar_t*, content)

//virtual void onChatMsgNotifcation(IChatMsgInfo* chatMsg, const wchar_t* content = NULL) = 0;
CallBack_FUNC_2(onChatMsgNotifcation, IChatMsgInfo*, chatMsg, const wchar_t*, content)
END_CLASS_DEFINE(IMeetingChatController)
END_ZOOM_SDK_NAMESPACE