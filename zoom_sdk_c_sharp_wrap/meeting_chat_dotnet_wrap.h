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