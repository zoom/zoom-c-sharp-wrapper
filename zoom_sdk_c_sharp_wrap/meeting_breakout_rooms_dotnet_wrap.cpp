#include "stdafx.h"
#include "meeting_breakout_rooms_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate bo info
	private ref class IBreakoutRoomsInfoDotNetImpl sealed : public IBreakoutRoomsInfoDotNet
	{
	public:
		IBreakoutRoomsInfoDotNetImpl(ZOOM_SDK_NAMESPACE::IBreakoutRoomsInfo* pInfo)
		{
			m_pInfo = pInfo;
		}
		virtual String^ GetBID()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetBID());
			return nullptr;
		}
		virtual String^ GetBreakoutRoomName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetBreakoutRoomName());
			return nullptr;
		}

	private:
		IBreakoutRoomsInfoDotNetImpl() {}
		ZOOM_SDK_NAMESPACE::IBreakoutRoomsInfo* m_pInfo;
	};
	//
	//translate event
	class MeetingBreakoutRoomsControllerEventHanlder
	{
	public:
		static MeetingBreakoutRoomsControllerEventHanlder& GetInst()
		{
			static MeetingBreakoutRoomsControllerEventHanlder inst;
			return inst;
		}

		void OnBreakoutRoomsStartedNotification(const wchar_t* stBID)
		{
			if (CMeetingBreakoutRoomsControllerDotNetWrap::Instance)
				CMeetingBreakoutRoomsControllerDotNetWrap::Instance->ProcBreakoutRoomsStartedNotification(WChar2PlatformString(stBID));
		}
	private:
		MeetingBreakoutRoomsControllerEventHanlder() {};
	};
	//

	void CMeetingBreakoutRoomsControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingBreakoutRoomsControllerWrap& meetingBO = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingBreakoutRoomsController();
		meetingBO.m_cbOnBreakoutRoomsStartedNotification =
			std::bind(&MeetingBreakoutRoomsControllerEventHanlder::OnBreakoutRoomsStartedNotification,
				&MeetingBreakoutRoomsControllerEventHanlder::GetInst(), std::placeholders::_1);
	}

	void CMeetingBreakoutRoomsControllerDotNetWrap::ProcBreakoutRoomsStartedNotification(String^ stBID)
	{
		event_OnBreakoutRoomsStartedNotification(stBID);
	}

	SDKError CMeetingBreakoutRoomsControllerDotNetWrap::JoinBreakoutRoom(String^ stBID)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingBreakoutRoomsController().JoinBreakoutRoom(PlatformString2WChar(stBID));
	}

	SDKError CMeetingBreakoutRoomsControllerDotNetWrap::LeaveBreakoutRoom()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingBreakoutRoomsController().LeaveBreakoutRoom();
	}

	array<IBreakoutRoomsInfoDotNet^ >^ CMeetingBreakoutRoomsControllerDotNetWrap::GetBreakoutRoomsInfoList()
	{
		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IBreakoutRoomsInfo* >* plst = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingBreakoutRoomsController().GetBreakoutRoomsInfoList();
		if (plst && plst->GetCount() > 0)
		{
			int count = plst->GetCount();
			array<IBreakoutRoomsInfoDotNet^ >^ aryInfo = gcnew array<IBreakoutRoomsInfoDotNet^ >(count);
			if (aryInfo)
			{
				for (int i = 0; i < count; i++)
				{
					IBreakoutRoomsInfoDotNet^ infoItem = gcnew IBreakoutRoomsInfoDotNetImpl(plst->GetItem(i));
					aryInfo[i] = infoItem;
				}
				return aryInfo;
			}
		}

		return nullptr;
	}
}