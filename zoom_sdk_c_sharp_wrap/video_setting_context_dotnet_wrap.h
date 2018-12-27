#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/video_setting_context_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public interface class ICameraInfoDotNetWrap
	{
	public:
		String^ GetDeviceId();
		String^ GetDeviceName();
		bool IsSelectedDevice();
	};

	public delegate void onComputerCamDeviceChanged(array<ICameraInfoDotNetWrap^>^ newCameras);

	public interface class IVideoSettingContextDotNetWrap
	{
	public:
		array<ICameraInfoDotNetWrap^ >^ GetCameraList();
		SDKError SelectCamera(String^ deviceId);
		SDKError EnableVideoMirrorEffect(bool bEnable);
		bool IsVideoMirrorEffectEnabled();
		SDKError EnableFaceBeautyEffect(bool bEnable);
		bool IsFaceBeautyEffectEnabled();
		SDKError EnableHDVideo(bool bEnable);
		bool IsHDVideoEnabled();
		SDKError EnableAlwaysShowNameOnVideo(bool bEnable);
		bool IsAlwaysShowNameOnVideoEnabled();
		SDKError EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable);
		bool IsAutoTurnOffVideoWhenJoinMeetingEnabled();
		SDKError EnableAlwaysUse16v9(bool bEnable);
		bool IsAlwaysUse16v9();
		SDKError EnableSpotlightSelf(bool bEnable);
		bool IsSpotlightSelfEnabled();
		SDKError EnableHardwareEncode(bool bEnable);
		bool IsHardwareEncodeEnabled();
		SDKError Enable49VideoesInGallaryView(bool bEnable);
		bool Is49VideoesInGallaryViewEnabled();
		SDKError EnableHideNoVideoUsersOnWallView(bool bEnable);
		bool IsHideNoVideoUsersOnWallViewEnabled();
		// ITestVideoDeviceHelper* GetTestVideoDeviceHelper();

		void Add_CB_onComputerCamDeviceChanged(onComputerCamDeviceChanged^ cb);
		void Remove_CB_onComputerCamDeviceChanged(onComputerCamDeviceChanged^ cb);
	};

	private ref class CVideoSettingContextDotNetWrap sealed : public IVideoSettingContextDotNetWrap
	{
	public:
		static property CVideoSettingContextDotNetWrap^ Instance
		{
			CVideoSettingContextDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procComputerCamDeviceChanged(array<ICameraInfoDotNetWrap^ >^ newCameras);

		virtual array<ICameraInfoDotNetWrap^ >^ GetCameraList();
		virtual SDKError SelectCamera(String^ deviceId);
		virtual SDKError EnableVideoMirrorEffect(bool bEnable);
		virtual bool IsVideoMirrorEffectEnabled();
		virtual SDKError EnableFaceBeautyEffect(bool bEnable);
		virtual bool IsFaceBeautyEffectEnabled();
		virtual SDKError EnableHDVideo(bool bEnable);
		virtual bool IsHDVideoEnabled();
		virtual SDKError EnableAlwaysShowNameOnVideo(bool bEnable);
		virtual bool IsAlwaysShowNameOnVideoEnabled();
		virtual SDKError EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable);
		virtual bool IsAutoTurnOffVideoWhenJoinMeetingEnabled();
		virtual SDKError EnableAlwaysUse16v9(bool bEnable);
		virtual bool IsAlwaysUse16v9();
		virtual SDKError EnableSpotlightSelf(bool bEnable);
		virtual bool IsSpotlightSelfEnabled();
		virtual SDKError EnableHardwareEncode(bool bEnable);
		virtual bool IsHardwareEncodeEnabled();
		virtual SDKError Enable49VideoesInGallaryView(bool bEnable);
		virtual bool Is49VideoesInGallaryViewEnabled();
		virtual SDKError EnableHideNoVideoUsersOnWallView(bool bEnable);
		virtual bool IsHideNoVideoUsersOnWallViewEnabled();
		// ITestVideoDeviceHelper* GetTestVideoDeviceHelper();

		virtual void Add_CB_onComputerCamDeviceChanged(onComputerCamDeviceChanged^ cb)
		{
			event_onComputerCamDeviceChanged += cb;
		}

		virtual void Remove_CB_onComputerCamDeviceChanged(onComputerCamDeviceChanged^ cb)
		{
			event_onComputerCamDeviceChanged -= cb;
		}

		static array<ICameraInfoDotNetWrap^>^ ConvertCameraList(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo*>* pList);

	private:
		event onComputerCamDeviceChanged^ event_onComputerCamDeviceChanged;
		static CVideoSettingContextDotNetWrap^ m_Instance = gcnew CVideoSettingContextDotNetWrap;
	};

}
