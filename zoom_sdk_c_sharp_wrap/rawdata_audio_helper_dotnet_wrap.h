#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "h/zoom_sdk_raw_data_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public ref class DotNetAudioRawData
	{
	public:
		bool CanAddRef() {
			return _data->CanAddRef();
		}
		bool AddRef() {
			return _data->AddRef();
		}
		int Release() {
			return _data->Release();
		}
		array<Byte>^ GetBuffer() {
			char* buf = _data->GetBuffer();
			unsigned int len = _data->GetBufferLen();
			array<Byte>^ byteArray = gcnew array< Byte >(len + 2);
			// convert native pointer to System::IntPtr with C-Style cast
			Marshal::Copy((IntPtr)buf, byteArray, 0, len);
			return byteArray;
		}
		UInt32 GetBufferLen() {
			return _data->GetBufferLen();
		}
		UInt32 GetSampleRate() {
			return _data->GetSampleRate();
		}
	private:
		AudioRawData* _data;
	public:
		DotNetAudioRawData(AudioRawData* data) {
			_data = data;
		}
	};

	public interface class IZoomSDKAudioRawDataDotNetDelegate {
	public:
		void onMixedAudioRawDataReceived(DotNetAudioRawData^ data_);
		void onOneWayAudioRawDataReceived(DotNetAudioRawData^ data_, UInt32 node_id);
	};

	public interface class IZoomSDKAudioRawDataDotNetHelper {
	public:
		SDKError subscribe(IZoomSDKAudioRawDataDotNetDelegate^ pDelegate);
		SDKError unSubscribe();
	};
	
	private ref class CRawDataAudioDotNetWrap : IZoomSDKAudioRawDataDotNetHelper {
	public:
		static property CRawDataAudioDotNetWrap^ Instance
		{
			CRawDataAudioDotNetWrap^ get() { return m_Instance; }
		}
		virtual SDKError subscribe(IZoomSDKAudioRawDataDotNetDelegate^ pDelegate);
		virtual SDKError unSubscribe();
	private: 
		CRawDataAudioDotNetWrap();
		virtual ~CRawDataAudioDotNetWrap();
		static CRawDataAudioDotNetWrap^ m_Instance = gcnew CRawDataAudioDotNetWrap;
	};
}
