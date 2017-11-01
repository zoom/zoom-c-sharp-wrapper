#include "meeting_participants_ctrl_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingParticipantsController* InitIMeetingParticipantsControllerFunc(IMeetingParticipantsCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingParticipantsController* pObj = pOwner->GetSDKObj()->GetMeetingParticipantsController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingParticipantsControllerFunc(IMeetingParticipantsController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual IList<unsigned int >* GetParticipantsList() = 0;
IMPL_FUNC_0(IMeetingParticipantsController, GetParticipantsList, IList<unsigned int >*, NULL)
//virtual IUserInfo* GetUserByUserID(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingParticipantsController, GetUserByUserID, IUserInfo*, unsigned int, userid, NULL)
//virtual SDKError LowerAllHands() = 0;
IMPL_FUNC_0(IMeetingParticipantsController, LowerAllHands, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ChangeUserName(const unsigned int userid, const wchar_t* userName, bool bSaveUserName) = 0;
IMPL_FUNC_3(IMeetingParticipantsController, ChangeUserName, SDKError, const unsigned int, userid, const wchar_t*, userName, bool, bSaveUserName, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE