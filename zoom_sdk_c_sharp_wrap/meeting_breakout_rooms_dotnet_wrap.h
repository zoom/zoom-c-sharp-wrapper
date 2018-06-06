#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public interface class IBreakoutRoomsInfoDotNet
	{
	public:
		String^ GetBID();
		String^ GetBreakoutRoomName();
	};

	public delegate void OnBreakoutRoomsStartedNotification(String^ stBID);
	public interface class IMeetingBreakoutRoomsControllerDotNetWrap
	{
	public:
		SDKError JoinBreakoutRoom(String^ stBID);
		SDKError LeaveBreakoutRoom();
		array<IBreakoutRoomsInfoDotNet^ >^ GetBreakoutRoomsInfoList();
		void Add_CB_OnBreakoutRoomsStartedNotification(OnBreakoutRoomsStartedNotification^ cb);
	};

	private ref class CMeetingBreakoutRoomsControllerDotNetWrap sealed : public IMeetingBreakoutRoomsControllerDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
		static property CMeetingBreakoutRoomsControllerDotNetWrap^ Instance
		{
			CMeetingBreakoutRoomsControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();

		virtual SDKError JoinBreakoutRoom(String^ stBID);
		virtual SDKError LeaveBreakoutRoom();
		virtual array<IBreakoutRoomsInfoDotNet^ >^ GetBreakoutRoomsInfoList();
		virtual void Add_CB_OnBreakoutRoomsStartedNotification(OnBreakoutRoomsStartedNotification^ cb)
		{
			event_OnBreakoutRoomsStartedNotification += cb;
		}

		void ProcBreakoutRoomsStartedNotification(String^ stBID);
	private:
		CMeetingBreakoutRoomsControllerDotNetWrap() {};
		virtual ~CMeetingBreakoutRoomsControllerDotNetWrap() {};
		event OnBreakoutRoomsStartedNotification^ event_OnBreakoutRoomsStartedNotification;
		static CMeetingBreakoutRoomsControllerDotNetWrap^ m_Instance = gcnew CMeetingBreakoutRoomsControllerDotNetWrap;
	};
}