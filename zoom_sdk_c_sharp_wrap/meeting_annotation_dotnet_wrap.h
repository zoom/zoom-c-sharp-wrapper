#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class AnnotationToolType : int
	{
		ANNOTOOL_NONE_DRAWING,///<switch to mouse 

		ANNOTOOL_PEN,
		ANNOTOOL_HIGHLIGHTER,
		ANNOTOOL_AUTO_LINE,
		ANNOTOOL_AUTO_RECTANGLE,
		ANNOTOOL_AUTO_ELLIPSE,
		ANNOTOOL_AUTO_ARROW,
		ANNOTOOL_AUTO_RECTANGLE_FILL,
		ANNOTOOL_AUTO_ELLIPSE_FILL,

		ANNOTOOL_SPOTLIGHT,
		ANNOTOOL_ARROW,

		ANNOTOOL_ERASER,///<earser
	};

	public enum class AnnotationClearType : int
	{
		ANNOCLEAR_ALL,
		ANNOCLEAR_SELF,
		ANNOCLEAR_OTHER,
	};


	public interface class IAnnotationControllerDotNetWrap
	{
	public:
		bool IsAnnoataionDisable();
		SDKError StartAnnotation(SDKViewType viewtype, int left, int top);
		SDKError StopAnnotation(SDKViewType viewtype);
		SDKError SetTool(SDKViewType viewtype, AnnotationToolType type);
		SDKError Clear(SDKViewType viewtype, AnnotationClearType type);
		SDKError SetColor(SDKViewType viewtype, unsigned long color);
		SDKError SetLineWidth(SDKViewType viewtype, long lineWidth);
		SDKError Undo(SDKViewType viewtype);
		SDKError Redo(SDKViewType viewtype);
	};

	private ref class CAnnotationControllerDotNetWrap sealed : public IAnnotationControllerDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
		static property CAnnotationControllerDotNetWrap^ Instance
		{
			CAnnotationControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent() {};

		virtual bool IsAnnoataionDisable();
		virtual SDKError StartAnnotation(SDKViewType viewtype, int left, int top);
		virtual SDKError StopAnnotation(SDKViewType viewtype);
		virtual SDKError SetTool(SDKViewType viewtype, AnnotationToolType type);
		virtual SDKError Clear(SDKViewType viewtype, AnnotationClearType type);
		virtual SDKError SetColor(SDKViewType viewtype, unsigned long color);
		virtual SDKError SetLineWidth(SDKViewType viewtype, long lineWidth);
		virtual SDKError Undo(SDKViewType viewtype);
		virtual SDKError Redo(SDKViewType viewtype);
	private:
		CAnnotationControllerDotNetWrap() {};
		virtual ~CAnnotationControllerDotNetWrap() {};
		static CAnnotationControllerDotNetWrap^ m_Instance = gcnew CAnnotationControllerDotNetWrap;
	};
}