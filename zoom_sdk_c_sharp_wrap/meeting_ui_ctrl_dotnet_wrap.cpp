#include "stdafx.h"
#include "meeting_ui_ctrl_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate event
	class MeetingUIControllerEventHanlder
	{
	public:
		static MeetingUIControllerEventHanlder& GetInst()
		{
			static MeetingUIControllerEventHanlder inst;
			return inst;
		}
		void onInviteBtnClicked(bool& handled)
		{
			if (CMeetingUIControllerDotNetWrap::Instance)
				CMeetingUIControllerDotNetWrap::Instance->ProcInviteBtnClicked();
		}

		void onStartShareBtnClicked()
		{
			if (CMeetingUIControllerDotNetWrap::Instance)
				CMeetingUIControllerDotNetWrap::Instance->ProcEndMeetingBtnClicked();
		}

		void onEndMeetingBtnClicked()
		{
			if (CMeetingUIControllerDotNetWrap::Instance)
				CMeetingUIControllerDotNetWrap::Instance->ProcEndMeetingBtnClicked();
		}

		void onParticipantListBtnClicked()
		{
			if (CMeetingUIControllerDotNetWrap::Instance)
				CMeetingUIControllerDotNetWrap::Instance->ProcParticipantListBtnClicked();
		}
	private:
		MeetingUIControllerEventHanlder() {}
	};
	//
	void CMeetingUIControllerDotNetWrap::BindEvent()
	{
		//todo
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetUIController().m_cbonInviteBtnClicked =
			std::bind(&MeetingUIControllerEventHanlder::onInviteBtnClicked,
				&MeetingUIControllerEventHanlder::GetInst(), std::placeholders::_1);

		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetUIController().m_cbonStartShareBtnClicked =
			std::bind(&MeetingUIControllerEventHanlder::onStartShareBtnClicked,
				&MeetingUIControllerEventHanlder::GetInst());

		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetUIController().m_cbonEndMeetingBtnClicked =
			std::bind(&MeetingUIControllerEventHanlder::onEndMeetingBtnClicked,
				&MeetingUIControllerEventHanlder::GetInst());

		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetUIController().m_cbonParticipantListBtnClicked =
			std::bind(&MeetingUIControllerEventHanlder::onParticipantListBtnClicked,
				&MeetingUIControllerEventHanlder::GetInst());
	}

	void CMeetingUIControllerDotNetWrap::ProcInviteBtnClicked()
	{
		event_onInviteBtnClicked();
	}

	void CMeetingUIControllerDotNetWrap::ProcStartShareBtnClicked()
	{
		event_onStartShareBtnClicked();
	}

	void CMeetingUIControllerDotNetWrap::ProcEndMeetingBtnClicked()
	{
		event_onEndMeetingBtnClicked();
	}

	void CMeetingUIControllerDotNetWrap::ProcParticipantListBtnClicked()
	{
		event_onParticipantListBtnClicked();
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowChatDlg(ShowChatDlgParam^% param)
	{
		if (nullptr == param)
			return SDKError::SDKERR_INVALID_PARAMETER;

		ZOOM_SDK_NAMESPACE::ShowChatDlgParam param_c;
		param_c.hParent = (HWND)param->hParent.value;
		param_c.rect.bottom = param->rect.Bottom;
		param_c.rect.left = param->rect.Left;
		param_c.rect.right = param->rect.Right;
		param_c.rect.top = param->rect.Top;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowChatDlg(param_c);
		Convert_HWND(param_c.hChatWnd, param->hChatWnd);

		return err;
	}

	SDKError CMeetingUIControllerDotNetWrap::HideChatDlg()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().HideChatDlg();
	}

	SDKError CMeetingUIControllerDotNetWrap::EnterFullScreen(bool firstView, bool secondView)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().EnterFullScreen(firstView, secondView);
	}

	SDKError CMeetingUIControllerDotNetWrap::ExitFullScreen(bool firstView, bool secondView)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ExitFullScreen(firstView, secondView);
	}

	SDKError CMeetingUIControllerDotNetWrap::SwitchToVideoWall()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().SwitchToVideoWall();
	}

	SDKError CMeetingUIControllerDotNetWrap::SwtichToAcitveSpeaker()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().SwtichToAcitveSpeaker();
	}

	SDKError CMeetingUIControllerDotNetWrap::MoveFloatVideoWnd(int left, int top)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().MoveFloatVideoWnd(left, top);
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowSharingToolbar(bool bShow)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowSharingToolbar(bShow);
	}

	SDKError CMeetingUIControllerDotNetWrap::SwitchFloatVideoToActiveSpkMod()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().SwitchFloatVideoToActiveSpkMod();
	}

	SDKError CMeetingUIControllerDotNetWrap::ChangeFloatoActiveSpkVideoSize(SDKFloatVideoType type)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ChangeFloatoActiveSpkVideoSize((ZOOM_SDK_NAMESPACE::SDKFloatVideoType)type);
	}

	SDKError CMeetingUIControllerDotNetWrap::SwitchFloatVideoToGalleryMod()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().SwitchFloatVideoToGalleryMod();
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowParticipantsListWnd(bool bShow, HWNDDotNet^% hParticipantsListWnd)
	{
		HWND hParticipantsListWnd_c(NULL);
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowParticipantsListWnd(bShow, hParticipantsListWnd_c);

		Convert_HWND(hParticipantsListWnd_c, hParticipantsListWnd);
	
		return err;
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowBottomFloatToolbarWnd(bool bShow)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowBottomFloatToolbarWnd(bShow);
	}

	SDKError CMeetingUIControllerDotNetWrap::GetMeetingUIWnd(HWNDDotNet^% hFirstView, HWNDDotNet^% hSecondView)
	{
		HWND hFirstView_c(NULL), hSecondView_c(NULL);
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().GetMeetingUIWnd(hFirstView_c, hSecondView_c);
		
		Convert_HWND(hFirstView_c, hFirstView);
		Convert_HWND(hSecondView_c, hSecondView);
		return err;
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowJoinAudioDlg()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowJoinAudioDlg();
	}

	SDKError CMeetingUIControllerDotNetWrap::HideJoinAudioDlg()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().HideJoinAudioDlg();
	}

	SDKError CMeetingUIControllerDotNetWrap::GetWallViewPageInfo(VideoWallPageInfoParam^% videoWallPageInfoParam)
	{
		if (nullptr == videoWallPageInfoParam)
			return SDKError::SDKERR_INVALID_PARAMETER;

		ZOOM_SDK_NAMESPACE::VideoWallPageInfoParam videoWallPageInfoParam_c;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().GetWallViewPageInfo(videoWallPageInfoParam_c);

		videoWallPageInfoParam->nCurrentPage = videoWallPageInfoParam_c.nCurrentPage;
		videoWallPageInfoParam->nTotalPages = videoWallPageInfoParam_c.nTotalPages;
		return err;
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowPreOrNextPageVideo(bool bPageUp)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowPreOrNextPageVideo(bPageUp);
	}

	SDKError CMeetingUIControllerDotNetWrap::ShowSharingFrameWindows(bool bShow)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().ShowPreOrNextPageVideo(bShow);
	}

	bool	 CMeetingUIControllerDotNetWrap::IsMinimizeModeOfFristScreenMeetingUIWnd(SDKMinimizeUIMode^% mode)
	{
		ZOOM_SDK_NAMESPACE::SDKMinimizeUIMode mode_c;
		bool ret = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().IsMinimizeModeOfFristScreenMeetingUIWnd(mode_c);

		if (mode)
			mode = (SDKMinimizeUIMode)mode;
		return ret;
	}

	SDKError CMeetingUIControllerDotNetWrap::SwitchMinimizeUIMode4FristScreenMeetingUIWnd(SDKMinimizeUIMode mode)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().SwitchMinimizeUIMode4FristScreenMeetingUIWnd((ZOOM_SDK_NAMESPACE::SDKMinimizeUIMode)mode);
	}

	SDKError CMeetingUIControllerDotNetWrap::GetCurrentSplitScreenModeInfo(SplitScreenInfo^% info)
	{
		if (nullptr == info)
			return SDKError::SDKERR_INVALID_PARAMETER;

		ZOOM_SDK_NAMESPACE::SplitScreenInfo info_c;
		SDKError err =(SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().GetCurrentSplitScreenModeInfo(info_c);

		info->bSupportSplitScreen = info_c.bSupportSplitScreen;
		info->bInSplitScreenMode = info_c.bInSplitScreenMode;

		return err;
	}

	SDKError CMeetingUIControllerDotNetWrap::SwitchSplitScreenMode(bool bSplit)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetUIController().SwitchSplitScreenMode(bSplit);
	}
}