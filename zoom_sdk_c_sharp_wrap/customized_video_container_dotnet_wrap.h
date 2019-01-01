#pragma once

using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "customized_video_render_element_dotnet_wrap.h"
#include "wrap\customized_ui_components_wrap\customized_video_container_wrap.h"
#include <map>

namespace ZOOM_SDK_DOTNET_WRAP {

	public interface class ICustomizedVideoContainerDotNet
	{
	public:
		IVideoRenderElementDotNetWrap^ CreateVideoElement(VideoRenderElementType elementType);
		SDKError DestroyVideoElement(IVideoRenderElementDotNetWrap^ ppElement);
		SDKError DestroyAllVideoElement();
		SDKError Show();
		SDKError Hide();
		SDKError Resize(RECT rc);
		array<IVideoRenderElementDotNetWrap^>^ GetVideoElementList();
	};


	// Translate custom video container
	public ref class ICustomizedVideoContainerDotNetImpl sealed : public ICustomizedVideoContainerDotNet
	{
	public:
		ICustomizedVideoContainerDotNetImpl(ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* pObj)
		{
			m_pSDKObj = pObj;

			m_SDKToDotNetMap = new std::map<ZOOM_SDK_NAMESPACE::IVideoRenderElement*, int>;
		}

		ICustomizedVideoContainerDotNetImpl() { m_pSDKObj = NULL; }
		~ICustomizedVideoContainerDotNetImpl() 
		{ 
			if (m_pSDKObj)
			{
				m_pSDKObj->UnInit();
				delete m_pSDKObj;
			}

			if (m_SDKToDotNetMap)
			{
				delete m_SDKToDotNetMap;
			}
		}

		ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* GetSDKObj()
		{
			return m_pSDKObj;
		}

		virtual IVideoRenderElementDotNetWrap^ CreateVideoElement(VideoRenderElementType elementType)
		{
			IVideoRenderElementDotNetWrap^ pElement = nullptr;

			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::IVideoRenderElement* pObj(NULL);

				SDKError result = (SDKError)m_pSDKObj->CreateVideoElement(&pObj, (ZOOM_SDK_NAMESPACE::VideoRenderElementType)elementType);
				if (result == SDKError::SDKERR_SUCCESS)
				{
					// Create the wrapper
					if (elementType == VideoRenderElementType::VideoRenderElement_ACTIVE)
					{
						pElement = gcnew IActiveVideoRenderElementDotNetWrapImpl(dynamic_cast<ZOOM_SDK_NAMESPACE::IActiveVideoRenderElement*>(pObj));
					}
					else if (elementType == VideoRenderElementType::VideoRenderElement_NORMAL)
					{
						pElement = gcnew INormalVideoRenderElementDotNetWrapImpl(dynamic_cast<ZOOM_SDK_NAMESPACE::INormalVideoRenderElement*>(pObj));
					}
					else if (elementType == VideoRenderElementType::VideoRenderElement_PREVIEW)
					{
						pElement = gcnew IPreviewVideoRenderElementDotNetWrapImpl(dynamic_cast<ZOOM_SDK_NAMESPACE::IPreviewVideoRenderElement*>(pObj));
					}
					else
					{
						pElement = gcnew IVideoRenderElementDotNetWrapImpl(pObj);
					}
				}
			}

			return pElement;
		}

		virtual SDKError DestroyVideoElement(IVideoRenderElementDotNetWrap^ ppElement)
		{
			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError DestroyAllVideoElement()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->DestroyAllVideoElement();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Show()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->Show();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Hide()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->Hide();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Resize(RECT rc)
		{
			if (m_pSDKObj)
			{
				::RECT rc_native;
				rc_native.top = rc.Top;
				rc_native.left = rc.Left;
				rc_native.bottom = rc.Bottom;
				rc_native.right = rc.Right;
				return (SDKError)m_pSDKObj->Resize(rc_native);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual array<IVideoRenderElementDotNetWrap^>^ GetVideoElementList()
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IVideoRenderElement*>* plstSource = m_pSDKObj->GetVideoElementList();

				if (NULL == plstSource || plstSource->GetCount() <= 0)
				{
					return nullptr;
				}

				int count = plstSource->GetCount();
				array<IVideoRenderElementDotNetWrap^ >^ result = gcnew array<IVideoRenderElementDotNetWrap^ >(count);
				if (nullptr == result)
				{
					return nullptr;
				}

				for (int i = 0; i < count; i++)
				{
					ZOOM_SDK_NAMESPACE::IVideoRenderElement* pSourceItem = plstSource->GetItem(i);
					result[i] = gcnew IVideoRenderElementDotNetWrapImpl(pSourceItem);
				}

				return result;
			}

			return nullptr;
		}

	private:
		std::map<ZOOM_SDK_NAMESPACE::IVideoRenderElement*, int>* m_SDKToDotNetMap;

		ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* m_pSDKObj;
	};


