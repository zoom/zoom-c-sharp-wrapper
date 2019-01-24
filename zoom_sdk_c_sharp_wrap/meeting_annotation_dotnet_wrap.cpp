#include "stdafx.h"
#include "meeting_annotation_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	bool CAnnotationControllerDotNetWrap::IsAnnoataionDisable()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().IsAnnoataionDisable();
	}

	SDKError CAnnotationControllerDotNetWrap::StartAnnotation(SDKViewType viewtype, int left, int top)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().StartAnnotation((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype, left, top);
	}

	SDKError CAnnotationControllerDotNetWrap::StopAnnotation(SDKViewType viewtype)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().StopAnnotation((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype);
	}

	SDKError CAnnotationControllerDotNetWrap::SetTool(SDKViewType viewtype, AnnotationToolType type)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().SetTool((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype, (ZOOM_SDK_NAMESPACE::AnnotationToolType)type);
	}

	SDKError CAnnotationControllerDotNetWrap::Clear(SDKViewType viewtype, AnnotationClearType type)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().Clear((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype, (ZOOM_SDK_NAMESPACE::AnnotationClearType)type);
	}

	SDKError CAnnotationControllerDotNetWrap::SetColor(SDKViewType viewtype, unsigned long color)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().SetColor((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype, color);
	}

	SDKError CAnnotationControllerDotNetWrap::SetLineWidth(SDKViewType viewtype, long lineWidth)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().SetLineWidth((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype, lineWidth);
	}

	SDKError CAnnotationControllerDotNetWrap::Undo(SDKViewType viewtype)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().Undo((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype);
	}

	SDKError CAnnotationControllerDotNetWrap::Redo(SDKViewType viewtype)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().Redo((ZOOM_SDK_NAMESPACE::SDKViewType)viewtype);
	}
}