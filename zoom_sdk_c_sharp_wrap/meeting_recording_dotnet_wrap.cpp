#include "stdafx.h"
#include "meeting_recording_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	//translate event
	class MeetingRecordingControllerEventHanlder
	{
	public:
		static MeetingRecordingControllerEventHanlder& GetInst()
		{
			static MeetingRecordingControllerEventHanlder inst;
			return inst;
		}

		virtual void onRecording2MP4Done(bool bsuccess, int iResult, const wchar_t* szPath)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecording2MP4Done(bsuccess, iResult, WChar2PlatformString(szPath));
		}

		virtual void onRecording2MP4Processing(int iPercentage)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecording2MP4Processing(iPercentage);
		}

		virtual void onRecordingStatus(ZOOM_SDK_NAMESPACE::RecordingStatus status)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecordingStatus((RecordingStatus)status);
		}

		virtual void onRecordPriviligeChanged(bool bCanRec)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecordPriviligeChanged(bCanRec);
		}
	private:
		MeetingRecordingControllerEventHanlder() {}
	};
	//

	SDKError CMeetingRecordingControllerDotNetWrap::StartRecording(DateTime^% startTimestamp, String^ recPath)
	{
		time_t time_c;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().StartRecording(time_c, const_cast<wchar_t*>(PlatformString2WChar(recPath)));

		if (startTimestamp)
			startTimestamp = time_t2DateTime(time_c);
		
		return err;
	}

	SDKError CMeetingRecordingControllerDotNetWrap::StopRecording(DateTime^% stopTimestamp)
	{
		time_t time_c;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().StopRecording(time_c);

		if (stopTimestamp)
			stopTimestamp = time_t2DateTime(time_c);

		return err;
	}

	void CMeetingRecordingControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingRecordingControllerWrap& meetingRec = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingRecordingController();
		meetingRec.m_cbonRecording2MP4Done =
			std::bind(&MeetingRecordingControllerEventHanlder::onRecording2MP4Done, 
				&MeetingRecordingControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		meetingRec.m_cbonRecording2MP4Processing =
			std::bind(&MeetingRecordingControllerEventHanlder::onRecording2MP4Processing,
				&MeetingRecordingControllerEventHanlder::GetInst(), std::placeholders::_1);
		meetingRec.m_cbonRecordingStatus =
			std::bind(&MeetingRecordingControllerEventHanlder::onRecordingStatus,
				&MeetingRecordingControllerEventHanlder::GetInst(), std::placeholders::_1);
		meetingRec.m_cbonRecordPriviligeChanged =
			std::bind(&MeetingRecordingControllerEventHanlder::onRecordPriviligeChanged,
				&MeetingRecordingControllerEventHanlder::GetInst(), std::placeholders::_1);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecording2MP4Done(bool bsuccess, int iResult, String^ szPath)
	{
		event_onRecording2MP4Done(bsuccess, iResult, szPath);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecording2MP4Processing(int iPercentage)
	{
		event_onRecording2MP4Processing(iPercentage);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecordingStatus(RecordingStatus status)
	{
		event_onRecordingStatus(status);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecordPriviligeChanged(bool bCanRec)
	{
		event_onRecordPriviligeChanged(bCanRec);
	}
}