#pragma once

using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap\customized_ui_components_wrap\customized_share_render_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class CustomizedViewShareMode : int
	{
		CSM_FULLFILL, /// Stretch the sharing content to the whole window size
		CSM_LETTER_BOX /// Display the sharing content in the original ratio
	};

	public interface class ICustomizedShareRenderDotNet
	{
	public:
		SDKError Show();
		SDKError Hide();
		SDKError SetUserID(unsigned int userId);
		unsigned int GetUserID();
		SDKError Resize(RECT rc);
		SDKError SetViewMode(CustomizedViewShareMode mode);
		IntPtr GetOwnerWnd();
		SDKError HandleWindowsMoveMsg();
	};


	// Translate custom share render element
	private ref class ICustomizedShareRenderDotNetImpl sealed : public ICustomizedShareRenderDotNet
	{
	public:
		ICustomizedShareRenderDotNetImpl(ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pObj)
		{
			m_pSDKObj = pObj;
		}

		ICustomizedShareRenderDotNetImpl() { m_pSDKObj = NULL; }
		~ICustomizedShareRenderDotNetImpl() 
		{
			if(m_pSDKObj)
			{
				delete m_pSDKObj;
			}
		}

		ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* GetSDKObj()
		{
			return m_pSDKObj;
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

		virtual SDKError SetUserID(unsigned int userId)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetUserID(userId);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual unsigned int GetUserID()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetUserID();
			}

			return 0;
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

		virtual SDKError SetViewMode(CustomizedViewShareMode mode)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetViewMode((ZOOM_SDK_NAMESPACE::CustomizedViewShareMode)mode);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual IntPtr GetOwnerWnd()
		{
			IntPtr result = IntPtr::Zero;

			if (m_pSDKObj)
			{
				result = IntPtr(m_pSDKObj->GetOwnerWnd());
			}

			return result;
		}

		virtual SDKError HandleWindowsMoveMsg()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->HandleWindowsMoveMsg();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

	private:
		ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* m_pSDKObj;
	};
	//

	public delegate void onSharingContentStartRecving();
	public delegate void onSharingSourceUserIDNotification(unsigned int userId);

	public interface class ICustomizedShareRenderDotNetWrap
	{
	public:
		SDKError Show();
		SDKError Hide();
		SDKError SetUserID(unsigned int userId);
		unsigned int GetUserID();
		SDKError Resize(RECT rc);
		SDKError SetViewMode(CustomizedViewShareMode mode);
		IntPtr GetOwnerWnd();
		SDKError HandleWindowsMoveMsg();

		void Add_CB_onSharingContentStartRecving(onSharingContentStartRecving^ cb);
		void Add_CB_onSharingSourceUserIDNotification(onSharingSourceUserIDNotification^ cb);
		void Add_CB_onWindowMsgNotification(onWindowMsgNotification^ cb);
		void Remove_CB_onSharingContentStartRecving(onSharingContentStartRecving^ cb);
		void Remove_CB_onSharingSourceUserIDNotification(onSharingSourceUserIDNotification^ cb);
		void Remove_CB_onWindowMsgNotification(onWindowMsgNotification^ cb);
	};

	class CustomizedShareRenderEventHandler;
	private ref class CCustomizedShareRenderDotNetWrap sealed : public ICustomizedShareRenderDotNetWrap
	{
	public:
		CCustomizedShareRenderDotNetWrap(ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pWrap);

		ICustomizedShareRenderDotNetImpl^ Inner()
		{
			return m_dotNetWrapImpl;
		}

		void BindEvent();
		void ProcSharingContentStartRecving();
		void ProcSharingSourceUserIDNotification(unsigned int userId);
		void ProcWindowMsgNotification(unsigned int uMsg, UIntPtr wParam, IntPtr lParam);

		virtual SDKError Show();
		virtual SDKError Hide();
		virtual SDKError SetUserID(unsigned int userId);
		virtual unsigned int GetUserID();
		virtual SDKError Resize(RECT rc);
		virtual SDKError SetViewMode(CustomizedViewShareMode mode);
		virtual IntPtr GetOwnerWnd();
		virtual SDKError HandleWindowsMoveMsg();

		virtual void Add_CB_onSharingContentStartRecving(onSharingContentStartRecving^ cb)
		{
			event_onSharingContentStartRecving += cb;
		}

		virtual void Remove_CB_onSharingContentStartRecving(onSharingContentStartRecving^ cb)
		{
			event_onSharingContentStartRecving -= cb;
		}

		virtual void Add_CB_onSharingSourceUserIDNotification(onSharingSourceUserIDNotification^ cb)
		{
			event_onSharingSourceUserIDNotification += cb;
		}

		virtual void Remove_CB_onSharingSourceUserIDNotification(onSharingSourceUserIDNotification^ cb)
		{
			event_onSharingSourceUserIDNotification -= cb;
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
		CCustomizedShareRenderDotNetWrap();
		virtual ~CCustomizedShareRenderDotNetWrap();
		event onSharingContentStartRecving^ event_onSharingContentStartRecving;
		event onSharingSourceUserIDNotification^ event_onSharingSourceUserIDNotification;
		event onWindowMsgNotification^ event_onWindowMsgNotification;

		ICustomizedShareRenderDotNetImpl^ m_dotNetWrapImpl;
		CustomizedShareRenderEventHandler* m_pEvents;
	};

	// Translate events
	// Unlike most of the event handlers in the wrapper project, this is not a static class.
	// Because the dot net wrapper class that is the event target isn't static, it must be 
	// implemented as a member of the dot net wrapper class.
	class CustomizedShareRenderEventHandler
	{
	public:
		CustomizedShareRenderEventHandler(CCustomizedShareRenderDotNetWrap^ pTarget)
		{
			m_Target = pTarget;
		}

		virtual void onSharingContentStartRecving()
		{
			m_Target->ProcSharingContentStartRecving();
		}

		virtual void onSharingSourceUserIDNotification(unsigned int userId)
		{
			m_Target->ProcSharingSourceUserIDNotification(userId);
		}

		virtual void onWindowMsgNotification(UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			m_Target->ProcWindowMsgNotification((unsigned int)uMsg, (UIntPtr)wParam, (IntPtr)lParam);
		}

	private:
		CustomizedShareRenderEventHandler() {}

		gcroot<CCustomizedShareRenderDotNetWrap^> m_Target;
	};
}