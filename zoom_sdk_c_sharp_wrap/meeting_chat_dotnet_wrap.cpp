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

		virtual DateTime^ GetTimeStamp()
		{
			if (m_pChat)
			{
				DateTime^ time = gcnew DateTime;
				time = time_t2DateTime(m_pChat->GetTimeStamp());
				return time;
			}
			return nullptr;
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
}