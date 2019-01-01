#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class LiveStreamStatus : int
	{
		LiveStreamStatus_None,
		LiveStreamStatus_InProgress,
		LiveStreamStatus_Connecting,
		LiveStreamStatus_Start_Failed_Timeout,
		LiveStreamStatus_Start_Failed,
		LiveStreamStatus_Ended,
	};

	public interface class IMeetingLiveStreamItemDotNetWrap
	{
	public:
		String^ GetLiveStreamURL();
		String^ GetLiveStreamURLDescription();
	};

	public delegate void onLiveStreamStatusChange(LiveStreamStatus status);

	public interface class IMeetingLiveStreamControllerDotNetWrap
	{
	public:
		SDKError CanStartLiveStream();
		SDKError StartLiveStream(IMeetingLiveStreamItemDotNetWrap^ item_);
		SDKError StartLiveStreamWithStreamingURL(String^ streamingURL, String^ streamingKey, String^ broadcastURL);
		SDKError StopLiveStream();
		array<IMeetingLiveStreamItemDotNetWrap^>^ GetSupportLiveStreamURL();
		LiveStreamStatus GetCurrentLiveStreamStatus();
		void Add_CB_onLiveStreamStatusChange(onLiveStreamStatusChange^ cb);
		void Remove_CB_onLiveStreamStatusChange(onLiveStreamStatusChange^ cb);
	};

	private ref class CMeetingLiveStreamControllerDotNetWrap : public IMeetingLiveStreamControllerDotNetWrap
	{
	public:
		static property CMeetingLiveStreamControllerDotNetWrap^ Instance
		{
			CMeetingLiveStreamControllerDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError CanStartLiveStream();
		virtual SDKError StartLiveStream(IMeetingLiveStreamItemDotNetWrap^ item_);
		virtual SDKError StartLiveStreamWithStreamingURL(String^ streamingURL, String^ streamingKey, String^ broadcastURL);
		virtual SDKError StopLiveStream();
		virtual array<IMeetingLiveStreamItemDotNetWrap^>^ GetSupportLiveStreamURL();
		virtual LiveStreamStatus GetCurrentLiveStreamStatus();

		virtual void Add_CB_onLiveStreamStatusChange(onLiveStreamStatusChange^ cb)
		{
			event_onLiveStreamStatusChange += cb;
		}

		virtual void Remove_CB_onLiveStreamStatusChange(onLiveStreamStatusChange^ cb)
		{
			event_onLiveStreamStatusChange -= cb;
		}

		void BindEvent();
		void procLiveStreamStatusChange(LiveStreamStatus status);

	private:
		event onLiveStreamStatusChange^ event_onLiveStreamStatusChange;
		static CMeetingLiveStreamControllerDotNetWrap^ m_Instance = gcnew CMeetingLiveStreamControllerDotNetWrap;
	};
}