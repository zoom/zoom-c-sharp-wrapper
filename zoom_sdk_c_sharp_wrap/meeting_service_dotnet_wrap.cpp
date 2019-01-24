#include "stdafx.h"
#include "meeting_service_DotNet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate IMeetingExternalSecureKeyHandler
	private ref class IMeetingExternalSecureKeyHandlerImpl sealed: public IMeetingExternalSecureKeyHandler
	{
	public:
		IMeetingExternalSecureKeyHandlerImpl(ZOOM_SDK_NAMESPACE::IMeetingExternalSecureKeyHandler* pHandler)
		{
			m_pHandler = pHandler;
		}

		IMeetingExternalSecureKeyHandlerImpl()
		{
			m_pHandler = NULL;
		}
		~IMeetingExternalSecureKeyHandlerImpl()
		{

		}
		virtual void SetChatSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len)
		{
			if (m_pHandler)
			{
				PlatformBuffer2NativeBufferHelper key_c(key, key_len);
				int key_len_c = key_c.Data() ? key_len : 0;
				PlatformBuffer2NativeBufferHelper iv_c(iv, iv_len);
				int iv_len_c = iv_c.Data() ? iv_len : 0;
				m_pHandler->SetChatSessionKey(key_c.Data(), key_len_c, iv_c.Data(), iv_len_c);
			}
		}
		virtual void SetFileTransferSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len)
		{
			if (m_pHandler)
			{
				PlatformBuffer2NativeBufferHelper key_c(key, key_len);
				int key_len_c = key_c.Data() ? key_len : 0;
				PlatformBuffer2NativeBufferHelper iv_c(iv, iv_len);
				int iv_len_c = iv_c.Data() ? iv_len : 0;
				m_pHandler->SetFileTransferSessionKey(key_c.Data(), key_len_c, iv_c.Data(), iv_len_c);
			}
		}
		virtual void SetAudioSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len)
		{
			if (m_pHandler)
			{
				PlatformBuffer2NativeBufferHelper key_c(key, key_len);
				int key_len_c = key_c.Data() ? key_len : 0;
				PlatformBuffer2NativeBufferHelper iv_c(iv, iv_len);
				int iv_len_c = iv_c.Data() ? iv_len : 0;
				m_pHandler->SetAudioSessionKey(key_c.Data(), key_len_c, iv_c.Data(), iv_len_c);
			}
		}
		virtual void SetVideoSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len)
		{
			if (m_pHandler)
			{
				PlatformBuffer2NativeBufferHelper key_c(key, key_len);
				int key_len_c = key_c.Data() ? key_len : 0;
				PlatformBuffer2NativeBufferHelper iv_c(iv, iv_len);
				int iv_len_c = iv_c.Data() ? iv_len : 0;
				m_pHandler->SetVideoSessionKey(key_c.Data(), key_len_c, iv_c.Data(), iv_len_c);
			}
		}
		virtual void SetShareSessionKey(array<Byte >^ key, int key_len, array<Byte >^ iv, int iv_len)
		{
			if (m_pHandler)
			{
				PlatformBuffer2NativeBufferHelper key_c(key, key_len);
				int key_len_c = key_c.Data() ? key_len : 0;
				PlatformBuffer2NativeBufferHelper iv_c(iv, iv_len);
				int iv_len_c = iv_c.Data() ? iv_len : 0;
				m_pHandler->SetShareSessionKey(key_c.Data(), key_len_c, iv_c.Data(), iv_len_c);
			}
		}
		virtual void Cancel()
		{
			if (m_pHandler)
			{
				m_pHandler->Cancel();
			}
		}
		virtual void Confirm()
		{
			if (m_pHandler)
			{
				m_pHandler->Confirm();
			}
		}

	private:
		ZOOM_SDK_NAMESPACE::IMeetingExternalSecureKeyHandler* m_pHandler;
	};

	IMeetingExternalSecureKeyHandler^ TranslateMeetingExternalSecureKeyHandler(ZOOM_SDK_NAMESPACE::IMeetingExternalSecureKeyHandler* pHandler)
	{
		if (pHandler)
		{
			return gcnew IMeetingExternalSecureKeyHandlerImpl(pHandler);
		}
		return nullptr;
	}
	//

	//translate meeting info
	private ref class IMeetingInfoImpl sealed :public IMeetingInfo
	{
	public:
		IMeetingInfoImpl(ZOOM_SDK_NAMESPACE::IMeetingInfo* pInfo)
		{
			m_pInfo = pInfo;
		}

		IMeetingInfoImpl() { m_pInfo = NULL; }
		~IMeetingInfoImpl() {}

		virtual unsigned __int64 GetMeetingNumber()
		{
			if (m_pInfo)
				return m_pInfo->GetMeetingNumber();

			return 0;
		}
		virtual String^ GetMeetingID()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetMeetingID());

			return nullptr;
		}
		virtual String^ GetMeetingTopic()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetMeetingTopic());

			return nullptr;
		}
		virtual MeetingType GetMeetingType()
		{
			if (m_pInfo)
				return (MeetingType)m_pInfo->GetMeetingType();

			return MeetingType::MEETING_TYPE_NONE;
		}
		virtual String^ GetInviteEmailTeamplate()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetInviteEmailTeamplate());

			return nullptr;
		}
		virtual String^ GetInviteEmailTitle()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetInviteEmailTitle());

			return nullptr;
		}
		virtual String^ GetJoinMeetingUrl()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetJoinMeetingUrl());

			return nullptr;
		}
		virtual String^ GetMeetingHostTag()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetMeetingHostTag());

			return nullptr;
		}
		virtual bool IsInternalMeeting()
		{
			if (m_pInfo)
				return m_pInfo->IsInternalMeeting();

			return false;
		}

		virtual MeetingConnType GetMeetingConnType()
		{
			if (m_pInfo)
				return (MeetingConnType)m_pInfo->GetMeetingConnType();

			return MeetingConnType::Meeting_Conn_None;
		}

	private:
		ZOOM_SDK_NAMESPACE::IMeetingInfo* m_pInfo;
	};

	IMeetingInfo^ TranslateMeetingInfo(ZOOM_SDK_NAMESPACE::IMeetingInfo* pInfo)
	{
		if (pInfo)
		{
			return gcnew IMeetingInfoImpl(pInfo);
		}
		return nullptr;
	}
	//

	//translate event
	class MeetingEventHandler
	{
	public:
		static MeetingEventHandler& GetInst()
		{
			static MeetingEventHandler inst;
			return inst;
		}
		void onMeetingStatusChanged(ZOOM_SDK_NAMESPACE::MeetingStatus status, int iResult)
		{
			if (CMeetingServiceDotNetWrap::Instance)
				CMeetingServiceDotNetWrap::Instance->ProcMeetingStatusChanged((MeetingStatus)status, iResult);
		}
		void onMeetingStatisticsWarningNotification(ZOOM_SDK_NAMESPACE::StatisticsWarningType type)
		{
			if (CMeetingServiceDotNetWrap::Instance)
				CMeetingServiceDotNetWrap::Instance->ProcMeetingStatisticsWarningNotification((StatisticsWarningType)type);
		}
		void onMeetingSecureKeyNotification(const char* key, int len, ZOOM_SDK_NAMESPACE::IMeetingExternalSecureKeyHandler* pHandler)
		{
			if (CMeetingServiceDotNetWrap::Instance)
				CMeetingServiceDotNetWrap::Instance->ProcMeetingSecureKeyNotification(NativeBuffer2PlatformBuffer(key, len), 
					len, TranslateMeetingExternalSecureKeyHandler(pHandler));
		}
	private:
		MeetingEventHandler() {}
	};
	//

	CMeetingServiceDotNetWrap::CMeetingServiceDotNetWrap()
	{

	}
	CMeetingServiceDotNetWrap::~CMeetingServiceDotNetWrap()
	{

	}

	void CMeetingServiceDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& meetingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
		meetingWrap.m_cbonMeetingStatusChanged = 
			std::bind(&MeetingEventHandler::onMeetingStatusChanged, &MeetingEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);
		meetingWrap.m_cbonMeetingStatisticsWarningNotification =
			std::bind(&MeetingEventHandler::onMeetingStatisticsWarningNotification, &MeetingEventHandler::GetInst(), std::placeholders::_1);
		meetingWrap.m_cbonMeetingSecureKeyNotification =
			std::bind(&MeetingEventHandler::onMeetingSecureKeyNotification, &MeetingEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	}

	void CMeetingServiceDotNetWrap::ProcMeetingStatusChanged(MeetingStatus status, int iResult)
	{
		event_onMeetingStatusChanged(status, iResult);
	}

	void CMeetingServiceDotNetWrap::ProcMeetingStatisticsWarningNotification(StatisticsWarningType type)
	{
		event_onMeetingStatisticsWarningNotification(type);
	}
	void CMeetingServiceDotNetWrap::ProcMeetingSecureKeyNotification(array<Byte >^ key, int len, IMeetingExternalSecureKeyHandler^ pHandler)
	{
		event_onMeetingSecureKeyNotification(key, len, pHandler);
	}

	SDKError CMeetingServiceDotNetWrap::Join(JoinParam joinParam)
	{
		ZOOM_SDK_NAMESPACE::JoinParam joinParam_c;
		joinParam_c.userType = (ZOOM_SDK_NAMESPACE::SDKUserType)(joinParam.userType);
		switch (joinParam.userType)
		{
		case SDKUserType::SDK_UT_APIUSER:
		{
			if (nullptr == joinParam.apiuserJoin)
				return SDKError::SDKERR_INVALID_PARAMETER;

			joinParam_c.param.apiuserJoin.meetingNumber = joinParam.apiuserJoin->meetingNumber;
			joinParam_c.param.apiuserJoin.vanityID = PlatformString2WChar(joinParam.apiuserJoin->vanityID);
			joinParam_c.param.apiuserJoin.userName = PlatformString2WChar(joinParam.apiuserJoin->userName);
			joinParam_c.param.apiuserJoin.psw = PlatformString2WChar(joinParam.apiuserJoin->psw);
			joinParam_c.param.apiuserJoin.hDirectShareAppWnd = (HWND)joinParam.apiuserJoin->hDirectShareAppWnd.value;
			joinParam_c.param.apiuserJoin.toke4enfrocelogin = PlatformString2WChar(joinParam.apiuserJoin->toke4enfrocelogin);
			joinParam_c.param.apiuserJoin.participantId = PlatformString2WChar(joinParam.apiuserJoin->participantId);
			joinParam_c.param.apiuserJoin.webinarToken = PlatformString2WChar(joinParam.apiuserJoin->webinarToken);
			joinParam_c.param.apiuserJoin.isDirectShareDesktop = joinParam.apiuserJoin->isDirectShareDesktop;
			joinParam_c.param.apiuserJoin.isVideoOff = joinParam.apiuserJoin->isVideoOff;
			joinParam_c.param.apiuserJoin.isAudioOff = joinParam.apiuserJoin->isAudioOff;
		}
		break;
		case SDKUserType::SDK_UT_NORMALUSER:
		{
			if (nullptr == joinParam.normaluserJoin)
				return SDKError::SDKERR_INVALID_PARAMETER;

			joinParam_c.param.normaluserJoin.meetingNumber = joinParam.normaluserJoin->meetingNumber;
			joinParam_c.param.normaluserJoin.vanityID = PlatformString2WChar(joinParam.normaluserJoin->vanityID);
			joinParam_c.param.normaluserJoin.userName = PlatformString2WChar(joinParam.normaluserJoin->userName);
			joinParam_c.param.normaluserJoin.psw = PlatformString2WChar(joinParam.normaluserJoin->psw);
			joinParam_c.param.normaluserJoin.hDirectShareAppWnd = (HWND)joinParam.normaluserJoin->hDirectShareAppWnd.value;
			joinParam_c.param.normaluserJoin.participantId = PlatformString2WChar(joinParam.normaluserJoin->participantId);
			joinParam_c.param.normaluserJoin.webinarToken = PlatformString2WChar(joinParam.normaluserJoin->webinarToken);
			joinParam_c.param.normaluserJoin.isVideoOff = joinParam.normaluserJoin->isVideoOff;
			joinParam_c.param.normaluserJoin.isAudioOff = joinParam.normaluserJoin->isAudioOff;
			joinParam_c.param.normaluserJoin.isDirectShareDesktop = joinParam.normaluserJoin->isDirectShareDesktop;
		}
		break;
		case SDKUserType::SDK_UT_WITHOUT_LOGIN:
		{
			if (nullptr == joinParam.withoutloginJoin)
				return SDKError::SDKERR_INVALID_PARAMETER;
			joinParam_c.param.withoutloginuserJoin.meetingNumber = joinParam.withoutloginJoin->meetingNumber;
			joinParam_c.param.withoutloginuserJoin.vanityID = PlatformString2WChar(joinParam.withoutloginJoin->vanityID);
			joinParam_c.param.withoutloginuserJoin.userName = PlatformString2WChar(joinParam.withoutloginJoin->userName);
			joinParam_c.param.withoutloginuserJoin.psw = PlatformString2WChar(joinParam.withoutloginJoin->psw);
			joinParam_c.param.withoutloginuserJoin.hDirectShareAppWnd = (HWND)joinParam.withoutloginJoin->hDirectShareAppWnd.value;
			joinParam_c.param.withoutloginuserJoin.toke4enfrocelogin = PlatformString2WChar(joinParam.withoutloginJoin->toke4enfrocelogin);
			joinParam_c.param.withoutloginuserJoin.participantId = PlatformString2WChar(joinParam.withoutloginJoin->participantId);
			joinParam_c.param.withoutloginuserJoin.webinarToken = PlatformString2WChar(joinParam.withoutloginJoin->webinarToken);
			joinParam_c.param.withoutloginuserJoin.isDirectShareDesktop = joinParam.withoutloginJoin->isDirectShareDesktop;
			joinParam_c.param.withoutloginuserJoin.isVideoOff = joinParam.withoutloginJoin->isVideoOff;
			joinParam_c.param.withoutloginuserJoin.isAudioOff = joinParam.withoutloginJoin->isAudioOff;
		}
		break;
		default:
			break;
		}

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Join(joinParam_c);
	}

	SDKError CMeetingServiceDotNetWrap::Start(StartParam startParam)
	{
		ZOOM_SDK_NAMESPACE::StartParam startParam_c;
		startParam_c.userType = (ZOOM_SDK_NAMESPACE::SDKUserType)startParam.userType;
		switch (startParam.userType)
		{
		case SDKUserType::SDK_UT_APIUSER:
		{
			if (nullptr == startParam.apiuserStart)
				return SDKError::SDKERR_INVALID_PARAMETER;

			startParam_c.param.apiuserStart.userID = PlatformString2WChar(startParam.apiuserStart->userID);
			startParam_c.param.apiuserStart.userToken = PlatformString2WChar(startParam.apiuserStart->userToken);
			startParam_c.param.apiuserStart.userName = PlatformString2WChar(startParam.apiuserStart->userName);
			startParam_c.param.apiuserStart.meetingNumber = startParam.apiuserStart->meetingNumber;
			startParam_c.param.apiuserStart.vanityID = PlatformString2WChar(startParam.apiuserStart->vanityID);
			startParam_c.param.apiuserStart.hDirectShareAppWnd = (HWND)startParam.apiuserStart->hDirectShareAppWnd.value;
			startParam_c.param.apiuserStart.participantId = PlatformString2WChar(startParam.apiuserStart->participantId);
			startParam_c.param.apiuserStart.isDirectShareDesktop = startParam.apiuserStart->isDirectShareDesktop;
		}
		break;
		case SDKUserType::SDK_UT_NORMALUSER:
		{
			if (nullptr == startParam.normaluserStart)
				return SDKError::SDKERR_INVALID_PARAMETER;

			startParam_c.param.normaluserStart.meetingNumber = startParam.normaluserStart->meetingNumber;
			startParam_c.param.normaluserStart.vanityID = PlatformString2WChar(startParam.normaluserStart->vanityID);
			startParam_c.param.normaluserStart.hDirectShareAppWnd = (HWND)startParam.normaluserStart->hDirectShareAppWnd.value;
			startParam_c.param.normaluserStart.participantId = PlatformString2WChar(startParam.normaluserStart->participantId);
			startParam_c.param.normaluserStart.isVideoOff = startParam.normaluserStart->isVideoOff;
			startParam_c.param.normaluserStart.isAudioOff = startParam.normaluserStart->isAudioOff;
			startParam_c.param.normaluserStart.isDirectShareDesktop = startParam.normaluserStart->isDirectShareDesktop;
		}
		break;
		case SDKUserType::SDK_UT_WITHOUT_LOGIN:
		{
			if (nullptr == startParam.withoutloginStart)
				return SDKError::SDKERR_INVALID_PARAMETER;

			startParam_c.param.withoutloginStart.userID = PlatformString2WChar(startParam.withoutloginStart->userID);
			startParam_c.param.withoutloginStart.userToken = PlatformString2WChar(startParam.withoutloginStart->userToken);
			startParam_c.param.withoutloginStart.userZAK = PlatformString2WChar(startParam.withoutloginStart->userZAK);
			startParam_c.param.withoutloginStart.zoomuserType = (ZOOM_SDK_NAMESPACE::ZoomUserType)startParam.withoutloginStart->zoomuserType;
			startParam_c.param.withoutloginStart.userName = PlatformString2WChar(startParam.withoutloginStart->userName);
			startParam_c.param.withoutloginStart.meetingNumber = startParam.withoutloginStart->meetingNumber;
			startParam_c.param.withoutloginStart.vanityID = PlatformString2WChar(startParam.withoutloginStart->vanityID);
			startParam_c.param.withoutloginStart.hDirectShareAppWnd = (HWND)startParam.withoutloginStart->hDirectShareAppWnd.value;
			startParam_c.param.withoutloginStart.participantId = PlatformString2WChar(startParam.withoutloginStart->participantId);
			startParam_c.param.withoutloginStart.isDirectShareDesktop = startParam.withoutloginStart->isDirectShareDesktop;
		}
		break;
		default:
			break;
		}

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Start(startParam_c);
	}

	SDKError CMeetingServiceDotNetWrap::Leave(LeaveMeetingCmd leaveCmd)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Leave((ZOOM_SDK_NAMESPACE::LeaveMeetingCmd)leaveCmd);
	}

	MeetingStatus CMeetingServiceDotNetWrap::GetMeetingStatus()
	{
		return (MeetingStatus)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingStatus();
	}

	SDKError CMeetingServiceDotNetWrap::LockMeeting()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().LockMeeting();
	}

	SDKError CMeetingServiceDotNetWrap::UnlockMeeting()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().UnlockMeeting();
	}

	bool CMeetingServiceDotNetWrap::IsMeetingLocked()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().IsMeetingLocked();
	}

	IMeetingInfo^ CMeetingServiceDotNetWrap::GetMeetingInfo()
	{
		return TranslateMeetingInfo(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo());
	}

	ConnectionQuality CMeetingServiceDotNetWrap::GetSharingConnQuality()
	{
		return (ConnectionQuality)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetSharingConnQuality();
	}

	ConnectionQuality CMeetingServiceDotNetWrap::GetVideoConnQuality()
	{
		return (ConnectionQuality)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetVideoConnQuality();
	}

	ConnectionQuality CMeetingServiceDotNetWrap::GetAudioConnQuality()
	{
		return (ConnectionQuality)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetAudioConnQuality();
	}

	IMeetingConfigurationDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingConfiguration()
	{
		if (CMeetingConfigurationDotNetWrap::Instance)
			CMeetingConfigurationDotNetWrap::Instance->BindEvent();

		return CMeetingConfigurationDotNetWrap::Instance;
	}

	IMeetingUIControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetUIController()
	{
		if (CMeetingUIControllerDotNetWrap::Instance)
			CMeetingUIControllerDotNetWrap::Instance->BindEvent();

		return CMeetingUIControllerDotNetWrap::Instance;
	}

	IAnnotationControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetAnnotationController()
	{
		if (CAnnotationControllerDotNetWrap::Instance)
			CAnnotationControllerDotNetWrap::Instance->BindEvent();

		return CAnnotationControllerDotNetWrap::Instance;
	}

	IMeetingVideoControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingVideoController()
	{
		if (CMeetingVideoControllerDotNetWrap::Instance)
			CMeetingVideoControllerDotNetWrap::Instance->BindEvent();

		return CMeetingVideoControllerDotNetWrap::Instance;
	}

	IMeetingRemoteControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingRemoteController()
	{
		if (CMeetingRemoteControllerDotNetWrap::Instance)
			CMeetingRemoteControllerDotNetWrap::Instance->BindEvent();

		return CMeetingRemoteControllerDotNetWrap::Instance;
	}

	IMeetingShareControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingShareController()
	{
		if (CMeetingShareControllerDotNetWrap::Instance)
			CMeetingShareControllerDotNetWrap::Instance->BindEvent();

		return CMeetingShareControllerDotNetWrap::Instance;
	}

	IMeetingAudioControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingAudioController()
	{
		if (CMeetingAudioControllerDotNetWrap::Instance)
			CMeetingAudioControllerDotNetWrap::Instance->BindEvent();

		return CMeetingAudioControllerDotNetWrap::Instance;
	}

	IMeetingRecordingControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingRecordingController()
	{
		if (CMeetingRecordingControllerDotNetWrap::Instance)
			CMeetingRecordingControllerDotNetWrap::Instance->BindEvent();

		return CMeetingRecordingControllerDotNetWrap::Instance;
	}

	IMeetingChatControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingChatController()
	{
		if (CMeetingChatControllerDotNetWrap::Instance)
			CMeetingChatControllerDotNetWrap::Instance->BindEvent();

		return CMeetingChatControllerDotNetWrap::Instance;
	}

	IMeetingWaitingRoomControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingWaitingRoomController()
	{
		if (CMeetingWaitingRoomControllerDotNetWrap::Instance)
			CMeetingWaitingRoomControllerDotNetWrap::Instance->BindEvent();

		return CMeetingWaitingRoomControllerDotNetWrap::Instance;
	}

	IMeetingH323HelperDotNetWrap^ CMeetingServiceDotNetWrap::GetH323Helper()
	{
		if (CMeetingH323HelperDotNetWrap::Instance)
			CMeetingH323HelperDotNetWrap::Instance->BindEvent();

		return CMeetingH323HelperDotNetWrap::Instance;
	}

	IMeetingPhoneHelperDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingPhoneHelper()
	{
		if (CMeetingPhoneHelperDotNetWrap::Instance)
			CMeetingPhoneHelperDotNetWrap::Instance->BindEvent();

		return CMeetingPhoneHelperDotNetWrap::Instance;
	}

	IMeetingBreakoutRoomsControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingBreakoutRoomsController()
	{
		if (CMeetingBreakoutRoomsControllerDotNetWrap::Instance)
			CMeetingBreakoutRoomsControllerDotNetWrap::Instance->BindEvent();

		return CMeetingBreakoutRoomsControllerDotNetWrap::Instance;
	}

	IMeetingParticipantsControllerDotNetWrap^ CMeetingServiceDotNetWrap::GetMeetingParticipantsController()
	{
		if (CMeetingParticipantsControllerDotNetWrap::Instance)
			CMeetingParticipantsControllerDotNetWrap::Instance->BindEvent();

		return CMeetingParticipantsControllerDotNetWrap::Instance;
	}
}