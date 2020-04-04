#include "stdafx.h"
#include "wrap/customized_ui_components_wrap/customized_annotation_obj_wrap.h"
#include "customized_annotation_dotnet_wrap.h"
#include "wrap/sdk_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {
	// Translate event
	class CustomizedAnnotationControllerEventHandler
	{
	public:
		static CustomizedAnnotationControllerEventHandler& GetInst()
		{
			static CustomizedAnnotationControllerEventHandler inst;
			return inst;
		}

		void onCustomizedAnnotationObjDestroyed(ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObj* obj_)
		{
			if (CCustomizedAnnotationControllerDotNetWrap::Instance)
			{
				if (obj_)
				{
					ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* pWrap = new ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap;
					pWrap->Init(obj_);
					CCustomizedAnnotationControllerDotNetWrap::Instance->ProcCustomizedAnnotationObjDestroyed(gcnew ICustomizedAnnotationObjDotNetImpl(pWrap));
					delete pWrap;
				}
			}
		}

		void onSharingShareAnnotationStatusChanged(ZOOM_SDK_NAMESPACE::ICustomizedShareRender* share_render_, ZOOM_SDK_NAMESPACE::CustomizedShareAnnotationStatus status_)
		{
			if (CCustomizedAnnotationControllerDotNetWrap::Instance)
			{
				//Since the share sender doesn't have a real share render, the SDK will return a null here, we needn't a null judgement here..
				//if (share_render_ != NULL)
				{
					ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pWrap = new ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap;
					pWrap->Init(share_render_);
					ZOOM_SDK_DOTNET_WRAP::CustomizedShareAnnotationStatus wrap_status = (ZOOM_SDK_DOTNET_WRAP::CustomizedShareAnnotationStatus)status_;
					CCustomizedAnnotationControllerDotNetWrap::Instance->ProcSharingShareAnnotationStatusChanged(gcnew ICustomizedShareRenderDotNetImpl(pWrap), wrap_status);
					delete pWrap;
				}
			}
		}

	private:
		CustomizedAnnotationControllerEventHandler() {}
	};

	CCustomizedAnnotationControllerDotNetWrap::CCustomizedAnnotationControllerDotNetWrap()
	{
	}

	CCustomizedAnnotationControllerDotNetWrap::~CCustomizedAnnotationControllerDotNetWrap()
	{
	}

	void CCustomizedAnnotationControllerDotNetWrap::BindEvent(ICustomizedShareRenderDotNetWrap^ view_share_render)
	{
		ZOOM_SDK_NAMESPACE::ICustomizedShareRender* sdk_share_render = NULL;
		if (view_share_render == nullptr || ((CCustomizedShareRenderDotNetWrap^)view_share_render)->Inner() == nullptr)
		{
			sdk_share_render = NULL;
		}
		else
		{
			sdk_share_render = ((CCustomizedShareRenderDotNetWrap^)view_share_render)->Inner()->GetSDKObj()->GetSDKObj();
		}

		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationControllerWrap& customizedAnnotationControllerWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetAnnotationController().GetCustomizedAnnotationController(sdk_share_render);

		customizedAnnotationControllerWrap.m_cbonCustomizedAnnotationObjDestroyed =
			std::bind(&CustomizedAnnotationControllerEventHandler::onCustomizedAnnotationObjDestroyed, &CustomizedAnnotationControllerEventHandler::GetInst(), std::placeholders::_1);

		customizedAnnotationControllerWrap.m_cbonSharingShareAnnotationStatusChanged =
			std::bind(&CustomizedAnnotationControllerEventHandler::onSharingShareAnnotationStatusChanged, &CustomizedAnnotationControllerEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);

	}

	void CCustomizedAnnotationControllerDotNetWrap::ProcCustomizedAnnotationObjDestroyed(ICustomizedAnnotationObjDotNet^ obj_)
	{
		event_onCustomizedAnnotationObjDestroyed(obj_);
	}

	void CCustomizedAnnotationControllerDotNetWrap::ProcSharingShareAnnotationStatusChanged(ICustomizedShareRenderDotNet^ share_render_, CustomizedShareAnnotationStatus status_)
	{
		event_onSharingShareAnnotationStatusChanged(share_render_, status_);
	}
	
	ICustomizedAnnotationObjDotNetWrap^ CCustomizedAnnotationControllerDotNetWrap::CreateAnnoObj(ICustomizedShareRenderDotNetWrap^ view_share_render)
	{
		ICustomizedAnnotationObjDotNetWrap^ annotation_object = nullptr;
		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObj* pObj(NULL);
		SDKError result;
		if (view_share_render == nullptr || ((CCustomizedShareRenderDotNetWrap^)view_share_render)->Inner() == nullptr)
		{
			result = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetAnnotationController().GetCustomizedAnnotationController().CreateAnnoObj(NULL, &pObj);
		}
		else
		{
			ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pShareRender = ((CCustomizedShareRenderDotNetWrap^)view_share_render)->Inner()->GetSDKObj();
			result = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetAnnotationController().GetCustomizedAnnotationController(pShareRender->GetSDKObj()).CreateAnnoObj(pShareRender->GetSDKObj(), &pObj);
		}
		if (result == SDKError::SDKERR_SUCCESS)
		{
			ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* pObjWrap(NULL);
			pObjWrap = new ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap;
			if (pObjWrap)
			{
				pObjWrap->Init(pObj);
				annotation_object = gcnew CCustomizedAnnotationObjDotNetWrap(pObjWrap);
			}
		}

		return annotation_object;
	}

	SDKError CCustomizedAnnotationControllerDotNetWrap::DestroyAnnoObj(ICustomizedAnnotationObjDotNetWrap^ anno_obj)
	{
		if (anno_obj == nullptr || ((CCustomizedAnnotationObjDotNetWrap^)anno_obj)->Inner() == nullptr)
		{
			return SDKError::SDKERR_INVALID_PARAMETER;
		}

		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationObjWrap* pAnnoObj = ((CCustomizedAnnotationObjDotNetWrap^)anno_obj)->Inner()->GetSDKObj();
		if (pAnnoObj)
		{
			return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetAnnotationController().GetCustomizedAnnotationController().DestroyAnnoObj(pAnnoObj->GetSDKObj());
		}

		return SDKError::SDKERR_UNKNOWN;
	}

}