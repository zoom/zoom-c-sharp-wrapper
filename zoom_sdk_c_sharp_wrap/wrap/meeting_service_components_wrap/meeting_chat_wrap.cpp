#include "meeting_chat_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingChatController* InitIMeetingChatControllerFunc(IMeetingChatCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingChatController* pObj = pOwner->GetSDKObj()->GetMeetingChatController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingChatControllerFunc(IMeetingChatController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError SendChatTo(unsigned int receiver, wchar_t* content) = 0;
IMPL_FUNC_2(IMeetingChatController, SendChatTo, SDKError, unsigned int, receiver, wchar_t*, content, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE