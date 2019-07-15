#include "stdafx.h"
#include "customized_video_container_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	CCustomizedVideoContainerDotNetWrap::CCustomizedVideoContainerDotNetWrap()
	{
		m_dotNetWrapImpl = nullptr;
		m_pEvents = NULL;
	}

	CCustomizedVideoContainerDotNetWrap::CCustomizedVideoContainerDotNetWrap(ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* pWrap)
	{
		m_dotNetWrapImpl = gcnew ICustomizedVideoContainerDotNetImpl(pWrap);
		m_pEvents = new CustomizedVideoContainerEventHandler(this);
	}

	CCustomizedVideoContainerDotNetWrap::~CCustomizedVideoContainerDotNetWrap()
	{

	}

	void CCustomizedVideoContainerDotNetWrap::BindEvent()
	{
		m_dotNetWrapImpl->GetSDKObj()->m_cbonRenderUserChanged =
			std::bind(&CustomizedVideoContainerEventHandler::onRenderUserChanged, *m_pEvents, std::placeholders::_1, std::placeholders::_2);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonRenderDataTypeChanged =
			std::bind(&CustomizedVideoContainerEventHandler::onRenderDataTypeChanged, *m_pEvents, std::placeholders::_1, std::placeholders::_2);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonLayoutNotification =
			std::bind(&CustomizedVideoContainerEventHandler::onLayoutNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonVideoRenderElementDestroyed =
			std::bind(&CustomizedVideoContainerEventHandler::onVideoRenderElementDestroyed, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonWindowMsgNotification =
			std::bind(&CustomizedVideoContainerEventHandler::onWindowMsgNotification, *m_pEvents, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	}

	void CCustomizedVideoContainerDotNetWrap::ProcRenderUserChanged(IVideoRenderElementDotNetWrapImpl^ pElement, unsigned int userId)
	{
		event_onRenderUserChanged(pElement, userId);
	}

	void CCustomizedVideoContainerDotNetWrap::ProcRenderDataTypeChanged(IVideoRenderElementDotNetWrapImpl^ pElement, VideoRenderDataType dataType)
	{
		event_onRenderDataTypeChanged(pElement, dataType);
	}

	void CCustomizedVideoContainerDotNetWrap::ProcLayoutNotification(RECT wndClientRect)
	{
		event_onLayoutNotification(wndClientRect);
	}

	void CCustomizedVideoContainerDotNetWrap::ProcVideoRenderElementDestroyed(IVideoRenderElementDotNetWrapImpl^ pElement)
	{
		event_onVideoRenderElementDestroyed(pElement);
	}

	void CCustomizedVideoContainerDotNetWrap::ProcWindowMsgNotification(unsigned int uMsg, UIntPtr wParam, IntPtr lParam)
	{
		event_onWindowMsgNotification(uMsg, wParam, lParam);
	}

	//
	IVideoRenderElementDotNetWrap^ CCustomizedVideoContainerDotNetWrap::CreateVideoElement(VideoRenderElementType elementType)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->CreateVideoElement(elementType);
		}

		return nullptr;
	}

	SDKError CCustomizedVideoContainerDotNetWrap::DestroyVideoElement(IVideoRenderElementDotNetWrap^ ppElement)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->DestroyVideoElement(ppElement);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedVideoContainerDotNetWrap::DestroyAllVideoElement()
	{
		if (m_dotNetWrapImpl)
		{
			return (SDKError)m_dotNetWrapImpl->DestroyAllVideoElement();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedVideoContainerDotNetWrap::Show()
	{
		if (m_dotNetWrapImpl)
		{
			return (SDKError)m_dotNetWrapImpl->Show();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedVideoContainerDotNetWrap::Hide()
	{
		if (m_dotNetWrapImpl)
		{
			return (SDKError)m_dotNetWrapImpl->Hide();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedVideoContainerDotNetWrap::Resize(RECT rc)
	{
		if (m_dotNetWrapImpl)
		{
			return (SDKError)m_dotNetWrapImpl->Resize(rc);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	array<IVideoRenderElementDotNetWrap^>^ CCustomizedVideoContainerDotNetWrap::GetVideoElementList()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetVideoElementList();
		}

		return nullptr;
	}
}