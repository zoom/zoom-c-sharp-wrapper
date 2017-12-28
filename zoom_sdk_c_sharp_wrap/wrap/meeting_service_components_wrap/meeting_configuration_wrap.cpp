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

END_ZOOM_SDK_NAMESPACE