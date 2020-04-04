#pragma once
#include "zoom_sdk_dotnet_wrap_def.h"
#include "customized_share_render_dotnet_wrap.h"
#include "customized_annotation_obj_dotnet_wrap.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public delegate void onCustomizedAnnotationObjDestroyed(ICustomizedAnnotationObjDotNet^ obj_);
	public delegate void onSharingShareAnnotationStatusChanged(ICustomizedShareRenderDotNet^ share_render_, CustomizedShareAnnotationStatus status_);

	public interface class ICustomizedAnnotationControllerDotNetWrap
	{
	public:
		ICustomizedAnnotationObjDotNetWrap^ CreateAnnoObj(ICustomizedShareRenderDotNetWrap^ view_share_render);
		SDKError DestroyAnnoObj(ICustomizedAnnotationObjDotNetWrap^ anno_obj);

		void Add_CB_onCustomizedAnnotationObjDestroyed(onCustomizedAnnotationObjDestroyed^ cb);
		void Add_CB_onSharingShareAnnotationStatusChanged(onSharingShareAnnotationStatusChanged^ cb);
		void Remove_CB_onCustomizedAnnotationObjDestroyed(onCustomizedAnnotationObjDestroyed^ cb);
		void Remove_CB_onSharingShareAnnotationStatusChanged(onSharingShareAnnotationStatusChanged^ cb);
	};

	private ref class CCustomizedAnnotationControllerDotNetWrap sealed : public ICustomizedAnnotationControllerDotNetWrap
	{
	public:
		static property CCustomizedAnnotationControllerDotNetWrap^ Instance
		{
			CCustomizedAnnotationControllerDotNetWrap^ get() { return m_Instance; }
		}
		//
		void BindEvent(ICustomizedShareRenderDotNetWrap^ view_share_render);
		void ProcCustomizedAnnotationObjDestroyed(ICustomizedAnnotationObjDotNet^ obj_);
		void ProcSharingShareAnnotationStatusChanged(ICustomizedShareRenderDotNet^ share_render_, CustomizedShareAnnotationStatus status_);

		//
		virtual ICustomizedAnnotationObjDotNetWrap^ CreateAnnoObj(ICustomizedShareRenderDotNetWrap^ view_share_render);
		virtual SDKError DestroyAnnoObj(ICustomizedAnnotationObjDotNetWrap^ anno_obj);

		virtual void Add_CB_onCustomizedAnnotationObjDestroyed(onCustomizedAnnotationObjDestroyed^ cb)
		{
			event_onCustomizedAnnotationObjDestroyed += cb;
		}

		virtual void Remove_CB_onCustomizedAnnotationObjDestroyed(onCustomizedAnnotationObjDestroyed^ cb)
		{
			event_onCustomizedAnnotationObjDestroyed -= cb;
		}

		virtual void Add_CB_onSharingShareAnnotationStatusChanged(onSharingShareAnnotationStatusChanged^ cb)
		{
			event_onSharingShareAnnotationStatusChanged += cb;
		}

		virtual void Remove_CB_onSharingShareAnnotationStatusChanged(onSharingShareAnnotationStatusChanged^ cb)
		{
			event_onSharingShareAnnotationStatusChanged -= cb;
		}

	private:
		CCustomizedAnnotationControllerDotNetWrap();
		virtual ~CCustomizedAnnotationControllerDotNetWrap();
		event onCustomizedAnnotationObjDestroyed^ event_onCustomizedAnnotationObjDestroyed;
		event onSharingShareAnnotationStatusChanged^ event_onSharingShareAnnotationStatusChanged;

		static CCustomizedAnnotationControllerDotNetWrap^ m_Instance = gcnew CCustomizedAnnotationControllerDotNetWrap;
	};
}
