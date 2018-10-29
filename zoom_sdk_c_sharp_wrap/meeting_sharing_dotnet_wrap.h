#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public enum class SharingStatus : int
	{
		Sharing_Self_Send_Begin,
		Sharing_Self_Send_End,
		Sharing_Other_Share_Begin,
		Sharing_Other_Share_End,
		Sharing_View_Other_Sharing,
		Sharing_Pause,
		Sharing_Resume,
	};

	public value class ViewableShareSource sealed
	{
	public:
		unsigned int userid;
		bool isShowingInFirstView;
		bool isShowingInSecondView;
		bool isCanBeRemoteControl;
	};

	public enum class ShareType : int
	{
		SHARE_TYPE_UNKNOWN, //unknown
		SHARE_TYPE_AS,	//application share
		SHARE_TYPE_DS,	//desktop share
		SHARE_TYPE_WB,	//whiteboard share
		SHARE_TYPE_AIRHOST,	//mobile device from PC
		SHARE_TYPE_CAMERA,	//camera share
		SHARE_TYPE_DATA,	//data share
	};

	public value class ShareInfo sealed
	{
	public:
		ShareType eShareType;  //share type, refer to ShareType
		HWNDDotNet hwndSharedApp;  //handle of sharing application or whiteboard, it is valid only when eShareType is SHARE_TYPE_AS or SHARE_TYPE_WB
		String^ monitorID;  //monitor id of sharing desktop, it is valid only when eShareType is SHARE_TYPE_DS
	};

	public delegate void onSharingStatus(SharingStatus status, unsigned int userId);
	public delegate void onLockShareStatus(bool bLocked);
	public delegate void onShareContentNotification(ShareInfo^ shareInfo);

	public interface class IMeetingShareControllerDotNetWrap
	{
	public:
		SDKError StartAppShare(HWNDDotNet hwndSharedApp);
		SDKError StartMonitorShare(String^ monitorID);
		SDKError StartAirPlayShare();
		SDKError ShowSharingAppSelectWnd();
		SDKError StopShare();
		SDKError BlockWindowFromScreenshare(bool bBlock, HWNDDotNet hWnd, bool bChangeWindowStyle);
		SDKError LockShare();
		SDKError UnlockShare();
		SDKError SwitchToFitWindowModeWhenViewShare(SDKViewType type);
		SDKError SwitchToOriginalSizeModeWhenViewShare(SDKViewType type);
		SDKError PauseCurrentSharing();
		SDKError ResumeCurrentSharing();
		array <unsigned int >^ GetViewableShareSourceList();
		SDKError GetViewabltShareSourceByUserID(unsigned int userid, ViewableShareSource^% shareSource);
		SDKError ViewShare(unsigned int userid, SDKViewType type);
		SDKError ShowShareOptionDialog();
		bool CanStartShare();
		SDKError IsShareLocked(bool^% bLocked);
		bool	 IsSupportEnableShareComputerSound(bool^% bCurEnableOrNot);
		bool	 IsSupportEnableOptimizeForFullScreenVideoClip(bool^% bCurEnableOrNot);
		SDKError EnableShareComputerSound(bool bEnable);
		SDKError EnableOptimizeForFullScreenVideoClip(bool bEnable);

		void Add_CB_onSharingStatus(onSharingStatus^ cb);
		void Add_CB_onLockShareStatus(onLockShareStatus^ cb);
		void Add_CB_onShareContentNotification(onShareContentNotification^ cb);
	};

	private ref class CMeetingShareControllerDotNetWrap sealed : public IMeetingShareControllerDotNetWrap
	{
	public:
		static property CMeetingShareControllerDotNetWrap^ Instance
		{
			CMeetingShareControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();

		virtual SDKError StartAppShare(HWNDDotNet hwndSharedApp);
		virtual SDKError StartMonitorShare(String^ monitorID);
		virtual SDKError StartAirPlayShare();
		virtual SDKError ShowSharingAppSelectWnd();
		virtual SDKError StopShare();
		virtual SDKError BlockWindowFromScreenshare(bool bBlock, HWNDDotNet hWnd, bool bChangeWindowStyle);
		virtual SDKError LockShare();
		virtual SDKError UnlockShare();
		virtual SDKError SwitchToFitWindowModeWhenViewShare(SDKViewType type);
		virtual SDKError SwitchToOriginalSizeModeWhenViewShare(SDKViewType type);
		virtual SDKError PauseCurrentSharing();
		virtual SDKError ResumeCurrentSharing();
		virtual array <unsigned int >^ GetViewableShareSourceList();
		virtual SDKError GetViewabltShareSourceByUserID(unsigned int userid, ViewableShareSource^% shareSource);
		virtual SDKError ViewShare(unsigned int userid, SDKViewType type);
		virtual SDKError ShowShareOptionDialog();
		virtual bool CanStartShare();
		virtual SDKError IsShareLocked(bool^% bLocked);
		virtual bool	 IsSupportEnableShareComputerSound(bool^% bCurEnableOrNot);
		virtual bool	 IsSupportEnableOptimizeForFullScreenVideoClip(bool^% bCurEnableOrNot);
		virtual SDKError EnableShareComputerSound(bool bEnable);
		virtual SDKError EnableOptimizeForFullScreenVideoClip(bool bEnable);

		virtual void Add_CB_onSharingStatus(onSharingStatus^ cb)
		{
			event_onSharingStatus += cb;
		}

		virtual void Add_CB_onLockShareStatus(onLockShareStatus^ cb)
		{
			event_onLockShareStatus += cb;
		}

		virtual void Add_CB_onShareContentNotification(onShareContentNotification^ cb)
		{
			event_onShareContentNotification += cb;
		}

		void ProcSharingStatus(SharingStatus status, unsigned int userId);
		void ProcLockShareStatus(bool bLocked);
		void ProcShareContentNotification(ShareInfo^ shareInfo);
	private:
		event onSharingStatus^ event_onSharingStatus;
		event onLockShareStatus^ event_onLockShareStatus;
		event onShareContentNotification^ event_onShareContentNotification;
		static CMeetingShareControllerDotNetWrap^ m_Instance = gcnew CMeetingShareControllerDotNetWrap;
	};
}