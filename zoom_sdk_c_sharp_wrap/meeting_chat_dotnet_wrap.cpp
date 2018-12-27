#include "stdafx.h"
#include "meeting_chat_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	//translate event
	private ref class IChatMsgInfoDotNetWrapImpl sealed : public IChatMsgInfoDotNetWrap
	{
	public:
		IChatMsgInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IChatMsgInfo* pChat)
		{
			m_pChat = pChat;
		}

		virtual unsigned int GetSenderUserId()
		{
			if (m_pChat)
				return m_pChat->GetSenderUserId();
			return 0;
		}

		virtual String^ GetSenderDisplayName()
		{
			if (m_pChat)
				return WChar2PlatformString(m_pChat->GetSenderDisplayName());
			return nullptr;
		}

		virtual unsigned int GetReceiverUserId()
		{
			if (m_pChat)
				return m_pChat->GetReceiverUserId();
			return 0;
		}

		virtual String^ GetReceiverDisplayName()
		{
			if (m_pChat)
				return WChar2PlatformString(m_pChat->GetReceiverDisplayName());
			return nullptr;
		}

		virtual String^ GetContent()
		{
			if (m_pChat)
				return WChar2PlatformString(m_pChat->GetContent());
			return nullptr;
		}

		virtual Nullable<DateTime> GetTimeStamp()
		{
			if (m_pChat)
			{
				Nullable<DateTime> time = time_t2DateTime(m_pChat->GetTimeStamp());
				return time;
			}
			return Nullable<DateTime>();
		}

	private:
		ZOOM_SDK_NAMESPACE::IChatMsgInfo* m_pChat;

	};

	class MeetingChatControllerEventHanlder
	{
	public:
		static MeetingChatControllerEventHanlder& GetInst()
		{
			static MeetingChatControllerEventHanlder inst;
			return inst;
		}
		
		void onChatMsgNotifcation(ZOOM_SDK_NAMESPACE::IChatMsgInfo* chatMsg, const wchar_t* content)
		{
			if (CMeetingChatControllerDotNetWrap::Instance && chatMsg)
			{
				CMeetingChatControllerDotNetWrap::Instance->procChatMsgNotifcation(gcnew IChatMsgInfoDotNetWrapImpl(chatMsg));
			}
		}

		void onChatStatusChangedNotifcation(ZOOM_SDK_NAMESPACE::ChatStatus* status)
		{
			if (CMeetingChatControllerDotNetWrap::Instance)
			{
				ChatStatus^ chatstatus_dotnet = gcnew ChatStatus;
				if (chatstatus_dotnet)
				{
					chatstatus_dotnet->isChatOff = status->is_chat_off;
					chatstatus_dotnet->isWebinarAttendee = status->is_webinar_attendee;
					chatstatus_dotnet->isWebinarMeeting = status->is_webinar_meeting;

					if (chatstatus_dotnet->isWebinarMeeting)
					{
						if (chatstatus_dotnet->isWebinarAttendee)
						{
							chatstatus_dotnet->webinarAttendeeStatus = gcnew WebinarAttendeeChatStatus;
							chatstatus_dotnet->webinarAttendeeStatus->canChat = status->ut.webinar_attendee_status.can_chat;
							chatstatus_dotnet->webinarAttendeeStatus->canChatToAllPanelListAndAttendee = status->ut.webinar_attendee_status.can_chat_to_all_panellist_and_attendee;
							chatstatus_dotnet->webinarAttendeeStatus->canChatToAllPanelList = status->ut.webinar_attendee_status.can_chat_to_all_panellist;
						}
						else
						{
							chatstatus_dotnet->webinarOtherStatus = gcnew WebinarOtherUserRoleChatStatus;
							chatstatus_dotnet->webinarOtherStatus->canChatToAllPanelList = status->ut.webinar_other_status.can_chat_to_all_panellist;
							chatstatus_dotnet->webinarOtherStatus->canChatToAllPanelListAndAttendee = status->ut.webinar_other_status.can_chat_to_all_panellist_and_attendee;
							chatstatus_dotnet->webinarOtherStatus->canChatToIndividual = status->ut.webinar_other_status.can_chat_to_individual;
						}
					}
					else
					{
						chatstatus_dotnet->normalMeetingStatus = gcnew NormalMeetingChatStatus;
						chatstatus_dotnet->normalMeetingStatus->canChatToAll = status->ut.normal_meeting_status.can_chat_to_all;
						chatstatus_dotnet->normalMeetingStatus->canChatToIndividual = status->ut.normal_meeting_status.can_chat_to_individual;
						chatstatus_dotnet->normalMeetingStatus->isOnlyCanChatToHost = status->ut.normal_meeting_status.is_only_can_chat_to_host;
					}
				}

				CMeetingChatControllerDotNetWrap::Instance->procChatStatusChangedNotification(chatstatus_dotnet);
			}
		}

	private:
		MeetingChatControllerEventHanlder() {};
	};
	//

	void CMeetingChatControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingChatControllerWrap& meetingChat = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingChatController();
		meetingChat.m_cbonChatMsgNotifcation =
			std::bind(&MeetingChatControllerEventHanlder::onChatMsgNotifcation, 
				&MeetingChatControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);

		meetingChat.m_cbonChatStautsChangedNotification =
			std::bind(&MeetingChatControllerEventHanlder::onChatStatusChangedNotifcation,
				&MeetingChatControllerEventHanlder::GetInst(), std::placeholders::_1);
	}

	SDKError CMeetingChatControllerDotNetWrap::SendChatTo(unsigned int receiver, String^ content)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingChatController().SendChatTo(receiver, const_cast<wchar_t*>(PlatformString2WChar(content)));
	}

	void CMeetingChatControllerDotNetWrap::procChatMsgNotifcation(IChatMsgInfoDotNetWrap^ chatMsg)
	{
		event_onChatMsgNotifcation(chatMsg);
	}

	void CMeetingChatControllerDotNetWrap::procChatStatusChangedNotification(ChatStatus^ status)
	{
		event_onChatStatusChangedNotification(status);
	}
}