#include "stdafx.h"
#include "video_setting_context_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {


	private ref class CCameraInfoDotNetWrap sealed : public ICameraInfoDotNetWrap
	{
	public:
		CCameraInfoDotNetWrap(ZOOM_SDK_NAMESPACE::ICameraInfo* pSDKObj)
		{
			m_pSDKObj = pSDKObj;
		}

		virtual String^ GetDeviceId()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetDeviceId());
			}

			return nullptr;
		}

		virtual String^ GetDeviceName()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetDeviceName());
			}

			return nullptr;
		}

		virtual bool IsSelectedDevice()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsSelectedDevice();
			}

			return false;
		}

	private:
		ZOOM_SDK_NAMESPACE::ICameraInfo* m_pSDKObj;
	};


	class VideoSettingContextEventHandler
	{
	public:
		static VideoSettingContextEventHandler& GetInst()
		{
			static VideoSettingContextEventHandler instance;
			return instance;
		}

		void onComputerCamDeviceChanged(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo* >* newCameras)
		{
			if (CVideoSettingContextDotNetWrap::Instance)
			{
				CVideoSettingContextDotNetWrap::Instance->procComputerCamDeviceChanged(CVideoSettingContextDotNetWrap::ConvertCameraList(newCameras));
			}
		}

	private:
		VideoSettingContextEventHandler() {};
	};
	//

	void CVideoSettingContextDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IVideoSettingContextWrap& videoSettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings();
		videoSettingContext.m_cbonComputerCamDeviceChanged =
			std::bind(&VideoSettingContextEventHandler::onComputerCamDeviceChanged,
				&VideoSettingContextEventHandler::GetInst(), std::placeholders::_1);
	}

	array<ICameraInfoDotNetWrap^ >^ CVideoSettingContextDotNetWrap::GetCameraList()
	{
		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo* >* pList = 
			ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings().GetCameraList();

		return ConvertCameraList(pList);
	}

	SDKError CVideoSettingContextDotNetWrap::SelectCamera(String^ deviceId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.SelectCamera(PlatformString2WChar(deviceId));
	}

	SDKError CVideoSettingContextDotNetWrap::EnableVideoMirrorEffect(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableVideoMirrorEffect(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsVideoMirrorEffectEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsVideoMirrorEffectEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableFaceBeautyEffect(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableFaceBeautyEffect(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsFaceBeautyEffectEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsFaceBeautyEffectEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableHDVideo(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableHDVideo(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsHDVideoEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsHDVideoEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableAlwaysShowNameOnVideo(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableAlwaysShowNameOnVideo(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsAlwaysShowNameOnVideoEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsAlwaysShowNameOnVideoEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableAutoTurnOffVideoWhenJoinMeeting(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsAutoTurnOffVideoWhenJoinMeetingEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableAlwaysUse16v9(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableAlwaysUse16v9(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsAlwaysUse16v9()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsAlwaysUse16v9();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableSpotlightSelf(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableSpotlightSelf(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsSpotlightSelfEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsSpotlightSelfEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableHardwareEncode(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableHardwareEncode(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsHardwareEncodeEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsHardwareEncodeEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::Enable49VideoesInGallaryView(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.Enable49VideoesInGallaryView(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::Is49VideoesInGallaryViewEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.Is49VideoesInGallaryViewEnabled();
	}

	SDKError CVideoSettingContextDotNetWrap::EnableHideNoVideoUsersOnWallView(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.EnableHideNoVideoUsersOnWallView(bEnable);
	}

	bool CVideoSettingContextDotNetWrap::IsHideNoVideoUsersOnWallViewEnabled()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetVideoSettings()
			.IsHideNoVideoUsersOnWallViewEnabled();
	}

	void CVideoSettingContextDotNetWrap::procComputerCamDeviceChanged(array<ICameraInfoDotNetWrap^>^ newCameras)
	{
		event_onComputerCamDeviceChanged(newCameras);
	}

	array<ICameraInfoDotNetWrap^>^ CVideoSettingContextDotNetWrap::ConvertCameraList(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo*>* pList)
	{
		if (NULL == pList || pList->GetCount() <= 0)
		{
			return nullptr;
		}

		int count = pList->GetCount();
		array<ICameraInfoDotNetWrap^ >^ cameras = gcnew array<ICameraInfoDotNetWrap^ >(count);
		if (nullptr == cameras)
		{
			return nullptr;
		}

		for (int i(0); i < count; i++)
		{
			cameras[i] = gcnew CCameraInfoDotNetWrap(pList->GetItem(i));
		}

		return cameras;
	}
}