	public delegate void onRenderUserChanged(IVideoRenderElementDotNetWrap^ pElement, unsigned int userId);
	public delegate void onRenderDataTypeChanged(IVideoRenderElementDotNetWrap^ pElement, VideoRenderDataType dataType);
	public delegate void onLayoutNotification(RECT wndCientRect);
	public delegate void onVideoRenderElementDestroyed(IVideoRenderElementDotNetWrap^ pElement);
	
	public interface class ICustomizedVideoContainerDotNetWrap
	{
	public:
		IVideoRenderElementDotNetWrap^ CreateVideoElement(VideoRenderElementType elementType);
		SDKError DestroyVideoElement(IVideoRenderElementDotNetWrap^ ppElement);
		SDKError DestroyAllVideoElement();
		SDKError Show();
		SDKError Hide();
		SDKError Resize(RECT rc);
		array<IVideoRenderElementDotNetWrap^>^ GetVideoElementList();

		void Add_CB_onRenderUserChanged(onRenderUserChanged^ cb);
		void Add_CB_onRenderDataTypeChanged(onRenderDataTypeChanged^ cb);
		void Add_CB_onLayoutNotification(onLayoutNotification^ cb);
		void Add_CB_onVideoRenderElementDestroyed(onVideoRenderElementDestroyed^ cb);
		void Add_CB_onWindowMsgNotification(onWindowMsgNotification^ cb);
		void Remove_CB_onRenderUserChanged(onRenderUserChanged^ cb);
		void Remove_CB_onRenderDataTypeChanged(onRenderDataTypeChanged^ cb);
		void Remove_CB_onLayoutNotification(onLayoutNotification^ cb);
		void Remove_CB_onVideoRenderElementDestroyed(onVideoRenderElementDestroyed^ cb);
		void Remove_CB_onWindowMsgNotification(onWindowMsgNotification^ cb);
	};

