#include "stdafx.h"
#include "setting_service_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	SDKError CSettingServiceDotNetWrap::ShowSettingDlg(ShowSettingDlgParam^% param)
	{
		if (nullptr == param)
			return SDKError::SDKERR_INVALID_PARAMETER;

		ZOOM_SDK_NAMESPACE::ShowSettingDlgParam param_c;
		param_c.hParent = (HWND)param->hParent.value;
		param_c.bShow = param->bShow;
		param_c.left = param->left;
		param_c.top = param->top;
		param_c.eTabPageType = (ZOOM_SDK_NAMESPACE::SettingTabPage)param->eTabPageType;

		SDKError err =  (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().ShowSettingDlg(param_c);
		param->hSettingWnd.value = (UInt32)param_c.hSettingWnd;
		return err;
	}

	SDKError CSettingServiceDotNetWrap::HideSettingDlg()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().HideSettingDlg();
	}

	IGeneralSettingContextDotNetWrap^ CSettingServiceDotNetWrap::GetGeneralSettings()
	{
		return CGeneralSettingContextDotNetWrap::Instance;
	}

	IAudioSettingContextDotNetWrap^ CSettingServiceDotNetWrap::GetAudioSettings()
	{
		return CAudioSettingContextDotNetWrap::Instance;
	}

	IVideoSettingContextDotNetWrap^ CSettingServiceDotNetWrap::GetVideoSettings()
	{
		return CVideoSettingContextDotNetWrap::Instance;
	}

	IRecordingSettingContextDotNetWrap^ CSettingServiceDotNetWrap::GetRecordingSettings()
	{
		return CRecordingSettingContextDotNetWrap::Instance;
	}

	IStatisticSettingContextDotNetWrap^ CSettingServiceDotNetWrap::GetStatisticSettings()
	{
		return CStatisticSettingContextDotNetWrap::Instance;
	}

	//CGeneralSettingContextDotNetWrap
	SDKError CGeneralSettingContextDotNetWrap::EnableDualScreenMode(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->EnableDualScreenMode(bEnable);
	}

	bool CGeneralSettingContextDotNetWrap::IsDualScreenModeEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->IsDualScreenModeEnabled();
	}

	SDKError CGeneralSettingContextDotNetWrap::TurnOffAeroModeInSharing(bool bTurnoff)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->TurnOffAeroModeInSharing(bTurnoff);
	}

	bool CGeneralSettingContextDotNetWrap::IsAeroModeInSharingTurnOff()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->IsAeroModeInSharingTurnOff();
	}

	SDKError CGeneralSettingContextDotNetWrap::EnableAutoFitToWindowWhenViewSharing(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->EnableAutoFitToWindowWhenViewSharing(bEnable);
	}

	bool CGeneralSettingContextDotNetWrap::IsAutoFitToWindowWhenViewSharingEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->IsAutoFitToWindowWhenViewSharingEnabled();
	}

	SDKError CGeneralSettingContextDotNetWrap::EnableAutoFullScreenVideoWhenJoinMeeting(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->EnableAutoFullScreenVideoWhenJoinMeeting(bEnable);
	}

	bool CGeneralSettingContextDotNetWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->IsAutoFullScreenVideoWhenJoinMeetingEnabled();
	}

	SDKError CGeneralSettingContextDotNetWrap::EnableSplitScreenMode(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->EnableSplitScreenMode(bEnable);
	}

	bool CGeneralSettingContextDotNetWrap::IsSplitScreenModeEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->IsSplitScreenModeEnabled();
	}

	SDKError CGeneralSettingContextDotNetWrap::EnableAutoFullScreenVideoWhenViewShare(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->EnableAutoFullScreenVideoWhenViewShare(bEnable);
	}

	bool CGeneralSettingContextDotNetWrap::IsAutoFullScreenVideoWhenViewShareEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetGeneralSettings()->IsAutoFullScreenVideoWhenViewShareEnabled();
	}

	//CVideoSettingContextDotNetWrap
	private ref class CCameraInfoDotNetWrap sealed : public ICameraInfoDotNetWrap
	{
	public:
		CCameraInfoDotNetWrap(ZOOM_SDK_NAMESPACE::ICameraInfo* pInfo)
		{
			m_pInfo = pInfo;
		}
		
		virtual String^ GetDeviceId()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDeviceId());

			return nullptr;
		}
		virtual String^ GetDeviceName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDeviceName());

			return nullptr;
		}

		virtual bool IsSelectedDevice()
		{
			if (m_pInfo)
				return m_pInfo->IsSelectedDevice();
			return false;
		}
	private:
		ZOOM_SDK_NAMESPACE::ICameraInfo* m_pInfo;
	};

	array<ICameraInfoDotNetWrap^ >^ CVideoSettingContextDotNetWrap::GetCameraList()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return nullptr;

		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo* >* plst = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->GetCameraList();
		if (plst && plst->GetCount())
		{
			int count = plst->GetCount();
			array<ICameraInfoDotNetWrap^ >^ aryCamera = gcnew array<ICameraInfoDotNetWrap^ >(count);
			if (aryCamera)
			{
				for (int i =0; i < count; i++)
				{
					aryCamera[i] = gcnew CCameraInfoDotNetWrap(plst->GetItem(i));
				}

				return aryCamera;
			}
		}

		return nullptr;
	}

	SDKError CVideoSettingContextDotNetWrap::SelectCamera(String^ deviceId)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->SelectCamera(PlatformString2WChar(deviceId));
	}

	SDKError CVideoSettingContextDotNetWrap::EnableVideoMirrorEffect(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->EnableVideoMirrorEffect(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsVideoMirrorEffectEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->IsVideoMirrorEffectEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableFaceBeautyEffect(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->EnableFaceBeautyEffect(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsFaceBeautyEffectEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->IsFaceBeautyEffectEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableHDVideo(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->EnableHDVideo(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsHDVideoEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->IsHDVideoEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableAlwaysShowNameOnVideo(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->EnableAlwaysShowNameOnVideo(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsAlwaysShowNameOnVideoEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->IsAlwaysShowNameOnVideoEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->EnableAutoTurnOffVideoWhenJoinMeeting(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			->IsAutoTurnOffVideoWhenJoinMeetingEnabled();
	}

	//CAudioSettingContextDotNetWrap
	private ref class CMicInfoDotNetWrap sealed : public IMicInfoDotNetWrap
	{
	public:
		CMicInfoDotNetWrap(ZOOM_SDK_NAMESPACE::IMicInfo* pInfo)
		{
			m_pInfo = pInfo;
		}

		virtual String^ GetDeviceId()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDeviceId());

			return nullptr;
		}
		virtual String^ GetDeviceName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDeviceName());

			return nullptr;
		}

		virtual bool IsSelectedDevice()
		{
			if (m_pInfo)
				return m_pInfo->IsSelectedDevice();
			return false;
		}
	private:
		ZOOM_SDK_NAMESPACE::IMicInfo* m_pInfo;
	};

	private ref class CSpeakerInfoDotNetWrap sealed : public ISpeakerInfoDotNetWrap
	{
	public:
		CSpeakerInfoDotNetWrap(ZOOM_SDK_NAMESPACE::ISpeakerInfo* pInfo)
		{
			m_pInfo = pInfo;
		}

		virtual String^ GetDeviceId()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDeviceId());

			return nullptr;
		}
		virtual String^ GetDeviceName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetDeviceName());

			return nullptr;
		}

		virtual bool IsSelectedDevice()
		{
			if (m_pInfo)
				return m_pInfo->IsSelectedDevice();
			return false;
		}
	private:
		ZOOM_SDK_NAMESPACE::ISpeakerInfo* m_pInfo;
	};

	array<IMicInfoDotNetWrap^ >^ CAudioSettingContextDotNetWrap::GetMicList()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return nullptr;

		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMicInfo* >* plst = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings()
			->GetMicList();
		if (plst && plst->GetCount())
		{
			int count = plst->GetCount();
			array<IMicInfoDotNetWrap^ >^ aryCamera = gcnew array<IMicInfoDotNetWrap^ >(count);
			if (aryCamera)
			{
				for (int i = 0; i < count; i++)
				{
					aryCamera[i] = gcnew CMicInfoDotNetWrap(plst->GetItem(i));
				}

				return aryCamera;
			}
		}

		return nullptr;
	}

	SDKError CAudioSettingContextDotNetWrap::SelectMic(String^ deviceId, String^ deviceName)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->SelectMic(PlatformString2WChar(deviceId), PlatformString2WChar(deviceName));
	}

	array<ISpeakerInfoDotNetWrap^ >^ CAudioSettingContextDotNetWrap::GetSpeakerList()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return nullptr;

		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ISpeakerInfo* >* plst = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings()
			->GetSpeakerList();
		if (plst && plst->GetCount())
		{
			int count = plst->GetCount();
			array<ISpeakerInfoDotNetWrap^ >^ aryCamera = gcnew array<ISpeakerInfoDotNetWrap^ >(count);
			if (aryCamera)
			{
				for (int i = 0; i < count; i++)
				{
					aryCamera[i] = gcnew CSpeakerInfoDotNetWrap(plst->GetItem(i));
				}

				return aryCamera;
			}
		}

		return nullptr;
	}

	SDKError CAudioSettingContextDotNetWrap::SelectSpeaker(String^ deviceId, String^ deviceName)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->SelectSpeaker(PlatformString2WChar(deviceId), PlatformString2WChar(deviceName));
	}

	SDKError CAudioSettingContextDotNetWrap::EnableAutoJoinAudio(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->EnableAutoJoinAudio(bEnable);
	}

	bool CAudioSettingContextDotNetWrap::IsAutoJoinAudioEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->IsAutoJoinAudioEnabled();
	}

	SDKError CAudioSettingContextDotNetWrap::EnableAutoAdjustMic(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->EnableAutoAdjustMic(bEnable);
	}

	bool CAudioSettingContextDotNetWrap::IsAutoAdjustMicEnabled()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->IsAutoAdjustMicEnabled();
	}

	SDKError CAudioSettingContextDotNetWrap::EnableStereoAudio(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->EnableStereoAudio(bEnable);
	}

	bool CAudioSettingContextDotNetWrap::IsStereoAudioEnable()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->IsStereoAudioEnable();
	}

	SDKError CAudioSettingContextDotNetWrap::EnableMicOriginalInput(bool bEnable)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->EnableMicOriginalInput(bEnable);
	}

	bool CAudioSettingContextDotNetWrap::IsMicOriginalInputEnable()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetAudioSettings())
			return false;

		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetAudioSettings()->IsMicOriginalInputEnable();
	}

	//CRecordingSettingContextDotNetWrap
	SDKError CRecordingSettingContextDotNetWrap::SetRecordingPath(String^ szPath)
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetRecordingSettings())
			return SDKError::SDKERR_INVALID_PARAMETER;

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetRecordingSettings()->SetRecordingPath(PlatformString2WChar(szPath));
	}

	String^  CRecordingSettingContextDotNetWrap::GetRecordingPath()
	{
		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetRecordingSettings())
			return nullptr;

		return WChar2PlatformString(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetRecordingSettings()->GetRecordingPath());
	}

	//CStatisticSettingContextDotNetWrap
	static void Convert(OverallStatisticInfo^% info_, ZOOM_SDK_NAMESPACE::OverallStatisticInfo& info_c_)
	{
		if (nullptr == info_)
			return;

		info_->connection_type_ = (SettingConnectionType)info_c_.connection_type_;
		info_->net_work_type_ = (SettingsNetWorkType)info_c_.net_work_type_;
		info_->proxy_addr_ = WChar2PlatformString(info_c_.proxy_addr_);
	}
	SDKError CStatisticSettingContextDotNetWrap::QueryOverallStatisticInfo(OverallStatisticInfo^% info_)
	{
		if (nullptr == info_)
			return SDKError::SDKERR_INVALID_PARAMETER;

		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		ZOOM_SDK_NAMESPACE::OverallStatisticInfo info_c_;
		SDKError err_ = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetStatisticSettings()->QueryOverallStatisticInfo(info_c_);
		Convert(info_, info_c_);

		return err_;
	}

	static void Convert(AudioSessionStatisticInfo^% info_, ZOOM_SDK_NAMESPACE::AudioSessionStatisticInfo& info_c_)
	{
		if (nullptr == info_)
			return;
		info_->frequency_send_ = info_c_.frequency_send_;
		info_->frequency_recv_ = info_c_.frequency_recv_;
		info_->latency_send_ = info_c_.latency_send_;
		info_->latency_recv_ = info_c_.latency_recv_;
		info_->jitter_send_ = info_c_.jitter_send_;
		info_->jitter_recv_ = info_c_.jitter_recv_;
		info_->packetloss_send_ = info_c_.packetloss_send_;
		info_->packetloss_recv_ = info_c_.packetloss_recv_;
	}
	SDKError CStatisticSettingContextDotNetWrap::QueryAudioStatisticInfo(AudioSessionStatisticInfo^% info_)
	{
		if (nullptr == info_)
			return SDKError::SDKERR_INVALID_PARAMETER;

		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		ZOOM_SDK_NAMESPACE::AudioSessionStatisticInfo info_c_;
		SDKError err_ = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetStatisticSettings()->QueryAudioStatisticInfo(info_c_);
		Convert(info_, info_c_);

		return err_;
	}

	static void Convert(ASVSessionStatisticInfo^% info_, ZOOM_SDK_NAMESPACE::ASVSessionStatisticInfo& info_c_)
	{
		if (nullptr == info_)
			return;

		info_->latency_send_ = info_c_.latency_send_;
		info_->latency_recv_ = info_c_.latency_recv_;
		info_->jitter_send_ = info_c_.jitter_send_;
		info_->jitter_recv_ = info_c_.jitter_recv_;
		info_->packetloss_send_max_ = info_c_.packetloss_send_max_;
		info_->packetloss_recv_max_ = info_c_.packetloss_recv_max_;
		info_->packetloss_send_avg_ = info_c_.packetloss_send_avg_;
		info_->packetloss_recv_avg_ = info_c_.packetloss_recv_avg_;
		info_->resolution_send_ = info_c_.resolution_send_;
		info_->resolution_recv_ = info_c_.resolution_recv_;
		info_->fps_send_ = info_c_.fps_send_;
		info_->fps_recv_ = info_c_.fps_recv_;
	}
	SDKError CStatisticSettingContextDotNetWrap::QueryVideoStatisticInfo(ASVSessionStatisticInfo^% info_)
	{
		if (nullptr == info_)
			return SDKError::SDKERR_INVALID_PARAMETER;

		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		ZOOM_SDK_NAMESPACE::ASVSessionStatisticInfo info_c_;
		SDKError err_ = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetStatisticSettings()->QueryVideoStatisticInfo(info_c_);
		Convert(info_, info_c_);

		return err_;
	}

	SDKError CStatisticSettingContextDotNetWrap::QueryShareStatisticInfo(ASVSessionStatisticInfo^% info_)
	{
		if (nullptr == info_)
			return SDKError::SDKERR_INVALID_PARAMETER;

		if (NULL == ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings())
			return SDKError::SDKERR_UNINITIALIZE;

		ZOOM_SDK_NAMESPACE::ASVSessionStatisticInfo info_c_;
		SDKError err_ = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().
			GetStatisticSettings()->QueryShareStatisticInfo(info_c_);
		Convert(info_, info_c_);

		return err_;
	}
}