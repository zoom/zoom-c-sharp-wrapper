#include "meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IMeetingService* InitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingServiceEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::IMeetingService* pObj(NULL);
	CSDKImpl::GetInst().CreateMeetingService(&pObj);
	if (pObj)
	{
		pObj->SetEvent(pEvent);
	}
	return pObj;
}
void UninitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingService* obj)
{
	CSDKImpl::GetInst().DestroyMeetingService(obj);
}

	IMPL_FUNC_1(IMeetingService, Join, SDKError, JoinParam&, joinParam, SDKERR_UNINITIALIZE);
	IMPL_FUNC_1(IMeetingService, Start, SDKError, StartParam&, startParam, SDKERR_UNINITIALIZE);
	IMPL_FUNC_1(IMeetingService, Leave, SDKError, LeaveMeetingCmd, leaveCmd, SDKERR_UNINITIALIZE);
	IMPL_FUNC_0(IMeetingService, GetMeetingStatus, MeetingStatus, MEETING_STATUS_IDLE);
	IMPL_FUNC_0(IMeetingService, LockMeeting, SDKError, SDKERR_UNINITIALIZE);
	IMPL_FUNC_0(IMeetingService, UnlockMeeting, SDKError, SDKERR_UNINITIALIZE);
	IMPL_FUNC_0(IMeetingService, GetMeetingInfo, IMeetingInfo*, NULL);
	IMPL_FUNC_0(IMeetingService, GetMeetingConnQuality, ConnectionQuality,Conn_Quality_Unknow);
	IMPL_FUNC_0(IMeetingService, GetVideoConnQuality, ConnectionQuality,Conn_Quality_Unknow);
	IMPL_FUNC_0(IMeetingService, GetAudioConnQuality, ConnectionQuality,Conn_Quality_Unknow);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingConfiguration, IMeetingConfigurationWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetUIController, IMeetingUIControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetAnnotationController, IAnnotationControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingVideoController, IMeetingVideoControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingRemoteController, IMeetingRemoteControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingShareController, IMeetingShareControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingAudioController, IMeetingAudioControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingRecordingController, IMeetingRecordingControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingChatController, IMeetingChatControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingWaitingRoomController, IMeetingWaitingRoomControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetH323Helper, IMeetingH323HelperWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingPhoneHelper, IMeetingPhoneHelperWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingBreakoutRoomsController, IMeetingBreakoutRoomsControllerWrap);
	IMPL_FUNC_AND_MEMBER(IMeetingService, GetMeetingParticipantsController, IMeetingParticipantsControllerWrap);
END_ZOOM_SDK_NAMESPACE