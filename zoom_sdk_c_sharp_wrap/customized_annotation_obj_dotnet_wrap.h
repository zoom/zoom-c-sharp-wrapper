#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap\customized_ui_components_wrap\customized_annotation_obj_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class CustomizedShareAnnotationStatus : int
	{
		CS_ANNO_READYTOUSE,//ready to use annotation
		CS_ANNO_CLOSE, //annotation shut down
	};

	public interface class ICustomizedAnnotationObjDotNet
	{
	public:
		SDKError CanClear(AnnotationClearType type);
		SDKError Clear(AnnotationClearType type);
		SDKError SetTool(AnnotationToolType type);
		SDKError SetColor(unsigned long color);
		SDKError SetLineWidth(long lineWidth);
		SDKError GetCurColor(unsigned long& color);
		SDKError GetCurLineWidth(long& lineWidth);
		SDKError GetCurTool(AnnotationToolType& type);
		SDKError Undo();
		SDKError Redo();
		SDKError CanSaveSnapshot();
		SDKError SaveSnapshot(const wchar_t* path);
	};

	// Translate custom annotation object
	private ref class ICustomizedAnnotationObjDotNetImpl sealed : public ICustomizedAnnotationObjDotNet
	{
	public:
		ICustomizedAnnotationObjDotNetImpl(ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* pObj)
		{
			m_pSDKObj = pObj;
		}

		ICustomizedAnnotationObjDotNetImpl() { m_pSDKObj = NULL; }
		~ICustomizedAnnotationObjDotNetImpl()
		{
			if (m_pSDKObj)
			{
				delete m_pSDKObj;
			}
		}

		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* GetSDKObj()
		{
			return m_pSDKObj;
		}

		virtual SDKError CanClear(AnnotationClearType type)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::AnnotationClearType sdk_type = (ZOOM_SDK_NAMESPACE::AnnotationClearType)type;
				return (SDKError)m_pSDKObj->CanClear(sdk_type);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Clear(AnnotationClearType type)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::AnnotationClearType sdk_type = (ZOOM_SDK_NAMESPACE::AnnotationClearType)type;
				return (SDKError)m_pSDKObj->Clear(sdk_type);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError SetTool(AnnotationToolType type)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::AnnotationToolType sdk_type = (ZOOM_SDK_NAMESPACE::AnnotationToolType)type;
				return (SDKError)m_pSDKObj->SetTool(sdk_type);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError SetColor(unsigned long color)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetColor(color);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError SetLineWidth(long lineWidth)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SetLineWidth(lineWidth);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError GetCurColor(unsigned long& color)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->GetCurColor(color);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError GetCurLineWidth(long& lineWidth)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->GetCurLineWidth(lineWidth);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError  GetCurTool(AnnotationToolType& type)
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::AnnotationToolType sdk_type = (ZOOM_SDK_NAMESPACE::AnnotationToolType)type;
				return (SDKError)m_pSDKObj->GetCurTool(sdk_type);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Undo()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->Undo();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError Redo()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->Redo();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError CanSaveSnapshot()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->CanSaveSnapshot();
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}

		virtual SDKError SaveSnapshot(const wchar_t* path)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SaveSnapshot(path);
			}

			return SDKError::SDKERR_UNINITIALIZE;
		}
	private:
		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* m_pSDKObj;
	};

	public delegate void onAnnotationObjToolChange(AnnotationToolType type_);

	public interface class ICustomizedAnnotationObjDotNetWrap
	{
	public:
		SDKError CanClear(AnnotationClearType type);
		SDKError Clear(AnnotationClearType type);
		SDKError SetTool(AnnotationToolType type);
		SDKError SetColor(unsigned long color);
		SDKError SetLineWidth(long lineWidth);
		SDKError GetCurColor(unsigned long& color);
		SDKError GetCurLineWidth(long& lineWidth);
		SDKError GetCurTool(AnnotationToolType& type);
		SDKError Undo();
		SDKError Redo();
		SDKError CanSaveSnapshot();
		SDKError SaveSnapshot(const wchar_t* path);

		void Add_CB_onAnnotationObjToolChange(onAnnotationObjToolChange^ cb);
		void Remove_CB_onAnnotationObjToolChange(onAnnotationObjToolChange^ cb);
	};

	class CustomizedAnnotationObjEventHandler;
	private ref class CCustomizedAnnotationObjDotNetWrap sealed : public ICustomizedAnnotationObjDotNetWrap
	{
	public:
		CCustomizedAnnotationObjDotNetWrap(ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* pWrap);

		ICustomizedAnnotationObjDotNetImpl^ Inner()
		{
			return m_dotNetWrapImpl;
		}

		void BindEvent();
		void ProcAnnotationObjToolChange(AnnotationToolType type_);

		virtual SDKError CanClear(AnnotationClearType type);
		virtual SDKError Clear(AnnotationClearType type);
		virtual SDKError SetTool(AnnotationToolType type);
		virtual SDKError SetColor(unsigned long color);
		virtual SDKError SetLineWidth(long lineWidth);
		virtual SDKError GetCurColor(unsigned long& color);
		virtual SDKError GetCurLineWidth(long& lineWidth);
		virtual SDKError GetCurTool(AnnotationToolType& type);
		virtual SDKError Undo();
		virtual SDKError Redo();
		virtual SDKError CanSaveSnapshot();
		virtual SDKError SaveSnapshot(const wchar_t* path);

		virtual void Add_CB_onAnnotationObjToolChange(onAnnotationObjToolChange^ cb)
		{
			event_onAnnotationObjToolChange += cb;
		}

		virtual void Remove_CB_onAnnotationObjToolChange(onAnnotationObjToolChange^ cb)
		{
			event_onAnnotationObjToolChange -= cb;
		}

	private:
		CCustomizedAnnotationObjDotNetWrap();
		virtual ~CCustomizedAnnotationObjDotNetWrap();

		event onAnnotationObjToolChange^ event_onAnnotationObjToolChange;

		ICustomizedAnnotationObjDotNetImpl^ m_dotNetWrapImpl;
		CustomizedAnnotationObjEventHandler* m_pEvents;
	};

	// Translate events
	// Unlike most of the event handlers in the wrapper project, this is not a static class.
	// Because the dot net wrapper class that is the event target isn't static, it must be 
	// implemented as a member of the dot net wrapper class.
	class CustomizedAnnotationObjEventHandler
	{
	public:
		CustomizedAnnotationObjEventHandler(CCustomizedAnnotationObjDotNetWrap^ pTarget)
		{
			m_Target = pTarget;
		}

		void onAnnotationObjToolChange(ZOOM_SDK_NAMESPACE::AnnotationToolType type_)
		{
			m_Target->ProcAnnotationObjToolChange((ZOOM_SDK_DOTNET_WRAP::AnnotationToolType)type_);
		}

	private:
		CustomizedAnnotationObjEventHandler() {}
		gcroot<CCustomizedAnnotationObjDotNetWrap^> m_Target;
	};
}
