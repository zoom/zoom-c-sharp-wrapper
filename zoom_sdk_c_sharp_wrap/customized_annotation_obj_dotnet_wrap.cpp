#include "stdafx.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "customized_annotation_obj_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	CCustomizedAnnotationObjDotNetWrap::CCustomizedAnnotationObjDotNetWrap()
	{
		m_dotNetWrapImpl = nullptr;
		m_pEvents = NULL;
	}

	CCustomizedAnnotationObjDotNetWrap::CCustomizedAnnotationObjDotNetWrap(ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* pWrap)
	{
		m_dotNetWrapImpl = gcnew ICustomizedAnnotationObjDotNetImpl(pWrap);
		m_pEvents = new CustomizedAnnotationObjEventHandler(this);
		if (m_dotNetWrapImpl)
		{
			BindEvent();
		}
	}

	CCustomizedAnnotationObjDotNetWrap::~CCustomizedAnnotationObjDotNetWrap()
	{
	}

	void CCustomizedAnnotationObjDotNetWrap::BindEvent()
	{
		m_dotNetWrapImpl->GetSDKObj()->m_cbonAnnotationObjToolChange =
			std::bind(&CustomizedAnnotationObjEventHandler::onAnnotationObjToolChange, *m_pEvents, std::placeholders::_1);
	}

	void CCustomizedAnnotationObjDotNetWrap::ProcAnnotationObjToolChange(AnnotationToolType type_)
	{
		event_onAnnotationObjToolChange(type_);
	}
	//
	SDKError CCustomizedAnnotationObjDotNetWrap::CanClear(AnnotationClearType type)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->CanClear(type);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::Clear(AnnotationClearType type)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->Clear(type);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::SetTool(AnnotationToolType type)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetTool(type);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::SetColor(unsigned long color)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetColor(color);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::SetLineWidth(long lineWidth)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SetLineWidth(lineWidth);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::GetCurColor(unsigned long& color)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetCurColor(color);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::GetCurLineWidth(long& lineWidth)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetCurLineWidth(lineWidth);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::GetCurTool(AnnotationToolType& type)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->GetCurTool(type);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::Undo()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->Undo();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::Redo()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->Redo();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::CanSaveSnapshot()
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->CanSaveSnapshot();
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

	SDKError CCustomizedAnnotationObjDotNetWrap::SaveSnapshot(const wchar_t* path)
	{
		if (m_dotNetWrapImpl)
		{
			return m_dotNetWrapImpl->SaveSnapshot(path);
		}

		return SDKError::SDKERR_UNINITIALIZE;
	}

}