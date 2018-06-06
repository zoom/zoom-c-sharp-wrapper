#include "stdafx.h"
#include "meeting_sharing_DotNet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	//translate event
	class MeetingSharingControllerEventHanlder
	{
	public:
		static MeetingSharingControllerEventHanlder& GetInst()
		{
			static MeetingSharingControllerEventHanlder inst;
			return inst;
		}
	
		void onSharingStatus(ZOOM_SDK_NAMESPACE::SharingStatus status, unsigned int userId)
		{
			if (CMeetingShareControllerDotNetWrap::Instance)
				CMeetingShareControllerDotNetWrap::Instance->ProcSharingStatus((SharingStatus)status, userId);
		}

		void onLockShareStatus(bool bLocked)
		{
			if (CMeetingShareControllerDotNetWrap::Instance)
				CMeetingShareControllerDotNetWrap::Instance->ProcLockShareStatus(bLocked);
		}

		void onShareContentNotification(ZOOM_SDK_NAMESPACE::ShareInfo& shareInfo)
		{
			if (CMeetingShareControllerDotNetWrap::Instance)
			{
				ShareInfo^ shareinfo_dotnet = gcnew ShareInfo;
				if (shareinfo_dotnet)
				{
					shareinfo_dotnet->eShareType = (ShareType)shareInfo.eShareType;
					shareinfo_dotnet->hwndSharedApp.value = 0;
					shareinfo_dotnet->monitorID = nullptr;
					switch (shareinfo_dotnet->eShareType)
					{
					case ShareType::SHARE_TYPE_AS:
					case ShareType::SHARE_TYPE_WB:
					{
						shareinfo_dotnet->hwndSharedApp.value = (UInt32)shareInfo.ut.hwndSharedApp;
					}
					break;
					case ShareType::SHARE_TYPE_DS:
					{
						shareinfo_dotnet->monitorID = WChar2PlatformString(shareInfo.ut.monitorID);
					}
					break;
					default:
						break;
					}
					
					CMeetingShareControllerDotNetWrap::Instance->ProcShareContentNotification(shareinfo_dotnet);
				}
			}
		}
	private:
		MeetingSharingControllerEventHanlder() {}
	};
	//

	void CMeetingShareControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingShareControllerWrap& meetingShare = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingShareController();
		meetingShare.m_cbonLockShareStatus =
			std::bind(&MeetingSharingControllerEventHanlder::onLockShareStatus, &MeetingSharingControllerEventHanlder::GetInst(), std::placeholders::_1);
		meetingShare.m_cbonShareContentNotification =
			std::bind(&MeetingSharingControllerEventHanlder::onShareContentNotification, &MeetingSharingControllerEventHanlder::GetInst(), std::placeholders::_1);
		meetingShare.m_cbonSharingStatus =
			std::bind(&MeetingSharingControllerEventHanlder::onSharingStatus, &MeetingSharingControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	SDKError CMeetingShareControllerDotNetWrap::StartAppShare(HWNDDotNet hwndSharedApp)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().StartAppShare((HWND)hwndSharedApp.value);
	}

	SDKError CMeetingShareControllerDotNetWrap::StartMonitorShare(String^ monitorID)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().StartMonitorShare(PlatformString2WChar(monitorID));
	}

	SDKError CMeetingShareControllerDotNetWrap::StartAirPlayShare()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().StartAirPlayShare();
	}

	SDKError CMeetingShareControllerDotNetWrap::ShowSharingAppSelectWnd()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().ShowSharingAppSelectWnd();
	}

	SDKError CMeetingShareControllerDotNetWrap::StopShare()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().StopShare();
	}

	SDKError CMeetingShareControllerDotNetWrap::BlockWindowFromScreenshare(bool bBlock, HWNDDotNet hWnd, bool bChangeWindowStyle)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().BlockWindowFromScreenshare(bBlock, (HWND)hWnd.value, bChangeWindowStyle);
	}

	SDKError CMeetingShareControllerDotNetWrap::LockShare()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().LockShare();
	}

	SDKError CMeetingShareControllerDotNetWrap::UnlockShare()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().UnlockShare();
	}

	SDKError CMeetingShareControllerDotNetWrap::SwitchToFitWindowModeWhenViewShare(SDKViewType type)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().SwitchToFitWindowModeWhenViewShare((ZOOM_SDK_NAMESPACE::SDKViewType)type);
	}

	SDKError CMeetingShareControllerDotNetWrap::SwitchToOriginalSizeModeWhenViewShare(SDKViewType type)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().SwitchToOriginalSizeModeWhenViewShare((ZOOM_SDK_NAMESPACE::SDKViewType)type);
	}

	SDKError CMeetingShareControllerDotNetWrap::PauseCurrentSharing()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().PauseCurrentSharing();
	}

	SDKError CMeetingShareControllerDotNetWrap::ResumeCurrentSharing()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().ResumeCurrentSharing();
	}

	array <unsigned int >^ CMeetingShareControllerDotNetWrap::GetViewableShareSourceList()
	{
		ZOOM_SDK_NAMESPACE::IList<unsigned int >* plst = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().GetViewableShareSourceList();

		return Convert(plst);
	}

	SDKError CMeetingShareControllerDotNetWrap::GetViewabltShareSourceByUserID(unsigned int userid, ViewableShareSource^% shareSource)
	{
		if (nullptr == shareSource)
			return SDKError::SDKERR_INVALID_PARAMETER;

		ZOOM_SDK_NAMESPACE::ViewableShareSource shareSource_c;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().GetViewabltShareSourceByUserID(userid, shareSource_c);

		shareSource->isCanBeRemoteControl = shareSource_c.isCanBeRemoteControl;
		shareSource->isShowingInFirstView = shareSource_c.isShowingInFirstView;
		shareSource->isShowingInSecondView = shareSource_c.isShowingInSecondView;
		shareSource->userid = shareSource_c.userid;
		return err;
	}

	SDKError CMeetingShareControllerDotNetWrap::ViewShare(unsigned int userid, SDKViewType type)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().ViewShare(userid, (ZOOM_SDK_NAMESPACE::SDKViewType)type);
	}

	SDKError CMeetingShareControllerDotNetWrap::ShowShareOptionDialog()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().ShowShareOptionDialog();
	}

	bool CMeetingShareControllerDotNetWrap::CanStartShare()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().CanStartShare();
	}

	SDKError CMeetingShareControllerDotNetWrap::IsShareLocked(bool^% bLocked)
	{
		if (nullptr == bLocked)
			return SDKError::SDKERR_INVALID_PARAMETER;

		bool bLocked_c(false);
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().IsShareLocked(bLocked_c);

		if (bLocked)
			bLocked = bLocked_c;

		return err;
	}

	bool	 CMeetingShareControllerDotNetWrap::IsSupportEnableShareComputerSound(bool^% bCurEnableOrNot)
	{
		bool bCurEnableOrNot_c(false);
		bool bSupport = (bool)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().IsSupportEnableShareComputerSound(bCurEnableOrNot_c);
		if (nullptr != bCurEnableOrNot)
			bCurEnableOrNot = bCurEnableOrNot_c;

		return bSupport;
	}

	bool	 CMeetingShareControllerDotNetWrap::IsSupportEnableOptimizeForFullScreenVideoClip(bool^% bCurEnableOrNot)
	{
		bool bCurEnableOrNot_c(false);
		bool bSupport = (bool)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().IsSupportEnableOptimizeForFullScreenVideoClip(bCurEnableOrNot_c);
		if (nullptr != bCurEnableOrNot)
			bCurEnableOrNot = bCurEnableOrNot_c;

		return bSupport;
	}

	SDKError CMeetingShareControllerDotNetWrap::EnableShareComputerSound(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().EnableShareComputerSound(bEnable);
	}

	SDKError CMeetingShareControllerDotNetWrap::EnableOptimizeForFullScreenVideoClip(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingShareController().EnableOptimizeForFullScreenVideoClip(bEnable);
	}

	void CMeetingShareControllerDotNetWrap::ProcSharingStatus(SharingStatus status, unsigned int userId)
	{
		event_onSharingStatus(status, userId);
	}

	void CMeetingShareControllerDotNetWrap::ProcLockShareStatus(bool bLocked)
	{
		event_onLockShareStatus(bLocked);
	}

	void CMeetingShareControllerDotNetWrap::ProcShareContentNotification(ShareInfo^ shareInfo)
	{
		event_onShareContentNotification(shareInfo);
	}
}