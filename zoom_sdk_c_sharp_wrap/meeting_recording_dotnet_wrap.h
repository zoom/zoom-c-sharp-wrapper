#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class RecordingLayoutMode : int
	{
		RecordingLayoutMode_None = 0,
		RecordingLayoutMode_ActiveVideoOnly = 1,
		RecordingLayoutMode_VideoWall = (1 << 1),
		RecordingLayoutMode_ShareAndVideo = (1 << 2),
		RecordingLayoutMode_OnlyAudio = (1 << 3),
		RecordingLayoutMode_OnlyShare = (1 << 4),
	};

	public interface class ICustomizedLocalRecordingLayoutHelperDotNetWrap
	{
	public:
		int GetSupportLayout();
		array<unsigned int>^ GetValidVideoSourceList();
		array<unsigned int>^ GetValidRecvSharingSourceList();
		bool IsSendSharingSourceAvailable();
		bool HasActiveVideoSource();
		SDKError SelectRecordingLayoutMode(RecordingLayoutMode mode);
		SDKError AddVideoSourceToRecList(unsigned int userId);
		SDKError SelectActiveVideoSource();
		SDKError SelectRecvSharingSource(unsigned int userId);
		SDKError SelectSendSharingSource();
	};

	public enum class RecordingStatus : int
	{
		Recording_Start,
		Recording_Stop,
		Recording_DiskFull,
	};

	public delegate void onRecording2MP4Done(bool bsuccess, int iResult, String^ szPath);
	public delegate void onRecording2MP4Processing(int iPercentage);
	public delegate void onRecordingStatus(RecordingStatus status);
	public delegate void onRecordPriviligeChanged(bool bCanRec);

	public interface class IMeetingRecordingControllerDotNetWrap
	{
	public:
		SDKError StartRecording(DateTime^% startTimestamp, String^ recPath);
		SDKError StopRecording(DateTime^% stopTimestamp);
		void Add_CB_onRecording2MP4Done(onRecording2MP4Done^ cb);
		void Add_CB_onRecording2MP4Processing(onRecording2MP4Processing^ cb);
		void Add_CB_onRecordingStatus(onRecordingStatus^ cb);
		void Add_CB_onRecordPriviligeChanged(onRecordPriviligeChanged^ cb);
	};

	private ref class CMeetingRecordingControllerDotNetWrap : public IMeetingRecordingControllerDotNetWrap
	{
	public:
		static property CMeetingRecordingControllerDotNetWrap^ Instance
		{
			CMeetingRecordingControllerDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError StartRecording(DateTime^% startTimestamp, String^ recPath);
		virtual SDKError StopRecording(DateTime^% stopTimestamp);

		virtual void Add_CB_onRecording2MP4Done(onRecording2MP4Done^ cb)
		{
			event_onRecording2MP4Done += cb;
		}

		virtual void Add_CB_onRecording2MP4Processing(onRecording2MP4Processing^ cb)
		{
			event_onRecording2MP4Processing += cb;
		}

		virtual void Add_CB_onRecordingStatus(onRecordingStatus^ cb)
		{
			event_onRecordingStatus += cb;
		}

		virtual void Add_CB_onRecordPriviligeChanged(onRecordPriviligeChanged^ cb)
		{
			event_onRecordPriviligeChanged += cb;
		}

		void BindEvent();
		void procRecording2MP4Done(bool bsuccess, int iResult, String^ szPath);
		void procRecording2MP4Processing(int iPercentage);
		void procRecordingStatus(RecordingStatus status);
		void procRecordPriviligeChanged(bool bCanRec);
	private:
		event onRecording2MP4Done^ event_onRecording2MP4Done;
		event onRecording2MP4Processing^ event_onRecording2MP4Processing;
		event onRecordingStatus^ event_onRecordingStatus;
		event onRecordPriviligeChanged^ event_onRecordPriviligeChanged;
		static CMeetingRecordingControllerDotNetWrap^ m_Instance = gcnew CMeetingRecordingControllerDotNetWrap;
	};
}