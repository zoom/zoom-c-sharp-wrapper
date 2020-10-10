#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public interface class IChatMsgInfoDotNetWrap
	{
	public:
		unsigned int GetSenderUserId();
		String^ GetSenderDisplayName();
		unsigned int GetReceiverUserId();
		String^ GetReceiverDisplayName();
		String^ GetContent();
		Nullable<DateTime> GetTimeStamp();
	};

	public enum class SDKChatPriviledge : int
	{
		SDK_CHAT_PRIVILEDGE_ALL = 1,                    	/// allow attendee to chat with everyone [meeting & webinar]
		SDK_CHAT_PRIVILEDGE_ALL_PANELIST = 2,		          /// allow attendee to chat with all panelists only, but cannot to "all panelists and attendees" [webinar]
		SDK_CHAT_PRIVILEDGE_HOST = 3,	                    /// allow attendee to chat with host only [meeting]
		SDK_CHAT_PRIVILEDGE_DISABLE_ATTENDEE_CHAT = 4,    /// allow attendee to chat with no one [meeting & webinar]
		SDK_CHAT_PRIVILEDGE_HOST_PUBLIC = 5,              /// allow attendee to chat with host and public [meeting]
		SDK_CHAT_PRIVILEDGE_END
	};

	public value class NormalMeetingChatStatus
	{
	public:
		bool canChatToAll;
		bool canChatToIndividual;
		bool isOnlyCanChatToHost;
	};

	public value class WebinarAttendeeChatStatus
	{
	public:
		bool canChat;
		bool canChatToAllPanelListAndAttendee;
		bool canChatToAllPanelList;
	};

	public value class WebinarOtherUserRoleChatStatus sealed
	{
	public:
		bool canChatToAllPanelList;
		bool canChatToAllPanelListAndAttendee;
		bool canChatToIndividual;
	};

	public value class ChatStatus sealed
	{
	public:
		NormalMeetingChatStatus^ normalMeetingStatus;
		WebinarAttendeeChatStatus^ webinarAttendeeStatus;
		WebinarOtherUserRoleChatStatus^ webinarOtherStatus;

		bool isChatOff;
		bool isWebinarAttendee;
		bool isWebinarMeeting;
	};

	public delegate void onChatMsgNotifcation(IChatMsgInfoDotNetWrap^ chatMsg);
	public delegate void onChatStatusChangedNotification(ChatStatus^ status);

	public interface class IMeetingChatControllerDotNetWrap
	{
	public:
		SDKError SendChatTo(unsigned int receiver, String^ content);
		SDKError SetParticipantsChatPriviledge(SDKChatPriviledge priviledge);
		void Add_CB_onChatMsgNotifcation(onChatMsgNotifcation^ cb);
		void Add_CB_onChatStatusChangedNotification(onChatStatusChangedNotification^ cb);
		void Remove_CB_onChatMsgNotifcation(onChatMsgNotifcation^ cb);
		void Remove_CB_onChatStatusChangedNotification(onChatStatusChangedNotification^ cb);
	};

	private ref class CMeetingChatControllerDotNetWrap sealed : public IMeetingChatControllerDotNetWrap
	{
	public:
		static property CMeetingChatControllerDotNetWrap^ Instance
		{
			CMeetingChatControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procChatMsgNotifcation(IChatMsgInfoDotNetWrap^ chatMsg);
		void procChatStatusChangedNotification(ChatStatus^ status);

		virtual SDKError SendChatTo(unsigned int receiver, String^ content);

		virtual SDKError SetParticipantsChatPriviledge(SDKChatPriviledge priviledge);

		virtual void Add_CB_onChatMsgNotifcation(onChatMsgNotifcation^ cb)
		{
			event_onChatMsgNotifcation += cb;
		}

		virtual void Remove_CB_onChatMsgNotifcation(onChatMsgNotifcation^ cb)
		{
			event_onChatMsgNotifcation -= cb;
		}

		virtual void Add_CB_onChatStatusChangedNotification(onChatStatusChangedNotification^ cb)
		{
			event_onChatStatusChangedNotification += cb;
		}

		virtual void Remove_CB_onChatStatusChangedNotification(onChatStatusChangedNotification^ cb)
		{
			event_onChatStatusChangedNotification -= cb;
		}

	private:
		event onChatMsgNotifcation^ event_onChatMsgNotifcation;
		event onChatStatusChangedNotification^ event_onChatStatusChangedNotification;
		static CMeetingChatControllerDotNetWrap^ m_Instance = gcnew CMeetingChatControllerDotNetWrap;
	};
}