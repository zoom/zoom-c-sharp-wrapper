#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public enum class SettingTabPage : int
	{
		SettingTabPage_General,
		SettingTabPage_Audio,
		SettingTabPage_Video,
	};

	public value class ShowSettingDlgParam
	{
	public:
		HWNDDotNet hParent;///< Parent window handle
		int top;///< setting dialog top position
		int left;///< setting dialog left position
		HWNDDotNet hSettingWnd;///< return setting dialog handle
		bool bShow;///< show or not
		SettingTabPage eTabPageType;
	};

	public interface class IGeneralSettingContextDotNetWrap
	{
	public:
		SDKError EnableDualScreenMode(bool bEnable);
		bool IsDualScreenModeEnabled();
		SDKError TurnOffAeroModeInSharing(bool bTurnoff);
		bool IsAeroModeInSharingTurnOff();
		SDKError EnableAutoFitToWindowWhenViewSharing(bool bEnable);
		bool IsAutoFitToWindowWhenViewSharingEnabled();
		SDKError EnableAutoFullScreenVideoWhenJoinMeeting(bool bEnable);
		bool IsAutoFullScreenVideoWhenJoinMeetingEnabled();
		SDKError EnableSplitScreenMode(bool bEnable);
		bool IsSplitScreenModeEnabled();
		SDKError EnableAutoFullScreenVideoWhenViewShare(bool bEnable);
		bool IsAutoFullScreenVideoWhenViewShareEnabled();
	};

	private ref class CGeneralSettingContextDotNetWrap sealed : public IGeneralSettingContextDotNetWrap
	{
	public:
		static property CGeneralSettingContextDotNetWrap^ Instance
		{
			CGeneralSettingContextDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError EnableDualScreenMode(bool bEnable);
		virtual bool IsDualScreenModeEnabled();
		virtual SDKError TurnOffAeroModeInSharing(bool bTurnoff);
		virtual bool IsAeroModeInSharingTurnOff();
		virtual SDKError EnableAutoFitToWindowWhenViewSharing(bool bEnable);
		virtual bool IsAutoFitToWindowWhenViewSharingEnabled();
		virtual SDKError EnableAutoFullScreenVideoWhenJoinMeeting(bool bEnable);
		virtual bool IsAutoFullScreenVideoWhenJoinMeetingEnabled();
		virtual SDKError EnableSplitScreenMode(bool bEnable);
		virtual bool IsSplitScreenModeEnabled();
		virtual SDKError EnableAutoFullScreenVideoWhenViewShare(bool bEnable);
		virtual bool IsAutoFullScreenVideoWhenViewShareEnabled();
	private:
		CGeneralSettingContextDotNetWrap() {}
		virtual ~CGeneralSettingContextDotNetWrap() {}
		static CGeneralSettingContextDotNetWrap^ m_Instance = gcnew CGeneralSettingContextDotNetWrap;
	};

	public interface class ICameraInfoDotNetWrap
	{
	public:
		String^ GetDeviceId();
		String^ GetDeviceName();
		bool IsSelectedDevice();
	};

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
	};

	private ref class CVideoSettingContextDotNetWrap sealed : public IVideoSettingContextDotNetWrap
	{
	public:
		static property CVideoSettingContextDotNetWrap^ Instance
		{
			CVideoSettingContextDotNetWrap^ get() { return m_Instance; }
		}

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
	private:
		CVideoSettingContextDotNetWrap() {}
		virtual ~CVideoSettingContextDotNetWrap() {}
		static CVideoSettingContextDotNetWrap^ m_Instance = gcnew CVideoSettingContextDotNetWrap;
	};


	public interface class IMicInfoDotNetWrap
	{
	public:
		String^ GetDeviceId();
		String^ GetDeviceName();
		bool IsSelectedDevice();
	};

	public interface class ISpeakerInfoDotNetWrap
	{
	public:
		String^ GetDeviceId();
		String^ GetDeviceName();
		bool IsSelectedDevice();
	};

	public interface class IAudioSettingContextDotNetWrap
	{
	public:
		array<IMicInfoDotNetWrap^ >^ GetMicList();
		SDKError SelectMic(String^ deviceId, String^ deviceName);
		array<ISpeakerInfoDotNetWrap^ >^ GetSpeakerList();
		SDKError SelectSpeaker(String^ deviceId, String^ deviceName);
		SDKError EnableAutoJoinAudio(bool bEnable);
		bool IsAutoJoinAudioEnabled();
		SDKError EnableAutoAdjustMic(bool bEnable);
		bool IsAutoAdjustMicEnabled();
		SDKError EnableStereoAudio(bool bEnable);
		bool IsStereoAudioEnable();
		SDKError EnableMicOriginalInput(bool bEnable);
		bool IsMicOriginalInputEnable();
	};

	private ref class CAudioSettingContextDotNetWrap sealed : public IAudioSettingContextDotNetWrap
	{
	public:
		static property CAudioSettingContextDotNetWrap^ Instance
		{
			CAudioSettingContextDotNetWrap^ get() { return m_Instance; }
		}

		virtual array<IMicInfoDotNetWrap^ >^ GetMicList();
		virtual SDKError SelectMic(String^ deviceId, String^ deviceName);
		virtual array<ISpeakerInfoDotNetWrap^ >^ GetSpeakerList();
		virtual SDKError SelectSpeaker(String^ deviceId, String^ deviceName);
		virtual SDKError EnableAutoJoinAudio(bool bEnable);
		virtual bool IsAutoJoinAudioEnabled();
		virtual SDKError EnableAutoAdjustMic(bool bEnable);
		virtual bool IsAutoAdjustMicEnabled();
		virtual SDKError EnableStereoAudio(bool bEnable);
		virtual bool IsStereoAudioEnable();
		virtual SDKError EnableMicOriginalInput(bool bEnable);
		virtual bool IsMicOriginalInputEnable();

	private:
		CAudioSettingContextDotNetWrap() {}
		virtual ~CAudioSettingContextDotNetWrap() {}
		static CAudioSettingContextDotNetWrap^ m_Instance = gcnew CAudioSettingContextDotNetWrap;
	};

	public interface class IRecordingSettingContextDotNetWrap
	{
	public:
		SDKError SetRecordingPath(String^ szPath);
		String^  GetRecordingPath();
	};

	private ref class CRecordingSettingContextDotNetWrap sealed : public IRecordingSettingContextDotNetWrap
	{
	public:
		static property CRecordingSettingContextDotNetWrap^ Instance
		{
			CRecordingSettingContextDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError SetRecordingPath(String^ szPath);
		virtual String^  GetRecordingPath();
	private:
		CRecordingSettingContextDotNetWrap() {}
		virtual ~CRecordingSettingContextDotNetWrap() {}
		static CRecordingSettingContextDotNetWrap^ m_Instance = gcnew CRecordingSettingContextDotNetWrap;
	};

	public enum class SettingsNetWorkType : int
	{
		SETTINGS_NETWORK_WIRED = 0,
		SETTINGS_NETWORK_WIFI = 1,
		SETTINGS_NETWORK_PPP = 2,
		SETTINGS_NETWORK_3G = 3,
		SETTINGS_NETWORK_OTHERS = 4,

		SETTINGS_NETWORK_UNKNOWN = -1,
	};

	public enum class SettingConnectionType : int
	{
		SETTINGS_CONNECTION_TYPE_CLOUD = 0,
		SETTINGS_CONNECTION_TYPE_DIRECT,
		SETTINGS_CONNECTION_TYPE_UNKNOWN = -1,
	};

	public value class OverallStatisticInfo
	{
	public:
		SettingsNetWorkType net_work_type_;
		SettingConnectionType connection_type_;
		String^ proxy_addr_;
	};

	public value class AudioSessionStatisticInfo
	{
	public:
		int frequency_send_; //KHz
		int frequency_recv_; //KHz
		int latency_send_;//ms
		int latency_recv_;//ms
		int jitter_send_;//ms
		int jitter_recv_;//ms
		float packetloss_send_;//%
		float packetloss_recv_;//%
	};

	public value class ASVSessionStatisticInfo
	{
	public:
		int latency_send_;//ms
		int latency_recv_;//ms
		int jitter_send_;//ms
		int jitter_recv_;//ms
		float packetloss_send_max_;//%
		float packetloss_recv_max_;//%
		float packetloss_send_avg_;//%
		float packetloss_recv_avg_;//%
		int resolution_send_; //HIWORD->height,LOWORD->width
		int resolution_recv_; //HIWORD->height,LOWORD->width 
		int fps_send_;//fps
		int fps_recv_;//fps
	};

	public interface class IStatisticSettingContextDotNetWrap
	{
	public:
		SDKError QueryOverallStatisticInfo(OverallStatisticInfo^% info_);
		SDKError QueryAudioStatisticInfo(AudioSessionStatisticInfo^% info_);
		SDKError QueryVideoStatisticInfo(ASVSessionStatisticInfo^% info_);
		SDKError QueryShareStatisticInfo(ASVSessionStatisticInfo^% info_);
	};

	private ref class CStatisticSettingContextDotNetWrap sealed : public IStatisticSettingContextDotNetWrap
	{
	public:
		static property CStatisticSettingContextDotNetWrap^ Instance
		{
			CStatisticSettingContextDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError QueryOverallStatisticInfo(OverallStatisticInfo^% info_);
		virtual SDKError QueryAudioStatisticInfo(AudioSessionStatisticInfo^% info_);
		virtual SDKError QueryVideoStatisticInfo(ASVSessionStatisticInfo^% info_);
		virtual SDKError QueryShareStatisticInfo(ASVSessionStatisticInfo^% info_);

	private:
		CStatisticSettingContextDotNetWrap() {}
		virtual ~CStatisticSettingContextDotNetWrap() {}
		static CStatisticSettingContextDotNetWrap^ m_Instance = gcnew CStatisticSettingContextDotNetWrap;
	};

	public interface class ISettingServiceDotNetWrap
	{
	public:
		SDKError ShowSettingDlg(ShowSettingDlgParam^% param);
		SDKError HideSettingDlg();
		IGeneralSettingContextDotNetWrap^ GetGeneralSettings();
		IAudioSettingContextDotNetWrap^ GetAudioSettings();
		IVideoSettingContextDotNetWrap^ GetVideoSettings();
		IRecordingSettingContextDotNetWrap^ GetRecordingSettings();
		IStatisticSettingContextDotNetWrap^ GetStatisticSettings();
	};

	private ref class CSettingServiceDotNetWrap sealed : public ISettingServiceDotNetWrap
	{
	public:
		static property CSettingServiceDotNetWrap^ Instance
		{
			CSettingServiceDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent() {}

		virtual SDKError ShowSettingDlg(ShowSettingDlgParam^% param);
		virtual SDKError HideSettingDlg();
		virtual IGeneralSettingContextDotNetWrap^ GetGeneralSettings();
		virtual IAudioSettingContextDotNetWrap^ GetAudioSettings();
		virtual IVideoSettingContextDotNetWrap^ GetVideoSettings();
		virtual IRecordingSettingContextDotNetWrap^ GetRecordingSettings();
		virtual IStatisticSettingContextDotNetWrap^ GetStatisticSettings();
	private:
		CSettingServiceDotNetWrap() {}
		virtual ~CSettingServiceDotNetWrap() {}
		static CSettingServiceDotNetWrap^ m_Instance = gcnew CSettingServiceDotNetWrap;
	};
}