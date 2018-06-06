#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	public delegate void onWatingRoomUserJoin(unsigned int userID);
	public delegate void onWatingRoomUserLeft(unsigned int userID);

	public interface class IMeetingWaitingRoomControllerDotNetWrap
	{
	public:
		bool IsSupportWaitingRoom();
		bool IsWaitingRoomOnEntryFlagOn();
		SDKError EnableWaitingRoomOnEntry(bool bEnable);
		array<unsigned int >^ GetWaitingRoomLst();
		IUserInfoDotNetWrap^ GetWaitingRoomUserInfoByID(unsigned int userid);
		SDKError AdmitToMeeting(unsigned int userid);
		SDKError PutInWaitingRoom(unsigned int userid);

		void Add_CB_onWatingRoomUserJoin(onWatingRoomUserJoin^ cb);
		void Add_CB_onWatingRoomUserLeft(onWatingRoomUserLeft^ cb);
	};

	private ref class CMeetingWaitingRoomControllerDotNetWrap sealed : public IMeetingWaitingRoomControllerDotNetWrap
	{
	public:
		static property CMeetingWaitingRoomControllerDotNetWrap^ Instance
		{
			CMeetingWaitingRoomControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procWatingRoomUserJoin(unsigned int userID);
		void procWatingRoomUserLeft(unsigned int userID);

		virtual bool IsSupportWaitingRoom();
		virtual bool IsWaitingRoomOnEntryFlagOn();
		virtual SDKError EnableWaitingRoomOnEntry(bool bEnable);
		virtual array<unsigned int >^ GetWaitingRoomLst();
		virtual IUserInfoDotNetWrap^ GetWaitingRoomUserInfoByID(unsigned int userid);
		virtual SDKError AdmitToMeeting(unsigned int userid);
		virtual SDKError PutInWaitingRoom(unsigned int userid);
		virtual void Add_CB_onWatingRoomUserJoin(onWatingRoomUserJoin^ cb)
		{
			event_onWatingRoomUserJoin += cb;
		}

		virtual void Add_CB_onWatingRoomUserLeft(onWatingRoomUserLeft^ cb)
		{
			event_onWatingRoomUserLeft += cb;
		}

	private:
		event onWatingRoomUserJoin^ event_onWatingRoomUserJoin;
		event onWatingRoomUserLeft^ event_onWatingRoomUserLeft;
		static CMeetingWaitingRoomControllerDotNetWrap^ m_Instance = gcnew CMeetingWaitingRoomControllerDotNetWrap;
	};
}