	class CustomizedVideoContainerEventHandler;
	private ref class CCustomizedVideoContainerDotNetWrap sealed : public ICustomizedVideoContainerDotNetWrap
	{
	public:
		CCustomizedVideoContainerDotNetWrap(ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* pWrap);

		ICustomizedVideoContainerDotNetImpl^ Inner()
		{
			return m_dotNetWrapImpl;
		}

		//
		void BindEvent();
		void ProcRenderUserChanged(IVideoRenderElementDotNetWrapImpl^ pElement, unsigned int userId);
		void ProcRenderDataTypeChanged(IVideoRenderElementDotNetWrapImpl^ pElement, VideoRenderDataType dataType);
		void ProcLayoutNotification(RECT wndClientRect);
		void ProcVideoRenderElementDestroyed(IVideoRenderElementDotNetWrapImpl^ pElement);
		void ProcWindowMsgNotification(unsigned int uMsg, UIntPtr wParam, IntPtr lParam);

		//
		virtual IVideoRenderElementDotNetWrap^ CreateVideoElement(VideoRenderElementType elementType);
		virtual SDKError DestroyVideoElement(IVideoRenderElementDotNetWrap^ ppElement);
		virtual SDKError DestroyAllVideoElement();
		virtual SDKError Show();
		virtual SDKError Hide();
		virtual SDKError Resize(RECT rc);
		virtual array<IVideoRenderElementDotNetWrap^>^ GetVideoElementList();

		virtual void Add_CB_onRenderUserChanged(onRenderUserChanged^ cb)
		{
			event_onRenderUserChanged += cb;
		}

		virtual void Remove_CB_onRenderUserChanged(onRenderUserChanged^ cb)
		{
			event_onRenderUserChanged -= cb;
		}

		virtual void Add_CB_onRenderDataTypeChanged(onRenderDataTypeChanged^ cb)
		{
			event_onRenderDataTypeChanged += cb;
		}

		virtual void Remove_CB_onRenderDataTypeChanged(onRenderDataTypeChanged^ cb)
		{
			event_onRenderDataTypeChanged -= cb;
		}

		virtual void Add_CB_onLayoutNotification(onLayoutNotification^ cb)
		{
			event_onLayoutNotification += cb;
		}

		virtual void Remove_CB_onLayoutNotification(onLayoutNotification^ cb)
		{
			event_onLayoutNotification -= cb;
		}

		virtual void Add_CB_onVideoRenderElementDestroyed(onVideoRenderElementDestroyed^ cb)
		{
			event_onVideoRenderElementDestroyed += cb;
		}

		virtual void Remove_CB_onVideoRenderElementDestroyed(onVideoRenderElementDestroyed^ cb)
		{
			event_onVideoRenderElementDestroyed -= cb;
		}

		virtual void Add_CB_onWindowMsgNotification(onWindowMsgNotification^ cb)
		{
			event_onWindowMsgNotification += cb;
		}

		virtual void Remove_CB_onWindowMsgNotification(onWindowMsgNotification^ cb)
		{
			event_onWindowMsgNotification -= cb;
		}

	private:
		CCustomizedVideoContainerDotNetWrap();
		virtual ~CCustomizedVideoContainerDotNetWrap();
		event onRenderUserChanged^ event_onRenderUserChanged;
		event onRenderDataTypeChanged^ event_onRenderDataTypeChanged;
		event onLayoutNotification^ event_onLayoutNotification;
		event onVideoRenderElementDestroyed^ event_onVideoRenderElementDestroyed;
		event onWindowMsgNotification^ event_onWindowMsgNotification;

		ICustomizedVideoContainerDotNetImpl^ m_dotNetWrapImpl;
		CustomizedVideoContainerEventHandler* m_pEvents;
	};

	// Translate events
	// Unlike most of the event handlers in the wrapper project, this is not a static class.
	// Because the dot net wrapper class that is the event target isn't static, it must be 
	// implemented as a member of the dot net wrapper class.
	class CustomizedVideoContainerEventHandler
	{
	public:
		CustomizedVideoContainerEventHandler(CCustomizedVideoContainerDotNetWrap^ pTarget)
		{
			m_Target = pTarget;
		}

		virtual void onRenderUserChanged(ZOOM_SDK_NAMESPACE::IVideoRenderElement* pElement, unsigned int userId)
		{
			m_Target->ProcRenderUserChanged(gcnew IVideoRenderElementDotNetWrapImpl(pElement), userId);
		}

		virtual void onRenderDataTypeChanged(ZOOM_SDK_NAMESPACE::IVideoRenderElement* pElement, ZOOM_SDK_NAMESPACE::VideoRenderDataType dataType)
		{
			m_Target->ProcRenderDataTypeChanged(gcnew IVideoRenderElementDotNetWrapImpl(pElement), (VideoRenderDataType)dataType);
		}

		virtual void onLayoutNotification(::RECT wndClientRect)
		{
			RECT rc_dotnet;
			rc_dotnet.Top = wndClientRect.top;
			rc_dotnet.Left = wndClientRect.left;
			rc_dotnet.Bottom = wndClientRect.bottom;
			rc_dotnet.Right = wndClientRect.right;

			m_Target->ProcLayoutNotification(rc_dotnet);
		}
		virtual void onVideoRenderElementDestroyed(ZOOM_SDK_NAMESPACE::IVideoRenderElement* pElement)
		{
			m_Target->ProcVideoRenderElementDestroyed(gcnew IVideoRenderElementDotNetWrapImpl(pElement));
		}

		virtual void onWindowMsgNotification(UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			m_Target->ProcWindowMsgNotification((unsigned int)uMsg, (UIntPtr)wParam, (IntPtr)lParam);
		}

	private:
		CustomizedVideoContainerEventHandler() {}

		gcroot<CCustomizedVideoContainerDotNetWrap^> m_Target;
	};
}