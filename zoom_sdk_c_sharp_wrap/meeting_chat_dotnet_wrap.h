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
		DateTime^ GetTimeStamp();
	};

	public delegate void onChatMsgNotifcation(IChatMsgInfoDotNetWrap^ chatMsg);
	public interface class IMeetingChatControllerDotNetWrap
	{
	public:
		SDKError SendChatTo(unsigned int receiver, String^ content);
		void Add_CB_onChatMsgNotifcation(onChatMsgNotifcation^ cb);
	};

	private ref class CMeetingChatControllerDotNetWrap sealed : public IMeetingChatControllerDotNetWrap
	{
	public:
		static property CMeetingChatControllerDotNetWrap^ Instance
		{
			CMeetingChatControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		virtual SDKError SendChatTo(unsigned int receiver, String^ content);
		virtual void Add_CB_onChatMsgNotifcation(onChatMsgNotifcation^ cb)
		{
			event_onChatMsgNotifcation += cb;
		}
		void procChatMsgNotifcation(IChatMsgInfoDotNetWrap^ chatMsg);
	private:
		event onChatMsgNotifcation^ event_onChatMsgNotifcation;
		static CMeetingChatControllerDotNetWrap^ m_Instance = gcnew CMeetingChatControllerDotNetWrap;
	};
}