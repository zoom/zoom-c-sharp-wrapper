#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "meeting_configuration_dotnet_wrap.h"
#include "meeting_ui_ctrl_dotnet_wrap.h"
#include "meeting_annotation_dotnet_wrap.h"
#include "meeting_video_dotnet_wrap.h"
#include "meeting_remote_ctrl_dotnet_wrap.h"
#include "meeting_sharing_dotnet_wrap.h"
#include "meeting_audio_dotnet_wrap.h"
#include "meeting_recording_dotnet_wrap.h"
#include "meeting_chat_dotnet_wrap.h"
#include "meeting_waiting_room_dotnet_wrap.h"
#include "meeting_h323_helper_dotnet_wrap.h"
#include "meeting_phone_helper_donet_wrap.h"
#include "meeting_breakout_rooms_dotnet_wrap.h"
#include "meeting_participants_ctrl_donet_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {
	public enum class MeetingStatus : int
	{
		MEETING_STATUS_IDLE,///< Idle status, no meeting running
		MEETING_STATUS_CONNECTING,///< Connecting meeting server status
		MEETING_STATUS_WAITINGFORHOST,///< Waiting for host to start meeting
		MEETING_STATUS_INMEETING,///< Meeting is ready, in meeting status
		MEETING_STATUS_DISCONNECTING,///< Disconnecting meeting server status
		MEETING_STATUS_RECONNECTING,///< Reconnecting meeting server status
		MEETING_STATUS_FAILED,///< Meeting connection error
		MEETING_STATUS_ENDED,///< Meeting is ended
		MEETING_STATUS_UNKNOW,
		MEETING_STATUS_LOCKED,
		MEETING_STATUS_UNLOCKED,
		MEETING_STATUS_IN_WAITING_ROOM,
		MEETING_STATUS_WEBINAR_PROMOTE,
		MEETING_STATUS_WEBINAR_DEPROMOTE,
		MEETING_STATUS_JOIN_BREAKOUT_ROOM,
		MEETING_STATUS_LEAVE_BREAKOUT_ROOM,
		MEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY,
	};

	public enum class MeetingFailCode : int
	{
		MEETING_SUCCESS = 0,
		MEETING_FAIL_NETWORK_ERR = 1,
		MEETING_FAIL_RECONNECT_ERR = 2,
		MEETING_FAIL_MMR_ERR = 3,
		MEETING_FAIL_PASSWORD_ERR = 4,
		MEETING_FAIL_SESSION_ERR = 5,
		MEETING_FAIL_MEETING_OVER = 6,
		MEETING_FAIL_MEETING_NOT_START = 7,
		MEETING_FAIL_MEETING_NOT_EXIST = 8,
		MEETING_FAIL_MEETING_USER_FULL = 9,
		MEETING_FAIL_CLIENT_INCOMPATIBLE = 10,///< RESULT_ZC_INCOMPATIBLE
		MEETING_FAIL_NO_MMR = 11,
		MEETING_FAIL_CONFLOCKED = 12,
		MEETING_FAIL_MEETING_RESTRICTED = 13,
		MEETING_FAIL_MEETING_RESTRICTED_JBH = 14,
		MEETING_FAIL_CANNOT_EMIT_WEBREQUEST = 15,
		MEETING_FAIL_CANNOT_START_TOKENEXPIRE = 16,
		SESSION_VIDEO_ERR = 17,
		SESSION_AUDIO_AUTOSTARTERR = 18,
		MEETING_FAIL_REGISTERWEBINAR_FULL = 19,
		MEETING_FAIL_REGISTERWEBINAR_HOSTREGISTER = 20,
		MEETING_FAIL_REGISTERWEBINAR_PANELISTREGISTER = 21,
		MEETING_FAIL_REGISTERWEBINAR_DENIED_EMAIL = 22,
		MEETING_FAIL_ENFORCE_LOGIN = 23,
		MEETING_FAIL_WRITE_CONFIG_FILE = 50,	///< Failed to write configure file
		MEETING_FAIL_FORBID_TO_JOIN_INTERNAL_MEETING = 60,
	};

	public enum class MeetingType : int
	{
		MEETING_TYPE_NONE,
		MEETING_TYPE_NORMAL,
		MEETING_TYPE_WEBINAR,
		MEETING_TYPE_BREAKOUTROOM,
	};

	public enum class LeaveMeetingCmd : int
	{
		LEAVE_MEETING,///< Leave meeting
		END_MEETING,///< End meeting
	};

	public enum class SDKUserType : int
	{
		SDK_UT_APIUSER = 99,///< API User type
		SDK_UT_NORMALUSER = 100,///< Normal user type
		SDK_UT_WITHOUT_LOGIN = 101, ////< start meeting with out login
	};

	public value class JoinParam4APIUser sealed
	{
	public:
		unsigned __int64	meetingNumber;///< Meeting's number
		String^				vanityID;///< Meeting's vanityID
		String^				userName;///< User Name in meeting
		String^				psw;///< Meeting's password
		HWNDDotNet			hDirectShareAppWnd;///< share application directly
		String^				toke4enfrocelogin;///< enforce login when join meeting
		String^				participantId;///< for meeting participant report list, need web backend enable.
		String^				webinarToken;///< webinar token.
		bool				isDirectShareDesktop;///< share desktop directly
		bool				isVideoOff;
		bool				isAudioOff;
	};

	public value class JoinParam4WithoutLogin sealed
	{
	public:
		unsigned __int64	meetingNumber;///< Meeting's number
		String^				vanityID;///< Meeting's vanityID
		String^				userName;///< User Name in meeting
		String^				psw;///< Meeting's password
		HWNDDotNet			hDirectShareAppWnd;///< share application directly
		String^				toke4enfrocelogin;///< enforce login when join meeting
		String^				participantId;///< for meeting participant report list, need web backend enable.
		String^				webinarToken;///< webinar token.
		bool				isDirectShareDesktop;///< share desktop directly
		bool				isVideoOff;
		bool				isAudioOff;
	};

	public value class JoinParam4NormalUser sealed
	{
	public:
		unsigned __int64	meetingNumber;///< Meeting's number
		String^				vanityID;///< Meeting's vanityID
		String^				userName;///< User Name in meeting
		String^				psw;///< Meeting's password
		HWNDDotNet			hDirectShareAppWnd;///< share application directly
		String^				participantId;///< for meeting participant report list, need web backend enable.
		String^				webinarToken;///< webinar token.
		bool				isVideoOff;
		bool				isAudioOff;
		bool				isDirectShareDesktop;///< share desktop directly
	};

	public value class JoinParam sealed
	{
	public:
		SDKUserType userType;///< User type
		JoinParam4APIUser^ apiuserJoin;
		JoinParam4NormalUser^ normaluserJoin;
		JoinParam4WithoutLogin^ withoutloginJoin;
	};

	public value class StartParam4APIUser sealed
	{
	public:
		String^				userID;///< User Id
		String^				userToken;///< User token
		String^				userName;///< User name
		unsigned __int64	meetingNumber;///< Meeting's number
		String^				vanityID;///< Meeting's vanityID
		HWNDDotNet			hDirectShareAppWnd;///< share application directly
		String^				participantId;///< for meeting participant report list, need web backend enable.
		bool				isDirectShareDesktop;///< share desktop directly
	};

	public value class StartParam4NormalUser sealed
	{
	public:
		unsigned __int64	meetingNumber;///< Meeting's number
		String^				vanityID;///< Meeting's vanityID
		HWNDDotNet			hDirectShareAppWnd;///< share application directly
		String^				participantId;///< for meeting participant report list, need web backend enable.
		bool				isVideoOff;///< only instance meeting take effect
		bool				isAudioOff;///< only instance meeting take effect
		bool				isDirectShareDesktop;///< share desktop directly
	};


	public enum class ZoomUserType : int
	{
		ZoomUserType_APIUSER = 0,
		ZoomUserType_EMAIL_LOGIN = 1,
		ZoomUserType_FACEBOOK = 2,
		ZoomUserType_GoogleOAuth = 3,
		ZoomUserType_SSO = 4,
		ZoomUserType_Unknown = 5,
	};

	public value class StartParam4WithoutLogin sealed
	{
	public:
		String^				userID;///< User Id
		String^				userToken;///< User token
		String^				userZAK;///< zoom access token
		String^				userName;///< User name
		ZoomUserType		zoomuserType;
		UINT64				meetingNumber;///< Meeting's number
		String^				vanityID;///< Meeting's vanityID
		HWNDDotNet			hDirectShareAppWnd;///< share application directly
		String^				participantId;///< for meeting participant report list, need web backend enable.
		bool				isDirectShareDesktop;///< share desktop directly
	};

	public value class StartParam sealed
	{
	public:
		SDKUserType userType;///< User type
		StartParam4APIUser^ apiuserStart;
		StartParam4NormalUser^ normaluserStart;
		StartParam4WithoutLogin^ withoutloginStart;
	};

	
	public enum class ConnectionQuality : int
	{
		Conn_Quality_Unknow,
		Conn_Quality_Very_Bad,
		Conn_Quality_Bad,
		Conn_Quality_Not_Good,
		Conn_Quality_Normal,
		Conn_Quality_Good,
		Conn_Quality_Excellent,
	};

	public enum class MeetingConnType : int
	{
		Meeting_Conn_None,
		Meeting_Conn_Normal,
		Meeting_Conn_FailOver,
	};

	public interface class IMeetingInfo
	{
	public:
		unsigned __int64 GetMeetingNumber();
		String^ GetMeetingID();
		String^ GetMeetingTopic();
		MeetingType GetMeetingType();
		String^ GetInviteEmailTeamplate();
		String^ GetInviteEmailTitle();
		String^ GetJoinMeetingUrl();
		String^ GetMeetingHostTag();
		bool IsInternalMeeting();
		MeetingConnType GetMeetingConnType();
	};

	public interface class IMeetingExternalSecureKeyHandler
	{
	public:
		void SetChatSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len);
		void SetFileTransferSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len);
		void SetAudioSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len);
		void SetVideoSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len);
		void SetShareSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len);
		void Cancel();
		void Confirm();
	};

	public enum class StatisticsWarningType : int
	{
		Statistics_Warning_None,
		Statistics_Warning_Network_Quality_Bad,
	};

	public delegate void onMeetingStatusChanged(MeetingStatus status, int iResult);
	public delegate void onMeetingStatisticsWarningNotification(StatisticsWarningType type);
	public delegate void onMeetingSecureKeyNotification(array<Byte >^ key, int len, IMeetingExternalSecureKeyHandler^ pHandler);

	public interface class IMeetingServiceDotNetWrap
	{
	public:
		SDKError Join(JoinParam joinParam);
		SDKError Start(StartParam startParam);
		SDKError Leave(LeaveMeetingCmd leaveCmd);
		MeetingStatus GetMeetingStatus();
		SDKError LockMeeting();
		SDKError UnlockMeeting();
		bool IsMeetingLocked();
		IMeetingInfo^ GetMeetingInfo();
		ConnectionQuality GetSharingConnQuality();
		ConnectionQuality GetVideoConnQuality();
		ConnectionQuality GetAudioConnQuality();
		IMeetingConfigurationDotNetWrap^ GetMeetingConfiguration();
		IMeetingUIControllerDotNetWrap^ GetUIController();
		IAnnotationControllerDotNetWrap^ GetAnnotationController();
		IMeetingVideoControllerDotNetWrap^ GetMeetingVideoController();
		IMeetingRemoteControllerDotNetWrap^ GetMeetingRemoteController();
		IMeetingShareControllerDotNetWrap^ GetMeetingShareController();
		IMeetingAudioControllerDotNetWrap^ GetMeetingAudioController();
		IMeetingRecordingControllerDotNetWrap^ GetMeetingRecordingController();
		IMeetingChatControllerDotNetWrap^ GetMeetingChatController();
		IMeetingWaitingRoomControllerDotNetWrap^ GetMeetingWaitingRoomController();
		IMeetingH323HelperDotNetWrap^ GetH323Helper();
		IMeetingPhoneHelperDotNetWrap^ GetMeetingPhoneHelper();
		IMeetingBreakoutRoomsControllerDotNetWrap^ GetMeetingBreakoutRoomsController();
		IMeetingParticipantsControllerDotNetWrap^ GetMeetingParticipantsController();

		void Add_CB_onMeetingStatusChanged(onMeetingStatusChanged^ cb);
		void Add_CB_onMeetingStatisticsWarningNotification(onMeetingStatisticsWarningNotification^ cb);
		void Add_CB_onMeetingSecureKeyNotification(onMeetingSecureKeyNotification^ cb);
	};
	private ref class CMeetingServiceDotNetWrap sealed : public IMeetingServiceDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
		static property CMeetingServiceDotNetWrap^ Instance
		{
			CMeetingServiceDotNetWrap^ get() { return m_Instance; }
		}

		//
		void BindEvent();
		void ProcMeetingStatusChanged(MeetingStatus status, int iResult);
		void ProcMeetingStatisticsWarningNotification(StatisticsWarningType type);
		void ProcMeetingSecureKeyNotification(array<Byte >^ key, int len, IMeetingExternalSecureKeyHandler^ pHandler);

		//
		virtual SDKError Join(JoinParam joinParam);
		virtual SDKError Start(StartParam startParam);
		virtual SDKError Leave(LeaveMeetingCmd leaveCmd);
		virtual MeetingStatus GetMeetingStatus();
		virtual SDKError LockMeeting();
		virtual SDKError UnlockMeeting();
		virtual bool IsMeetingLocked();
		virtual IMeetingInfo^ GetMeetingInfo();
		virtual ConnectionQuality GetSharingConnQuality();
		virtual ConnectionQuality GetVideoConnQuality();
		virtual ConnectionQuality GetAudioConnQuality();
		virtual IMeetingConfigurationDotNetWrap^ GetMeetingConfiguration();
		virtual IMeetingUIControllerDotNetWrap^ GetUIController();
		virtual IAnnotationControllerDotNetWrap^ GetAnnotationController();
		virtual IMeetingVideoControllerDotNetWrap^ GetMeetingVideoController();
		virtual IMeetingRemoteControllerDotNetWrap^ GetMeetingRemoteController();
		virtual IMeetingShareControllerDotNetWrap^ GetMeetingShareController();
		virtual IMeetingAudioControllerDotNetWrap^ GetMeetingAudioController();
		virtual IMeetingRecordingControllerDotNetWrap^ GetMeetingRecordingController();
		virtual IMeetingChatControllerDotNetWrap^ GetMeetingChatController();
		virtual IMeetingWaitingRoomControllerDotNetWrap^ GetMeetingWaitingRoomController();
		virtual IMeetingH323HelperDotNetWrap^ GetH323Helper();
		virtual IMeetingPhoneHelperDotNetWrap^ GetMeetingPhoneHelper();
		virtual IMeetingBreakoutRoomsControllerDotNetWrap^ GetMeetingBreakoutRoomsController();
		virtual IMeetingParticipantsControllerDotNetWrap^ GetMeetingParticipantsController();

		virtual void Add_CB_onMeetingStatusChanged(onMeetingStatusChanged^ cb)
		{
			event_onMeetingStatusChanged += cb;
		}

		virtual void Add_CB_onMeetingStatisticsWarningNotification(onMeetingStatisticsWarningNotification^ cb)
		{
			event_onMeetingStatisticsWarningNotification += cb;
		}

		virtual void Add_CB_onMeetingSecureKeyNotification(onMeetingSecureKeyNotification^ cb)
		{
			event_onMeetingSecureKeyNotification += cb;
		}

	private:
		CMeetingServiceDotNetWrap();
		virtual ~CMeetingServiceDotNetWrap();
		event onMeetingStatusChanged^ event_onMeetingStatusChanged;
		event onMeetingStatisticsWarningNotification^ event_onMeetingStatisticsWarningNotification;
		event onMeetingSecureKeyNotification^ event_onMeetingSecureKeyNotification;

		static CMeetingServiceDotNetWrap^ m_Instance = gcnew CMeetingServiceDotNetWrap;
	};
}