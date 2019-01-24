#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IAnnotationController* InitIAnnotationControllerFunc(void* nouse, IMeetingServiceWrap* pOwner);
void UninitIAnnotationControllerFunc(IAnnotationController* obj);

BEGIN_CLASS_DEFINE(IAnnotationController)
NORMAL_CLASS(IAnnotationController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IAnnotationController, IMeetingServiceWrap)

//virtual bool IsAnnoataionDisable() = 0;
DEFINE_FUNC_0(IsAnnoataionDisable, bool)
//virtual SDKError StartAnnotation(SDKViewType viewtype, int left, int top) = 0;
DEFINE_FUNC_3(StartAnnotation, SDKError, SDKViewType, viewtype, int, left, int, top)
//virtual SDKError StopAnnotation(SDKViewType viewtype) = 0;
DEFINE_FUNC_1(StopAnnotation, SDKError, SDKViewType, viewtype)
//virtual SDKError SetTool(SDKViewType viewtype, AnnotationToolType type) = 0;
DEFINE_FUNC_2(SetTool, SDKError, SDKViewType, viewtype, AnnotationToolType, type)
//virtual SDKError Clear(SDKViewType viewtype, AnnotationClearType type) = 0;
DEFINE_FUNC_2(Clear, SDKError, SDKViewType, viewtype, AnnotationClearType, type)
//virtual SDKError SetColor(SDKViewType viewtype, unsigned long color) = 0;
DEFINE_FUNC_2(SetColor, SDKError, SDKViewType, viewtype, unsigned long, color)
//virtual SDKError SetLineWidth(SDKViewType viewtype, long lineWidth) = 0;
DEFINE_FUNC_2(SetLineWidth, SDKError, SDKViewType, viewtype, long, lineWidth)
//virtual SDKError Undo(SDKViewType viewtype) = 0;
DEFINE_FUNC_1(Undo, SDKError, SDKViewType, viewtype)
//virtual SDKError Redo(SDKViewType viewtype) = 0;
DEFINE_FUNC_1(Redo, SDKError, SDKViewType, viewtype)
//virtual ICustomizedAnnotationController* GetCustomizedAnnotationController() = 0;
DEFINE_FUNC_0(GetCustomizedAnnotationController, ICustomizedAnnotationController*)


END_CLASS_DEFINE(IAnnotationController)
END_ZOOM_SDK_NAMESPACE