#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class RemoteControlStatus : int
	{
		Remote_Control_None,
		Remote_Control_I_Can_Request_Control_Who,

		Remote_Control_I_Can_Control_Who_Begin,
		Remote_Control_I_Can_Control_Who_End,

		Remote_Control_I_Control_Who_Begin,
		Remote_Control_I_Control_Who_End,

		Remote_Control_Who_Control_Me,
		Remote_Control_I_Recv_Decline_Msg,
		Remote_Control_I_Recv_Request_Msg,
	};

	public delegate void onRemoteControlStatus(RemoteControlStatus status, unsigned int userId);
	public interface class IMeetingRemoteControllerDotNetWrap
	{
	public:
		SDKError RequestRemoteControl(unsigned int userId);
		SDKError GiveupRemoteControl(unsigned int userId);
		SDKError GiveRemoteControlTo(unsigned int userId);
		SDKError DeclineRemoteControlRequest(unsigned int userId);
		SDKError RevokeRemoteControl();
		SDKError GetCurrentRemoteController(unsigned int^% userId);
		void Add_CB_onRemoteControlStatus(onRemoteControlStatus^ cb);
	};

	private ref class CMeetingRemoteControllerDotNetWrap sealed : public IMeetingRemoteControllerDotNetWrap
	{
	public:
		static property CMeetingRemoteControllerDotNetWrap^ Instance
		{
			CMeetingRemoteControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void ProcRemoteControlStatus(RemoteControlStatus status, unsigned int userId);
		virtual SDKError RequestRemoteControl(unsigned int userId);
		virtual SDKError GiveupRemoteControl(unsigned int userId);
		virtual SDKError GiveRemoteControlTo(unsigned int userId);
		virtual SDKError DeclineRemoteControlRequest(unsigned int userId);
		virtual SDKError RevokeRemoteControl();
		virtual SDKError GetCurrentRemoteController(unsigned int^% userId);
		virtual void Add_CB_onRemoteControlStatus(onRemoteControlStatus^ cb)
		{
			event_onRemoteControlStatus += cb;
		}
	private:
		event onRemoteControlStatus^ event_onRemoteControlStatus;
		static CMeetingRemoteControllerDotNetWrap^ m_Instance = gcnew CMeetingRemoteControllerDotNetWrap;
	};
}