#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingParticipantsController* InitIMeetingParticipantsControllerFunc(IMeetingParticipantsCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingParticipantsControllerFunc(IMeetingParticipantsController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingParticipantsController, IMeetingParticipantsCtrlEvent)
NORMAL_CLASS(IMeetingParticipantsController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingParticipantsController, IMeetingServiceWrap)

//virtual IList<unsigned int >* GetParticipantsList() = 0;
DEFINE_FUNC_0(GetParticipantsList, IList<unsigned int >*)
//virtual IUserInfo* GetUserByUserID(unsigned int userid) = 0;
DEFINE_FUNC_1(GetUserByUserID, IUserInfo*, unsigned int, userid)
//virtual SDKError LowerAllHands() = 0;
DEFINE_FUNC_0(LowerAllHands, SDKError)
//virtual SDKError ChangeUserName(const unsigned int userid, const wchar_t* userName, bool bSaveUserName) = 0;
DEFINE_FUNC_3(ChangeUserName, SDKError, const unsigned int, userid, const wchar_t*, userName, bool, bSaveUserName)

//virtual void onUserJoin(IList<unsigned int >* lstUserID, const wchar_t* strUserList = NULL) = 0;
CallBack_FUNC_2(onUserJoin, IList<unsigned int >*, lstUserID, const wchar_t*, strUserList)
//virtual void onUserLeft(IList<unsigned int >* lstUserID, const wchar_t* strUserList = NULL) = 0;
CallBack_FUNC_2(onUserLeft, IList<unsigned int >*, lstUserID, const wchar_t*, strUserList)
//virtual void onHostChangeNotification(unsigned int userId) = 0;
CallBack_FUNC_1(onHostChangeNotification, unsigned int, userId)
//virtual void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userid) = 0;
CallBack_FUNC_2(onLowOrRaiseHandStatusChanged, bool, bLow, unsigned int, userid)
//virtual void onUserNameChanged(unsigned int userId, const wchar_t* userName) = 0;
CallBack_FUNC_2(onUserNameChanged, unsigned int, userId, const wchar_t*, userName)
END_CLASS_DEFINE(IMeetingParticipantsController)
END_ZOOM_SDK_NAMESPACE