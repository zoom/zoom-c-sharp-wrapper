#include "stdafx.h"
#include "meeting_live_stream_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	// Translate event
	class MeetingLiveStreamEventHandler
	{
	public:
		static MeetingLiveStreamEventHandler& GetInst()
		{
			static MeetingLiveStreamEventHandler instance;
			return instance;
		}

		void onLiveStreamStatusChange(ZOOM_SDK_NAMESPACE::LiveStreamStatus status)
		{
			if (CMeetingLiveStreamControllerDotNetWrap::Instance)
			{
				CMeetingLiveStreamControllerDotNetWrap::Instance->procLiveStreamStatusChange((LiveStreamStatus)status);
			}
		}

	private:
		MeetingLiveStreamEventHandler() {};
	};
	//

	//
	private ref class IMeetingLiveStreamItemDotNetWrapImpl sealed : public IMeetingLiveStreamItemDotNetWrap
	{
	public:
		IMeetingLiveStreamItemDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IMeetingLiveStreamItem* pItem)
		{
			m_pSDKObj = pItem;
		}

		virtual String^ GetLiveStreamURL()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetLiveStreamURL());
			}

			return nullptr;
		}

		virtual String^ GetLiveStreamURLDescription()
		{
			if (m_pSDKObj)
			{
				return WChar2PlatformString(m_pSDKObj->GetLiveStreamURLDescription());
			}

			return nullptr;
		}

	private:
		ZOOM_SDK_NAMESPACE::IMeetingLiveStreamItem* m_pSDKObj;
	};
	//

	//
	SDKError CMeetingLiveStreamControllerDotNetWrap::CanStartLiveStream()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingLiveStreamController().CanStartLiveStream();
	}

	SDKError CMeetingLiveStreamControllerDotNetWrap::StartLiveStream(IMeetingLiveStreamItemDotNetWrap^ item)
	{
		ZOOM_SDK_NAMESPACE::IMeetingLiveStreamItem* pItemNative = 
			new ZOOM_SDK_NAMESPACE::IMeetingLiveStreamItemImpl(PlatformString2WChar(item->GetLiveStreamURL()), PlatformString2WChar(item->GetLiveStreamURLDescription()));

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingLiveStreamController().StartLiveStream(pItemNative);
	}

	SDKError CMeetingLiveStreamControllerDotNetWrap::StartLiveStreamWithStreamingURL(String^ streamingURL, String^ streamingKey, String^ broadcastURL)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingLiveStreamController().StartLiveStreamWithSteamingURL(PlatformString2WChar(streamingURL), PlatformString2WChar(streamingKey), PlatformString2WChar(broadcastURL));
	}

	SDKError CMeetingLiveStreamControllerDotNetWrap::StopLiveStream()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingLiveStreamController().StopLiveStream();
	}

	array<IMeetingLiveStreamItemDotNetWrap^>^ CMeetingLiveStreamControllerDotNetWrap::GetSupportLiveStreamURL()
	{
		ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMeetingLiveStreamItem*>* lstItems = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingLiveStreamController().GetSupportLiveStreamURL();
		if (lstItems && lstItems->GetCount() > 0)
		{
			int nCount = lstItems->GetCount();
			array<IMeetingLiveStreamItemDotNetWrap^ >^ lstItems_dotnet = gcnew array<IMeetingLiveStreamItemDotNetWrap^ >(nCount);
			if (lstItems_dotnet)
			{
				for (int i(0); i < nCount; i++)
				{
					lstItems_dotnet[i] = gcnew IMeetingLiveStreamItemDotNetWrapImpl(lstItems->GetItem(i));
				}

				return lstItems_dotnet;
			}
		}

		return nullptr;
	}

	LiveStreamStatus CMeetingLiveStreamControllerDotNetWrap::GetCurrentLiveStreamStatus()
	{
		return (LiveStreamStatus)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingLiveStreamController().GetCurrentLiveStreamStatus();
	}

	void CMeetingLiveStreamControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingLiveStreamControllerWrap& controller = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().
			GetMeetingServiceWrap().GetMeetingLiveStreamController();
		controller.m_cbonLiveStreamStatusChange =
			std::bind(&MeetingLiveStreamEventHandler::onLiveStreamStatusChange, &MeetingLiveStreamEventHandler::GetInst(), std::placeholders::_1);
	}

	void CMeetingLiveStreamControllerDotNetWrap::procLiveStreamStatusChange(LiveStreamStatus status)
	{
		event_onLiveStreamStatusChange(status);
	}
}
