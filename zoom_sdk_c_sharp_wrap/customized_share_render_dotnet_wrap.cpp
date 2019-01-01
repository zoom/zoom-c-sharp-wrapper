#include "stdafx.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "customized_share_render_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	CCustomizedShareRenderDotNetWrap::CCustomizedShareRenderDotNetWrap()
	{
		m_dotNetWrapImpl = nullptr;
		m_pEvents = NULL;
	}

	CCustomizedShareRenderDotNetWrap::CCustomizedShareRenderDotNetWrap(ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pWrap)
	{
		m_dotNetWrapImpl = gcnew ICustomizedShareRenderDotNetImpl(pWrap);
		m_pEvents = new CustomizedShareRenderEventHandler(this);
	}

	CCustomizedShareRenderDotNetWrap::~CCustomizedShareRenderDotNetWrap()
	{
	}

	void CCustomizedShareRenderDotNetWrap::BindEvent()
	{
		m_dotNetWrapImpl->GetSDKObj()->m_cbonSharingContentStartRecving =
			std::bind(&CustomizedShareRenderEventHandler::onSharingContentStartRecving, *m_pEvents);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonSharingSourceUserIDNotification =
			std::bind(&CustomizedShareRenderEventHandler::onSharingSourceUserIDNotification, *m_pEvents, std::placeholders::_1);

		m_dotNetWrapImpl->GetSDKObj()->m_cbonWindowMsgNotification =
			std::bind(&CustomizedShareRenderEventHandler::onWindowMsgNotification, *m_pEvents, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	}

	void CCustomizedShareRenderDotNetWrap::ProcSharingContentStartRecving()
	{
		event_onSharingContentStartRecving();
	}

	void CCustomizedShareRenderDotNetWrap::ProcSharingSourceUserIDNotification(unsigned int userid)
	{
		event_onSharingSourceUserIDNotification(userid);
	}

	void CCustomizedShareRenderDotNetWrap::ProcWindowMsgNotification(unsigned int uMsg, UIntPtr wParam, IntPtr lParam)
	{
		event_onWindowMsgNotification(uMsg, wParam, lParam);
	}

	//
	SDKError CCustomizedShareRenderDotNetWrap::Show()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->Show();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedShareRenderDotNetWrap::Hide()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->Hide();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedShareRenderDotNetWrap::SetUserID(unsigned int userid)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetUserID(userid);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	unsigned int CCustomizedShareRenderDotNetWrap::GetUserID()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetUserID();
		}

		return 0;
	}

	SDKError CCustomizedShareRenderDotNetWrap::Resize(RECT rc)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->Resize(rc);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedShareRenderDotNetWrap::SetViewMode(CustomizedViewShareMode mode)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetViewMode(mode);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	IntPtr CCustomizedShareRenderDotNetWrap::GetOwnerWnd()
	{
		IntPtr result = IntPtr::Zero;

		if (m_dotNetWrapImpl)
		{
			result = m_dotNetWrapImpl->GetOwnerWnd();
		}

		return result;
	}

	SDKError CCustomizedShareRenderDotNetWrap::HandleWindowsMoveMsg()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->HandleWindowsMoveMsg();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}
}