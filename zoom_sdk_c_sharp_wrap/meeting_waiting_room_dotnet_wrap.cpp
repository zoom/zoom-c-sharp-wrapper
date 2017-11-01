#include "stdafx.h"
#include "meeting_waiting_room_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate event
	class MeetingWaitingRoomControllerEventHanlder
	{
	public:
		static MeetingWaitingRoomControllerEventHanlder& GetInst()
		{
			static MeetingWaitingRoomControllerEventHanlder inst;
			return inst;
		}
		void onWatingRoomUserJoin(unsigned int userID)
		{
			if (CMeetingWaitingRoomControllerDotNetWrap::Instance)
				CMeetingWaitingRoomControllerDotNetWrap::Instance->procWatingRoomUserJoin(userID);
		}

		void onWatingRoomUserLeft(unsigned int userID)
		{
			if (CMeetingWaitingRoomControllerDotNetWrap::Instance)
				CMeetingWaitingRoomControllerDotNetWrap::Instance->procWatingRoomUserLeft(userID);
		}
	private:
		MeetingWaitingRoomControllerEventHanlder() {}
	};

	//
	void CMeetingWaitingRoomControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingWaitingRoomControllerWrap& meetingWait = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController();
		meetingWait.m_cbonWatingRoomUserJoin =
			std::bind(&MeetingWaitingRoomControllerEventHanlder::onWatingRoomUserJoin,
				&MeetingWaitingRoomControllerEventHanlder::GetInst(), std::placeholders::_1);
		meetingWait.m_cbonWatingRoomUserLeft =
			std::bind(&MeetingWaitingRoomControllerEventHanlder::onWatingRoomUserLeft,
				&MeetingWaitingRoomControllerEventHanlder::GetInst(), std::placeholders::_1);
	}

	void CMeetingWaitingRoomControllerDotNetWrap::procWatingRoomUserJoin(unsigned int userID)
	{
		event_onWatingRoomUserJoin(userID);
	}

	void CMeetingWaitingRoomControllerDotNetWrap::procWatingRoomUserLeft(unsigned int userID)
	{
		event_onWatingRoomUserLeft(userID);
	}

	bool CMeetingWaitingRoomControllerDotNetWrap::IsSupportWaitingRoom()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().IsSupportWaitingRoom();
	}

	bool CMeetingWaitingRoomControllerDotNetWrap::IsWaitingRoomOnEntryFlagOn()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().IsWaitingRoomOnEntryFlagOn();
	}

	SDKError CMeetingWaitingRoomControllerDotNetWrap::EnableWaitingRoomOnEntry(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().EnableWaitingRoomOnEntry(bEnable);
	}

	array<unsigned int >^ CMeetingWaitingRoomControllerDotNetWrap::GetWaitingRoomLst()
	{
		ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstInWaiting = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().GetWaitingRoomLst();
		if (lstInWaiting && lstInWaiting->GetCount() > 0)
		{
			return Convert(lstInWaiting);
		}

		return nullptr;
	}

	IUserInfoDotNetWrap^ CMeetingWaitingRoomControllerDotNetWrap::GetWaitingRoomUserInfoByID(unsigned int userid)
	{
		return gcnew IUserInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().GetWaitingRoomUserInfoByID(userid));
	}

	SDKError CMeetingWaitingRoomControllerDotNetWrap::AdmitToMeeting(unsigned int userid)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().AdmitToMeeting(userid);
	}

	SDKError CMeetingWaitingRoomControllerDotNetWrap::PutInWaitingRoom(unsigned int userid)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingWaitingRoomController().PutInWaitingRoom(userid);
	}
}