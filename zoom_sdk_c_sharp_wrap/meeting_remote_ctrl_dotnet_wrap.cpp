#include "stdafx.h"
#include "meeting_remote_ctrl_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate event
	class MeetingRemoteControllerEventHanlder
	{
	public:
		static MeetingRemoteControllerEventHanlder& GetInst()
		{
			static MeetingRemoteControllerEventHanlder inst;
			return inst;
		}
		void onRemoteControlStatus(ZOOM_SDK_NAMESPACE::RemoteControlStatus status, unsigned int userId)
		{
			if (CMeetingRemoteControllerDotNetWrap::Instance)
				CMeetingRemoteControllerDotNetWrap::Instance->ProcRemoteControlStatus((RemoteControlStatus)status, userId);
		}

	private:
		MeetingRemoteControllerEventHanlder() {}
	};
	//

	void CMeetingRemoteControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingRemoteController().m_cbonRemoteControlStatus =
			std::bind(&MeetingRemoteControllerEventHanlder::onRemoteControlStatus,
				&MeetingRemoteControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	void CMeetingRemoteControllerDotNetWrap::ProcRemoteControlStatus(RemoteControlStatus status, unsigned int userId)
	{
		event_onRemoteControlStatus(status, userId);
	}

	SDKError CMeetingRemoteControllerDotNetWrap::RequestRemoteControl(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRemoteController().RequestRemoteControl(userId);
	}

	SDKError CMeetingRemoteControllerDotNetWrap::GiveupRemoteControl(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRemoteController().GiveupRemoteControl(userId);
	}

	SDKError CMeetingRemoteControllerDotNetWrap::GiveRemoteControlTo(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRemoteController().GiveRemoteControlTo(userId);
	}

	SDKError CMeetingRemoteControllerDotNetWrap::DeclineRemoteControlRequest(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRemoteController().DeclineRemoteControlRequest(userId);
	}

	SDKError CMeetingRemoteControllerDotNetWrap::RevokeRemoteControl()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRemoteController().RevokeRemoteControl();
	}

	SDKError CMeetingRemoteControllerDotNetWrap::GetCurrentRemoteController(unsigned int^% userId)
	{
		unsigned int userid_c(0);
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRemoteController().GetCurrentRemoteController(userid_c);

		if (userId)
			userId = userid_c;

		return err;
	}
}