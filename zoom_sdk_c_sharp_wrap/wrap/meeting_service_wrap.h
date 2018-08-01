#pragma once
#include "common_include.h"
#include "meeting_service_components_wrap/meeting_configuration_wrap.h"
#include "meeting_service_components_wrap/meeting_ui_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_annotation_wrap.h"
#include "meeting_service_components_wrap/meeting_video_wrap.h"
#include "meeting_service_components_wrap/meeting_remote_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_sharing_wrap.h"
#include "meeting_service_components_wrap/meeting_audio_wrap.h"
#include "meeting_service_components_wrap/meeting_recording_wrap.h"
#include "meeting_service_components_wrap/meeting_chat_wrap.h"
#include "meeting_service_components_wrap/meeting_waiting_room_wrap.h"
#include "meeting_service_components_wrap/meeting_h323_helper_wrap.h"
#include "meeting_service_components_wrap/meeting_phone_helper_wrap.h"
#include "meeting_service_components_wrap/meeting_breakout_rooms_wrap.h"
#include "meeting_service_components_wrap/meeting_participants_ctrl_wrap.h"

BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IMeetingService* InitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingServiceEvent* pEvent);
void UninitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingService* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingService, IMeetingServiceEvent)
STAITC_CLASS(IMeetingService)
INIT_UNINIT_WITHEVENT(IMeetingService)
//virtual SDKError Join(JoinParam& joinParam) = 0;
DEFINE_FUNC_1(Join, SDKError, JoinParam&, joinParam)
//virtual SDKError Start(StartParam& startParam) = 0;
DEFINE_FUNC_1(Start, SDKError, StartParam&, startParam)
//virtual SDKError Leave(LeaveMeetingCmd leaveCmd) = 0;
DEFINE_FUNC_1(Leave, SDKError, LeaveMeetingCmd, leaveCmd)
//virtual MeetingStatus GetMeetingStatus() = 0;
DEFINE_FUNC_0(GetMeetingStatus, MeetingStatus)
//virtual SDKError LockMeeting() = 0;
DEFINE_FUNC_0(LockMeeting, SDKError)
//virtual SDKError UnlockMeeting() = 0;
DEFINE_FUNC_0(UnlockMeeting, SDKError)
//virtual bool IsMeetingLocked() = 0;
DEFINE_FUNC_0(IsMeetingLocked, bool)
//virtual IMeetingInfo* GetMeetingInfo() = 0;
DEFINE_FUNC_0(GetMeetingInfo, IMeetingInfo*)
//virtual ConnectionQuality GetMeetingConnQuality() = 0;
DEFINE_FUNC_0(GetSharingConnQuality, ConnectionQuality)
//virtual ConnectionQuality GetVideoConnQuality() = 0;
DEFINE_FUNC_0(GetVideoConnQuality, ConnectionQuality)
//virtual ConnectionQuality GetAudioConnQuality() = 0;
DEFINE_FUNC_0(GetAudioConnQuality, ConnectionQuality)

DEFINE_FUNC_AND_MEMBER(GetMeetingConfiguration, IMeetingConfigurationWrap)
DEFINE_FUNC_AND_MEMBER(GetUIController, IMeetingUIControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetAnnotationController, IAnnotationControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingVideoController, IMeetingVideoControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingRemoteController, IMeetingRemoteControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingShareController, IMeetingShareControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingAudioController, IMeetingAudioControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingRecordingController, IMeetingRecordingControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingChatController, IMeetingChatControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingWaitingRoomController, IMeetingWaitingRoomControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetH323Helper, IMeetingH323HelperWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingPhoneHelper, IMeetingPhoneHelperWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingBreakoutRoomsController, IMeetingBreakoutRoomsControllerWrap)
DEFINE_FUNC_AND_MEMBER(GetMeetingParticipantsController, IMeetingParticipantsControllerWrap)

//virtual void onMeetingStatusChanged(MeetingStatus status, int iResult = 0) = 0;
CallBack_FUNC_2(onMeetingStatusChanged, MeetingStatus, status, int, iResult)

//virtual void onMeetingSecureKeyNotification(const char* key, int len, IMeetingExternalSecureKeyHandler* pHandler) = 0;
CallBack_FUNC_3(onMeetingSecureKeyNotification, const char*, key, int, len, IMeetingExternalSecureKeyHandler*, pHandler)

/// \brief Meeting statistics warning notification callback
/// \param type The type of meeting statistics warning.
//virtual void onMeetingStatisticsWarningNotification(StatisticsWarningType type) = 0;
CallBack_FUNC_1(onMeetingStatisticsWarningNotification, StatisticsWarningType, type)
//virtual void onMeetingParameterNotification(const MeetingParameter* meeting_param) = 0;
CallBack_FUNC_1(onMeetingParameterNotification, const MeetingParameter*, meeting_param)

END_CLASS_DEFINE(IMeetingService)
END_ZOOM_SDK_NAMESPACE