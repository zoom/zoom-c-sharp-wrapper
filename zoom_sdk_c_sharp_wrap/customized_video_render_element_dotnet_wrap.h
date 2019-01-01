#pragma once

using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap\customized_ui_components_wrap\customized_video_container_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class VideoRenderElementType : int
	{
		VideoRenderElement_None, /// none
		VideoRenderElement_PREVIEW, /// for IPreviewVideoRenderElement
		VideoRenderElement_ACTIVE, /// for IActiveVideoRenderElement
		VideoRenderElement_NORMAL, /// for INormalVideoRenderElement
	};

	public enum class VideoRenderDataType
	{
		VideoRenderData_None,/// none
		VideoRenderData_Video,/// video data
		VideoRenderData_Avatar,/// avatar (no video data)
		VideoRenderData_ScreenName,/// screen name (no video data and no avatar)
	};

	public interface class IVideoRenderElementDotNetWrap
	{
	public:
		VideoRenderElementType GetType();
		RECT GetPos();
		SDKError SetPos(RECT pos);
		SDKError Show();
		SDKError Hide();
		unsigned int GetCurrentRenderUserId();
		VideoRenderDataType GetCurrentRenderDataType();
		SDKError EnableShowScreenNameOnVideo(bool enableShow);
	};

	public interface class IPreviewVideoRenderElementDotNetWrap : public IVideoRenderElementDotNetWrap
	{
	public:
		SDKError Start();
		SDKError Stop();
	};

	public interface class IActiveVideoRenderElementDotNetWrap : public IVideoRenderElementDotNetWrap
	{
	public:
		SDKError Start();
		SDKError Stop();
	};

	public interface class INormalVideoRenderElementDotNetWrap : public IVideoRenderElementDotNetWrap
	{
	public:
		SDKError Subscribe(unsigned int userId);
		SDKError Unsubscribe(unsigned int userId);
	};


	private ref class IVideoRenderElementDotNetWrapImpl : public IVideoRenderElementDotNetWrap
	{
	public:
		IVideoRenderElementDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IVideoRenderElement* pObj)
		{
			m_pSDKObj = pObj;
		}

		IVideoRenderElementDotNetWrapImpl() { m_pSDKObj = NULL; }
		~IVideoRenderElementDotNetWrapImpl() {}

		virtual VideoRenderElementType GetType()
		{
			if (m_pSDKObj)
			{
				return (VideoRenderElementType)m_pSDKObj->GetType();
			}

			return VideoRenderElementType::VideoRenderElement_None;
		}

		virtual RECT GetPos()
		{
			RECT result;

			if (m_pSDKObj)
			{
				::RECT rc_native = m_pSDKObj->GetPos();
				result.Top = rc_native.top;
				result.Left = rc_native.left;
				result.Bottom = rc_native.bottom;
				result.Right = rc_native.right;
			}

			return result;
		}

		virtual SDKError SetPos(RECT pos)
		{
			if (m_pSDKObj)
			{
				::RECT rc_native;
				rc_native.top = pos.Top;
				rc_native.left = pos.Left;
				rc_native.bottom = pos.Bottom;
				rc_native.right = pos.Right;
				return (SDKError)m_pSDKObj->SetPos(rc_native);
			}

			return SDKError::SDKERR_SUCCESS;
		}

		virtual SDKError Show()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->Show();
			}

			return SDKError::SDKERR_SUCCESS;
		}

		virtual SDKError Hide()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->Hide();
			}

			return SDKError::SDKERR_SUCCESS;
		}

		virtual unsigned int GetCurrentRenderUserId()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetCurrentRenderUserId();
			}

			return 0;
		}

		virtual VideoRenderDataType GetCurrentRenderDataType()
		{
			if (m_pSDKObj)
			{
				return (VideoRenderDataType)m_pSDKObj->GetCurrentRenderDataType();
			}

			return VideoRenderDataType::VideoRenderData_None;

		}

		virtual SDKError EnableShowScreenNameOnVideo(bool enableShow)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->EnableShowScreenNameOnVideo(enableShow);
			}

			return SDKError::SDKERR_SUCCESS;
		}

	protected:
		ZOOM_SDK_NAMESPACE::IVideoRenderElement* m_pSDKObj;
	};

	private ref class IActiveVideoRenderElementDotNetWrapImpl : public IVideoRenderElementDotNetWrapImpl, IActiveVideoRenderElementDotNetWrap
	{
	public:
		IActiveVideoRenderElementDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IActiveVideoRenderElement* pObj) : IVideoRenderElementDotNetWrapImpl(pObj)
		{
		}

		IActiveVideoRenderElementDotNetWrapImpl() {}
		~IActiveVideoRenderElementDotNetWrapImpl() {}

		virtual SDKError Start()
		{
			if (m_pSDKObj)
			{
				return (SDKError)dynamic_cast<ZOOM_SDK_NAMESPACE::IActiveVideoRenderElement*>(m_pSDKObj)->Start();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Stop()
		{
			if (m_pSDKObj)
			{
				return (SDKError)dynamic_cast<ZOOM_SDK_NAMESPACE::IActiveVideoRenderElement*>(m_pSDKObj)->Stop();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}
	};

	private ref class IPreviewVideoRenderElementDotNetWrapImpl : public IVideoRenderElementDotNetWrapImpl, IPreviewVideoRenderElementDotNetWrap
	{
	public:
		IPreviewVideoRenderElementDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IPreviewVideoRenderElement* pObj) : IVideoRenderElementDotNetWrapImpl(pObj)
		{
		}

		IPreviewVideoRenderElementDotNetWrapImpl() {}
		~IPreviewVideoRenderElementDotNetWrapImpl() {}

		virtual SDKError Start()
		{
			if (m_pSDKObj)
			{
				return (SDKError)dynamic_cast<ZOOM_SDK_NAMESPACE::IPreviewVideoRenderElement*>(m_pSDKObj)->Start();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Stop()
		{
			if (m_pSDKObj)
			{
				return (SDKError)dynamic_cast<ZOOM_SDK_NAMESPACE::IPreviewVideoRenderElement*>(m_pSDKObj)->Stop();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}
	};

	private ref class INormalVideoRenderElementDotNetWrapImpl : public IVideoRenderElementDotNetWrapImpl, INormalVideoRenderElementDotNetWrap
	{
	public:
		INormalVideoRenderElementDotNetWrapImpl(ZOOM_SDK_NAMESPACE::INormalVideoRenderElement* pObj) : IVideoRenderElementDotNetWrapImpl(pObj)
		{
		}

		INormalVideoRenderElementDotNetWrapImpl() {}
		~INormalVideoRenderElementDotNetWrapImpl() {}

		virtual SDKError Subscribe(unsigned int userId)
		{
			if (m_pSDKObj)
			{
				return (SDKError)dynamic_cast<ZOOM_SDK_NAMESPACE::INormalVideoRenderElement*>(m_pSDKObj)->Subscribe(userId);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Unsubscribe(unsigned int userId)
		{
			if (m_pSDKObj)
			{
				return (SDKError)dynamic_cast<ZOOM_SDK_NAMESPACE::INormalVideoRenderElement*>(m_pSDKObj)->Unsubscribe(userId);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}
	};
}
