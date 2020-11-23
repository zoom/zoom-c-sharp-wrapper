#include "Stdafx.h"
#include "rawdata_audio_helper_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {
	class ZoomSDKAudioRawDataDelegate : public ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataDelegate
	{
	public:
		virtual void onMixedAudioRawDataReceived(AudioRawData* data_)
		{
			DotNetAudioRawData^ data_c = gcnew DotNetAudioRawData(data_);
			_dotnetDelegate->onMixedAudioRawDataReceived(data_c);
		}

		virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, unsigned int node_id)
		{
			DotNetAudioRawData^ data_c = gcnew DotNetAudioRawData(data_);
			_dotnetDelegate->onOneWayAudioRawDataReceived(data_c, node_id);
		}

		ZoomSDKAudioRawDataDelegate(IZoomSDKAudioRawDataDotNetDelegate^ pDelegate) {
			_dotnetDelegate = pDelegate;
		}

	private:
		gcroot<IZoomSDKAudioRawDataDotNetDelegate^> _dotnetDelegate;
	};

	CRawDataAudioDotNetWrap::CRawDataAudioDotNetWrap() 
	{
	}

	CRawDataAudioDotNetWrap::~CRawDataAudioDotNetWrap()
	{
	}

	SDKError CRawDataAudioDotNetWrap::subscribe(IZoomSDKAudioRawDataDotNetDelegate^ pDelegate)
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAudioRawdataHelperWrap().Init();
		ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataDelegate* delegate_c = new ZoomSDKAudioRawDataDelegate(pDelegate);
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAudioRawdataHelperWrap().subscribe(delegate_c);
	}

	SDKError CRawDataAudioDotNetWrap::unSubscribe()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAudioRawdataHelperWrap().unSubscribe();
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAudioRawdataHelperWrap().Uninit();
	}
}