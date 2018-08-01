#include "stdafx.h"
#include "meeting_configuration_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	//translate event

	private ref class CMeetingPasswordAndScreenNameHandler sealed : public IMeetingPasswordAndScreenNameHandler
	{
	public:
		CMeetingPasswordAndScreenNameHandler()
		{
			m_pHandler = NULL;
		}

		CMeetingPasswordAndScreenNameHandler(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* pHandler)
		{
			m_pHandler = pHandler;
		}

		~CMeetingPasswordAndScreenNameHandler()
		{

		}

		virtual RequiredInfoType GetRequiredInfoType()
		{
			if (m_pHandler)
				return (RequiredInfoType)m_pHandler->GetRequiredInfoType();

			return RequiredInfoType::REQUIRED_INFO_TYPE_NONE;
		}

		virtual bool InputMeetingPasswordAndScreenName(String^ meetingPassword, String^ screenName)
		{
			if (m_pHandler)
				return m_pHandler->InputMeetingPasswordAndScreenName(PlatformString2WChar(meetingPassword), PlatformString2WChar(screenName));
			
			return false;
		}

		virtual void Cancel()
		{
			if (m_pHandler)
				m_pHandler->Cancel();
		}

	private:
		ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* m_pHandler;
	};

	IMeetingPasswordAndScreenNameHandler^ TranslateMeetingPasswordAndScreenNameHandler(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* pHandler)
	{
		if (pHandler)
			return gcnew CMeetingPasswordAndScreenNameHandler(pHandler);

		return nullptr;
	}

	class MeetingConfigurationEventHanlder
	{
	public:
		static MeetingConfigurationEventHanlder& GetInst()
		{
			static MeetingConfigurationEventHanlder inst;
			return inst;
		}

		void onInputMeetingPasswordAndScreenNameNotification(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* pHandler)
		{
			if (CMeetingConfigurationDotNetWrap::Instance)
				CMeetingConfigurationDotNetWrap::Instance->ProcInputMeetingPasswordAndScreenNameNotification(
					TranslateMeetingPasswordAndScreenNameHandler(pHandler));
		}
		void onAirPlayInstructionWndNotification(bool bShow, const wchar_t* airhostName)
		{
			if (CMeetingConfigurationDotNetWrap::Instance)
				CMeetingConfigurationDotNetWrap::Instance->ProcAirPlayInstructionWndNotification(
					bShow, WChar2PlatformString(airhostName));
		}
	private:
		MeetingConfigurationEventHanlder() {}
	};
	//

	//////////////////////////////////////////////////////////////////////////
	void CMeetingConfigurationDotNetWrap::Reset() 
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().Reset();
	}

	void CMeetingConfigurationDotNetWrap::SetFloatVideoPos(WndPosition pos)
	{
		ZOOM_SDK_NAMESPACE::WndPosition pos_c;
		pos_c.hParent = (HWND)pos.hParent.value;
		pos_c.hSelfWnd = (HWND)pos.hSelfWnd.value;
		pos_c.left = pos.left;
		pos_c.top = pos.top;
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetFloatVideoPos(pos_c);
	}

	void CMeetingConfigurationDotNetWrap::SetSharingToolbarVisibility(bool bShow)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetSharingToolbarVisibility(bShow);
	}

	void CMeetingConfigurationDotNetWrap::SetBottomFloatToolbarWndVisibility(bool bShow)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetBottomFloatToolbarWndVisibility(bShow);
	}

	void CMeetingConfigurationDotNetWrap::SetDirectShareMonitorID(String^ monitorID)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetDirectShareMonitorID(PlatformString2WChar(monitorID));
	}

	void CMeetingConfigurationDotNetWrap::SetMeetingUIPos(WndPosition pos)
	{
		ZOOM_SDK_NAMESPACE::WndPosition pos_c;
		pos_c.hParent = (HWND)pos.hParent.value;
		pos_c.hSelfWnd = (HWND)pos.hSelfWnd.value;
		pos_c.left = pos.left;
		pos_c.top = pos.top;
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetMeetingUIPos(pos_c);
	}

	void CMeetingConfigurationDotNetWrap::DisableWaitingForHostDialog(bool bDisable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().DisableWaitingForHostDialog(bDisable);
	}

	void CMeetingConfigurationDotNetWrap::HideMeetingInfoFromMeetingUITitle(bool bHide)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().HideMeetingInfoFromMeetingUITitle(bHide);
	}

	void CMeetingConfigurationDotNetWrap::SetMeetingIDForMeetingUITitle(unsigned __int64 meetingNumber)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetMeetingIDForMeetingUITitle(meetingNumber);
	}

	void CMeetingConfigurationDotNetWrap::DisablePopupMeetingWrongPSWDlg(bool bDisable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().DisablePopupMeetingWrongPSWDlg(bDisable);
	}

	void CMeetingConfigurationDotNetWrap::EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableAutoEndOtherMeetingWhenStartMeeting(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableAutoAdjustMicVolumeWhenJoinAudio(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableAutoAdjustMicVolumeWhenJoinAudio(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableApproveRemoteControlDlg(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableApproveRemoteControlDlg(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableDeclineRemoteControlResponseDlg(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableDeclineRemoteControlResponseDlg(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableLeaveMeetingOptionForHost(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableLeaveMeetingOptionForHost(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableInviteButtonOnMeetingUI(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableInviteButtonOnMeetingUI(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableInputMeetingPasswordDlg(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableInputMeetingPasswordDlg(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableEnterAndExitFullScreenButtonOnMeetingUI(bEnable);
	}
	void CMeetingConfigurationDotNetWrap::EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableLButtonDBClick4SwitchFullScreenMode(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::SetFloatVideoWndVisibility(bool bShow)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().SetFloatVideoWndVisibility(bShow);
	}

	void CMeetingConfigurationDotNetWrap::PrePopulateWebinarRegistrationInfo(String^ email, String^ username)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().PrePopulateWebinarRegistrationInfo(PlatformString2WChar(email), PlatformString2WChar(username));
	}

	void CMeetingConfigurationDotNetWrap::RedirectClickShareBTNEvent(bool bRedirect)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().RedirectClickShareBTNEvent(bRedirect);
	}

	void CMeetingConfigurationDotNetWrap::RedirectClickEndMeetingBTNEvent(bool bRedirect)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().RedirectClickEndMeetingBTNEvent(bRedirect);
	}

	void CMeetingConfigurationDotNetWrap::EnableToolTipsShow(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableToolTipsShow(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableAirplayInstructionWindow(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableAirplayInstructionWindow(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableClaimHostFeature(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().EnableClaimHostFeature(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().ConfigDSCP(dscpAudio, dscpVideo, bReset);
	}

	void CMeetingConfigurationDotNetWrap::RedirectClickParticipantListBTNEvent(bool bRedirect)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().RedirectClickParticipantListBTNEvent(bRedirect);
	}
	void CMeetingConfigurationDotNetWrap::DisableRemoteCtrlCopyPasteFeature(bool bDisable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().DisableRemoteCtrlCopyPasteFeature(bDisable);
	}

	void CMeetingConfigurationDotNetWrap::DisableSplitScreenModeUIElements(bool bDisable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().DisableSplitScreenModeUIElements(bDisable);
	}

	void CMeetingConfigurationDotNetWrap::EnableAutoHideJoinAudioDialog(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().EnableAutoHideJoinAudioDialog(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableHideFullPhoneNumber4PureCallinUser(bool bHide)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().EnableHideFullPhoneNumber4PureCallinUser(bHide);
	}

	void CMeetingConfigurationDotNetWrap::EnableLengthLimitationOfMeetingNumber(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().EnableLengthLimitationOfMeetingNumber(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::EnableShareIOSDevice(bool bEnable)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingConfiguration().EnableShareIOSDevice(bEnable);
	}

	void CMeetingConfigurationDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().m_cbonInputMeetingPasswordAndScreenNameNotification =
			std::bind(&MeetingConfigurationEventHanlder::onInputMeetingPasswordAndScreenNameNotification,
				&MeetingConfigurationEventHanlder::GetInst(), std::placeholders::_1);

		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingConfiguration().m_cbonAirPlayInstructionWndNotification =
			std::bind(&MeetingConfigurationEventHanlder::onAirPlayInstructionWndNotification,
				&MeetingConfigurationEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	void CMeetingConfigurationDotNetWrap::ProcInputMeetingPasswordAndScreenNameNotification(IMeetingPasswordAndScreenNameHandler^ pHandler)
	{
		event_onInputMeetingPasswordAndScreenNameNotification(pHandler);
	}

	void CMeetingConfigurationDotNetWrap::ProcAirPlayInstructionWndNotification(bool bShow, String^ airhostName)
	{
		event_onAirPlayInstructionWndNotification(bShow, airhostName);
	}
}