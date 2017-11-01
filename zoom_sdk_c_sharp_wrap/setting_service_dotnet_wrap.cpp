#include "stdafx.h"
#include "setting_service_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	SDKError CSettingServiceDotNetWrap::ShowSettingDlg(ShowSettingDlgParam^ param)
	{
		if (nullptr == param)
			return SDKError::SDKERR_INVALID_PARAMETER;

		ZOOM_SDK_NAMESPACE::ShowSettingDlgParam param_c;
		param_c.hParent = (HWND)param->hParent.value;
		param_c.bShow = param->bShow;
		param_c.left = param->left;
		param_c.top = param->top;

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

	//CVideoSettingContextDotNetWrap
	public ref class CCameraInfoDotNetWrap sealed : public ICameraInfoDotNetWrap
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

	//CAudioSettingContextDotNetWrap
	public ref class CMicInfoDotNetWrap sealed : public IMicInfoDotNetWrap
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

	public ref class CSpeakerInfoDotNetWrap sealed : public ISpeakerInfoDotNetWrap
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
}