#pragma once
using namespace System;
using namespace System::Windows;
#include "customized_video_container_dotnet_wrap.h"
#include "customized_share_render_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_def.h"

namespace ZOOM_SDK_DOTNET_WRAP {

	public delegate void onVideoContainerDestroyed(ICustomizedVideoContainerDotNet^ pContainer);
	public delegate void onShareRenderDestroyed(ICustomizedShareRenderDotNet^ pRender);

	public interface class ICustomizedUIMgrDotNetWrap
	{
	public:
		SDKError HasLicense();
		ICustomizedVideoContainerDotNetWrap^ CreateVideoContainer(IntPtr hParentWnd, RECT rc);
		SDKError DestroyVideoContainer(ICustomizedVideoContainerDotNetWrap^ pContainer);
		SDKError DestroyAllVideoContainer();
		ICustomizedShareRenderDotNetWrap^ CreateShareRender(IntPtr hParentWnd, RECT rc);
		SDKError DestroyShareRender(ICustomizedShareRenderDotNetWrap^ pRender);
		SDKError DestroyAllShareRender();

		void Add_CB_onVideoContainerDestroyed(onVideoContainerDestroyed^ cb);
		void Add_CB_onShareRenderDestroyed(onShareRenderDestroyed^ cb);
		void Remove_CB_onVideoContainerDestroyed(onVideoContainerDestroyed^ cb);
		void Remove_CB_onShareRenderDestroyed(onShareRenderDestroyed^ cb);
	};

	private ref class CCustomizedUIMgrDotNetWrap sealed : public ICustomizedUIMgrDotNetWrap
	{
	public:
		static property CCustomizedUIMgrDotNetWrap^ Instance
		{
			CCustomizedUIMgrDotNetWrap^ get() { return m_Instance; }
		}

		//
		void BindEvent();
		void ProcVideoContainerDestroyed(ICustomizedVideoContainerDotNet^ pContainer);
		void ProcShareRenderDestroyed(ICustomizedShareRenderDotNet^ pRender);

		//
		virtual SDKError HasLicense();
		virtual ICustomizedVideoContainerDotNetWrap^ CreateVideoContainer(IntPtr hParentWnd, RECT rc);
		virtual SDKError DestroyVideoContainer(ICustomizedVideoContainerDotNetWrap^ pRender);
		virtual SDKError DestroyAllVideoContainer();
		virtual ICustomizedShareRenderDotNetWrap^ CreateShareRender(IntPtr hParentWnd, RECT rc);
		virtual SDKError DestroyShareRender(ICustomizedShareRenderDotNetWrap^ pRender);
		virtual SDKError DestroyAllShareRender();

		virtual void Add_CB_onVideoContainerDestroyed(onVideoContainerDestroyed^ cb)
		{
			event_onVideoContainerDestroyed += cb;
		}

		virtual void Remove_CB_onVideoContainerDestroyed(onVideoContainerDestroyed^ cb)
		{
			event_onVideoContainerDestroyed -= cb;
		}

		virtual void Add_CB_onShareRenderDestroyed(onShareRenderDestroyed^ cb)
		{
			event_onShareRenderDestroyed += cb;
		}

		virtual void Remove_CB_onShareRenderDestroyed(onShareRenderDestroyed^ cb)
		{
			event_onShareRenderDestroyed -= cb;
		}

	private:
		CCustomizedUIMgrDotNetWrap();
		virtual ~CCustomizedUIMgrDotNetWrap();
		event onVideoContainerDestroyed^ event_onVideoContainerDestroyed;
		event onShareRenderDestroyed^ event_onShareRenderDestroyed;

		static CCustomizedUIMgrDotNetWrap^ m_Instance = gcnew CCustomizedUIMgrDotNetWrap;
	};
}