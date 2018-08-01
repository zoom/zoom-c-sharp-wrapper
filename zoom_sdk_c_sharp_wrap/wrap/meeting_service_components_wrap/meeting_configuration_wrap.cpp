#include "meeting_configuration_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingConfiguration* InitIMeetingConfigurationFunc(IMeetingConfigurationEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingConfiguration* pObj = pOwner->GetSDKObj()->GetMeetingConfiguration();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}
void UninitIMeetingConfigurationFunc(IMeetingConfiguration* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

IMPL_FUNC_NORET_0(IMeetingConfiguration, Reset, void)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetFloatVideoPos, void, WndPosition, pos)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetSharingToolbarVisibility, void, bool, bShow)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetBottomFloatToolbarWndVisibility, void, bool, bShow)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetDirectShareMonitorID, void, const wchar_t*, monitorID)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetMeetingUIPos, void, WndPosition, pos)
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisableWaitingForHostDialog, void, bool, bDisable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,HideMeetingInfoFromMeetingUITitle, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetMeetingIDForMeetingUITitle, void, UINT64, meetingNumber)
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisablePopupMeetingWrongPSWDlg, void, bool, bDisable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAutoEndOtherMeetingWhenStartMeeting, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAutoAdjustSpeakerVolumeWhenJoinAudio, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAutoAdjustMicVolumeWhenJoinAudio, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableApproveRemoteControlDlg, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableDeclineRemoteControlResponseDlg, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableLeaveMeetingOptionForHost, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableInviteButtonOnMeetingUI, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableInputMeetingPasswordDlg, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableEnterAndExitFullScreenButtonOnMeetingUI, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableLButtonDBClick4SwitchFullScreenMode, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetFloatVideoWndVisibility, void, bool, bShow)
IMPL_FUNC_NORET_2(IMeetingConfiguration,PrePopulateWebinarRegistrationInfo, void, const wchar_t*, email, const wchar_t*, username)
IMPL_FUNC_NORET_1(IMeetingConfiguration,RedirectClickShareBTNEvent, void, bool, bRedirect)
IMPL_FUNC_NORET_1(IMeetingConfiguration,RedirectClickEndMeetingBTNEvent, void, bool, bRedirect)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableToolTipsShow, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAirplayInstructionWindow, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableClaimHostFeature, void, bool, bEnable)

//virtual void ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset) = 0;
IMPL_FUNC_NORET_3(IMeetingConfiguration,ConfigDSCP, void, int, dscpAudio, int, dscpVideo, bool, bReset)
//virtual void RedirectClickParticipantListBTNEvent(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration,RedirectClickParticipantListBTNEvent, void, bool, bRedirect)
//virtual void DisableRemoteCtrlCopyPasteFeature(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisableRemoteCtrlCopyPasteFeature, void, bool, bDisable)
//virtual void DisableSplitScreenModeUIElements(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisableSplitScreenModeUIElements, void, bool, bDisable)
//virtual void EnableAutoHideJoinAudioDialog(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableAutoHideJoinAudioDialog, void, bool, bEnable)
//virtual void EnableHideFullPhoneNumber4PureCallinUser(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableHideFullPhoneNumber4PureCallinUser, void, bool, bEnable)

//virtual void EnableLengthLimitationOfMeetingNumber(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableLengthLimitationOfMeetingNumber, void, bool, bEnable)
//virtual void EnableShareIOSDevice(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableShareIOSDevice, void, bool, bEnable)

//virtual void EnableShareWhiteBoard(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableShareWhiteBoard, void, bool, bEnable)
//virtual void AlwaysShowIconOnTaskBar(bool bAlwaysShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, AlwaysShowIconOnTaskBar, void, bool, bAlwaysShow)
//virtual void RedirectFreeMeetingEndingReminderDlg(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectFreeMeetingEndingReminderDlg, void, bool, bRedirect)
//virtual void SetShowAudioUseComputerSoundChkbox(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowAudioUseComputerSoundChkbox, void, bool, bShow)
//virtual void SetShowVideoOptimizeChkbox(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowVideoOptimizeChkbox, void, bool, bShow)
//virtual void SetShowCallInTab(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowCallInTab, void, bool, bShow)
//virtual void SetShowCallMeTab(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowCallMeTab, void, bool, bShow)
//virtual void ForceDisableMultiShare(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, ForceDisableMultiShare, void, bool, bDisable)
//virtual void SetAlwaysShowMeetingIDOnTitle(bool bAlwaysShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetAlwaysShowMeetingIDOnTitle, void, bool, bAlwaysShow)
END_ZOOM_SDK_NAMESPACE