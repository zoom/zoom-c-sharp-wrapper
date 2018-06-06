#pragma once
using namespace System;
using namespace System::Windows;
using namespace System::Drawing;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class SDKMeetingUIType : int
	{
		SDK_Meeting_UI_None,
		SDK_Meeting_UI_VideoWall_Mode,
		SDK_Meeting_UI_ActiveRender_Mode,
	};

	public value class VideoWallPageInfoParam
	{
	public:
		int nCurrentPage;
		int nTotalPages;
	};

	public value class ShowChatDlgParam
	{
	public:
		HWNDDotNet  hParent;///< Parent window handle
		System::Drawing::Rectangle rect;///< chat dialog position
		HWNDDotNet^  hChatWnd;///< return chat windows handle
	};

	public enum class SDKFloatVideoType : int
	{
		FLOATVIDEO_List,
		FLOATVIDEO_Small,
		FLOATVIDEO_Large,
		FLOATVIDEO_Minimize,
	};

	public enum class SDKMinimizeUIMode : int
	{
		MinimizeUIMode_NONE,
		MinimizeUIMode_SHARE,
		MinimizeUIMode_VIDEO,
		MinimizeUIMode_ACTIVESPEAKER,
	};

	public value class SplitScreenInfo
	{
	public:
		bool bSupportSplitScreen;
		bool bInSplitScreenMode;
	};

	public delegate void onInviteBtnClicked();
	public delegate void onStartShareBtnClicked();
	public delegate void onEndMeetingBtnClicked();
	public delegate void onParticipantListBtnClicked();

	public interface class IMeetingUIControllerDotNetWrap
	{
	public:
		SDKError ShowChatDlg(ShowChatDlgParam^% param);
		SDKError HideChatDlg();
		SDKError EnterFullScreen(bool firstView, bool secondView);
		SDKError ExitFullScreen(bool firstView, bool secondView);
		SDKError SwitchToVideoWall();
		SDKError SwtichToAcitveSpeaker();
		SDKError MoveFloatVideoWnd(int left, int top);
		SDKError ShowSharingToolbar(bool bShow);
		SDKError SwitchFloatVideoToActiveSpkMod();
		SDKError ChangeFloatoActiveSpkVideoSize(SDKFloatVideoType type);
		SDKError SwitchFloatVideoToGalleryMod();
		SDKError ShowParticipantsListWnd(bool bShow, HWNDDotNet^% hParticipantsListWnd);
		SDKError ShowBottomFloatToolbarWnd(bool bShow);
		SDKError GetMeetingUIWnd(HWNDDotNet^% hFirstView, HWNDDotNet^% hSecondView);
		SDKError ShowJoinAudioDlg();
		SDKError HideJoinAudioDlg();
		SDKError GetWallViewPageInfo(VideoWallPageInfoParam^% videoWallPageInfoParam);
		SDKError ShowPreOrNextPageVideo(bool bPageUp);
		SDKError ShowSharingFrameWindows(bool bShow);
		bool	 IsMinimizeModeOfFristScreenMeetingUIWnd(SDKMinimizeUIMode^% mode);
		SDKError SwitchMinimizeUIMode4FristScreenMeetingUIWnd(SDKMinimizeUIMode mode);
		SDKError GetCurrentSplitScreenModeInfo(SplitScreenInfo^% info);
		SDKError SwitchSplitScreenMode(bool bSplit);

		void Add_CB_onInviteBtnClicked(onInviteBtnClicked^ cb);
		void Add_CB_onStartShareBtnClicked(onStartShareBtnClicked^ cb);
		void Add_CB_onEndMeetingBtnClicked(onEndMeetingBtnClicked^ cb);
		void Add_CB_onParticipantListBtnClicked(onParticipantListBtnClicked^ cb);
	};

	private ref class CMeetingUIControllerDotNetWrap sealed : public IMeetingUIControllerDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
		static property CMeetingUIControllerDotNetWrap^ Instance
		{
			CMeetingUIControllerDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError ShowChatDlg(ShowChatDlgParam^% param);
		virtual SDKError HideChatDlg();
		virtual SDKError EnterFullScreen(bool firstView, bool secondView);
		virtual SDKError ExitFullScreen(bool firstView, bool secondView);
		virtual SDKError SwitchToVideoWall();
		virtual SDKError SwtichToAcitveSpeaker();
		virtual SDKError MoveFloatVideoWnd(int left, int top);
		virtual SDKError ShowSharingToolbar(bool bShow);
		virtual SDKError SwitchFloatVideoToActiveSpkMod();
		virtual SDKError ChangeFloatoActiveSpkVideoSize(SDKFloatVideoType type);
		virtual SDKError SwitchFloatVideoToGalleryMod();
		virtual SDKError ShowParticipantsListWnd(bool bShow, HWNDDotNet^% hParticipantsListWnd);
		virtual SDKError ShowBottomFloatToolbarWnd(bool bShow);
		virtual SDKError GetMeetingUIWnd(HWNDDotNet^% hFirstView, HWNDDotNet^% hSecondView);
		virtual SDKError ShowJoinAudioDlg();
		virtual SDKError HideJoinAudioDlg();
		virtual SDKError GetWallViewPageInfo(VideoWallPageInfoParam^% videoWallPageInfoParam);
		virtual SDKError ShowPreOrNextPageVideo(bool bPageUp);
		virtual SDKError ShowSharingFrameWindows(bool bShow);
		virtual bool	 IsMinimizeModeOfFristScreenMeetingUIWnd(SDKMinimizeUIMode^% mode);
		virtual SDKError SwitchMinimizeUIMode4FristScreenMeetingUIWnd(SDKMinimizeUIMode mode);
		virtual SDKError GetCurrentSplitScreenModeInfo(SplitScreenInfo^% info);
		virtual SDKError SwitchSplitScreenMode(bool bSplit);

		virtual void Add_CB_onInviteBtnClicked(onInviteBtnClicked^ cb)
		{
			event_onInviteBtnClicked += cb;
		}

		virtual void Add_CB_onStartShareBtnClicked(onStartShareBtnClicked^ cb)
		{
			event_onStartShareBtnClicked += cb;
		}

		virtual void Add_CB_onEndMeetingBtnClicked(onEndMeetingBtnClicked^ cb)
		{
			event_onEndMeetingBtnClicked += cb;
		}

		virtual void Add_CB_onParticipantListBtnClicked(onParticipantListBtnClicked^ cb)
		{
			event_onParticipantListBtnClicked += cb;
		}

		void BindEvent();
		void ProcInviteBtnClicked();
		void ProcStartShareBtnClicked();
		void ProcEndMeetingBtnClicked();
		void ProcParticipantListBtnClicked();

	private:
		CMeetingUIControllerDotNetWrap() {};
		virtual ~CMeetingUIControllerDotNetWrap() {};
		event onInviteBtnClicked^ event_onInviteBtnClicked;
		event onStartShareBtnClicked^ event_onStartShareBtnClicked;
		event onEndMeetingBtnClicked^ event_onEndMeetingBtnClicked;
		event onParticipantListBtnClicked^ event_onParticipantListBtnClicked;
		static CMeetingUIControllerDotNetWrap^ m_Instance = gcnew CMeetingUIControllerDotNetWrap;
	};
}