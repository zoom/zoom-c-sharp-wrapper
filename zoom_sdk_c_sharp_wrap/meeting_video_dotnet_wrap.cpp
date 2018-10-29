#include "stdafx.h"
#include "meeting_video_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	
	//translate event
	class MeetingVideoControllerEventHanlder
	{
	public:
		static MeetingVideoControllerEventHanlder& GetInst()
		{
			static MeetingVideoControllerEventHanlder inst;
			return inst;
		}
		void onUserVideoStatusChange(unsigned int userId, ZOOM_SDK_NAMESPACE::VideoStatus status)
		{
			if (CMeetingVideoControllerDotNetWrap::Instance)
				CMeetingVideoControllerDotNetWrap::Instance->ProcUserVideoStatusChange(userId, (VideoStatus)status);
		}

		void onSpotlightVideoChangeNotification(bool bSpotlight, unsigned int userid)
		{
			if (CMeetingVideoControllerDotNetWrap::Instance)
				CMeetingVideoControllerDotNetWrap::Instance->ProcSpotlightVideoChangeNotification(bSpotlight, userid);
		}
	private:
		MeetingVideoControllerEventHanlder() {}
	};
	//

	void CMeetingVideoControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingVideoController().m_cbonUserVideoStatusChange =
			std::bind(&MeetingVideoControllerEventHanlder::onUserVideoStatusChange,
				&MeetingVideoControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);

		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingVideoController().m_cbonSpotlightVideoChangeNotification =
			std::bind(&MeetingVideoControllerEventHanlder::onSpotlightVideoChangeNotification,
				&MeetingVideoControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	void CMeetingVideoControllerDotNetWrap::ProcUserVideoStatusChange(unsigned int userId, VideoStatus status)
	{
		event_onUserVideoStatusChange(userId, status);
	}

	void CMeetingVideoControllerDotNetWrap::ProcSpotlightVideoChangeNotification(bool bSpotlight, unsigned int userid)
	{
		event_onSpotlightVideoChangeNotification(bSpotlight, userid);
	}

	SDKError CMeetingVideoControllerDotNetWrap::MuteVideo()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingVideoController().MuteVideo();
	}

	SDKError CMeetingVideoControllerDotNetWrap::UnmuteVideo()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingVideoController().UnmuteVideo();
	}

	SDKError CMeetingVideoControllerDotNetWrap::PinVideo(bool bPin, bool bFirstView, unsigned int userid)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingVideoController().PinVideo(bPin, bFirstView, userid);
	}

	SDKError CMeetingVideoControllerDotNetWrap::SpotlightVideo(bool bSpotlight, unsigned int userid)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingVideoController().SpotlightVideo(bSpotlight, userid);
	}

	SDKError CMeetingVideoControllerDotNetWrap::HideOrShowNoVideoUserOnVideoWall(bool bHide)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingVideoController().HideOrShowNoVideoUserOnVideoWall(bHide);
	}
}