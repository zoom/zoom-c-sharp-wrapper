#include "stdafx.h"
#include "wrap/customized_ui_components_wrap/customized_video_container_wrap.h"
#include "customized_ui_mgr_DotNet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	// Translate event
	class CustomizedUIMgrEventHandler
	{
	public:
		static CustomizedUIMgrEventHandler& GetInst()
		{
			static CustomizedUIMgrEventHandler inst;
			return inst;
		}

		void onVideoContainerDestroyed(ZOOM_SDK_NAMESPACE::ICustomizedVideoContainer* pContainer)
		{
			if (CCustomizedUIMgrDotNetWrap::Instance)
			{
				if (pContainer)
				{
					ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* pWrap = new ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap;
					pWrap->Init(pContainer);
					CCustomizedUIMgrDotNetWrap::Instance->ProcVideoContainerDestroyed(gcnew ICustomizedVideoContainerDotNetImpl(pWrap));
					delete pWrap;
				}
				else
				{
					CCustomizedUIMgrDotNetWrap::Instance->ProcVideoContainerDestroyed(nullptr);
				}
			}
		}

		void onShareRenderDestroyed(ZOOM_SDK_NAMESPACE::ICustomizedShareRender* pRender)
		{
			if (CCustomizedUIMgrDotNetWrap::Instance)
			{
				if (pRender)
				{
					ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pWrap = new ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap;
					pWrap->Init(pRender);
					CCustomizedUIMgrDotNetWrap::Instance->ProcShareRenderDestroyed(gcnew ICustomizedShareRenderDotNetImpl(pWrap));
					delete pWrap;
				}
				else
				{
					CCustomizedUIMgrDotNetWrap::Instance->ProcShareRenderDestroyed(nullptr);
				}
			}
		}

	private:
		CustomizedUIMgrEventHandler() {}
	};
	//

	CCustomizedUIMgrDotNetWrap::CCustomizedUIMgrDotNetWrap()
	{
	}

	CCustomizedUIMgrDotNetWrap::~CCustomizedUIMgrDotNetWrap()
	{
	}

	void CCustomizedUIMgrDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::ICustomizedUIMgrWrap& customizedUIMgrWrap = ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap();
		
		customizedUIMgrWrap.m_cbonVideoContainerDestroyed =
			std::bind(&CustomizedUIMgrEventHandler::onVideoContainerDestroyed, &CustomizedUIMgrEventHandler::GetInst(), std::placeholders::_1);

		customizedUIMgrWrap.m_cbonShareRenderDestroyed =
			std::bind(&CustomizedUIMgrEventHandler::onShareRenderDestroyed, &CustomizedUIMgrEventHandler::GetInst(), std::placeholders::_1);
	}

	void CCustomizedUIMgrDotNetWrap::ProcVideoContainerDestroyed(ICustomizedVideoContainerDotNet^ pContainer)
	{
		event_onVideoContainerDestroyed(pContainer);
	}

	void CCustomizedUIMgrDotNetWrap::ProcShareRenderDestroyed(ICustomizedShareRenderDotNet^ pRender)
	{
		event_onShareRenderDestroyed(pRender);
	}
	//

	SDKError CCustomizedUIMgrDotNetWrap::HasLicense()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().HasLicense();
	}
	
	ICustomizedVideoContainerDotNetWrap^ CCustomizedUIMgrDotNetWrap::CreateVideoContainer(IntPtr hParentWnd, RECT rc)
	{
		ICustomizedVideoContainerDotNetWrap^ container = nullptr;

		ZOOM_SDK_NAMESPACE::ICustomizedVideoContainer* pObj(NULL);
		::RECT rc_native;
		rc_native.top = rc.Top;
		rc_native.left = rc.Left;
		rc_native.bottom = rc.Bottom;
		rc_native.right = rc.Right;
		SDKError result = (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().
			CreateVideoContainer(&pObj, static_cast<HWND>(hParentWnd.ToPointer()), rc_native);
		if (result == SDKError::SDKERR_SUCCESS)
		{
			// Create the wrapper
			ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* pObjWrap(NULL);
			pObjWrap = new ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap;
			if (pObjWrap)
			{
				// And initialize with the SDK object
				pObjWrap->Init(pObj);

				container = gcnew CCustomizedVideoContainerDotNetWrap(pObjWrap);
			}
		}

		return container;
	}

	SDKError CCustomizedUIMgrDotNetWrap::DestroyVideoContainer(ICustomizedVideoContainerDotNetWrap^ pContainer)
	{
		if (pContainer == nullptr || ((CCustomizedVideoContainerDotNetWrap^)pContainer)->Inner() == nullptr)
		{
			return SDKError::SDKERR_INVALID_PARAMETER;
		}

		ZOOM_SDK_NAMESPACE::ICustomizedVideoContainerWrap* pVideoContainer = ((CCustomizedVideoContainerDotNetWrap^)pContainer)->Inner()->GetSDKObj();
		if (pVideoContainer)
		{
			return (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().DestroyVideoContainer(pVideoContainer->GetSDKObj());
		}

		return SDKError::SDKERR_UNKNOWN;
	}

	SDKError CCustomizedUIMgrDotNetWrap::DestroyAllVideoContainer()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().DestroyAllVideoContainer();
	}

	ICustomizedShareRenderDotNetWrap^ CCustomizedUIMgrDotNetWrap::CreateShareRender(IntPtr hParentWnd, RECT rc)
	{
		ICustomizedShareRenderDotNetWrap^ render = nullptr;

		ZOOM_SDK_NAMESPACE::ICustomizedShareRender* pObj(NULL);
		::RECT rc_native;
		rc_native.top = rc.Top;
		rc_native.left = rc.Left;
		rc_native.bottom = rc.Bottom;
		rc_native.right = rc.Right;
		SDKError result = (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().
			CreateShareRender(&pObj, static_cast<HWND>(hParentWnd.ToPointer()), rc_native);
		if (result == SDKError::SDKERR_SUCCESS)
		{
			// Create the wrapper
			ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pObjWrap(NULL);
			pObjWrap = new ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap;
			if (pObjWrap)
			{
				// And initialize with the SDK object
				pObjWrap->Init(pObj);

				render = gcnew CCustomizedShareRenderDotNetWrap(pObjWrap);
			}
		}

		return render;
	}

	SDKError CCustomizedUIMgrDotNetWrap::DestroyShareRender(ICustomizedShareRenderDotNetWrap^ pRender)
	{
		if (pRender == nullptr || ((CCustomizedShareRenderDotNetWrap^)pRender)->Inner() == nullptr)
		{
			return SDKError::SDKERR_INVALID_PARAMETER;
		}

		ZOOM_SDK_NAMESPACE::ICustomizedShareRenderWrap* pShareRender = ((CCustomizedShareRenderDotNetWrap^)pRender)->Inner()->GetSDKObj();
		if (pShareRender)
		{
			return (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().DestroyShareRender(pShareRender->GetSDKObj());
		}

		return SDKError::SDKERR_UNKNOWN;
	}

	SDKError CCustomizedUIMgrDotNetWrap::DestroyAllShareRender()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKCustomizedUIWrap::GetInst().GetCustomizedUIMgrWrap().DestroyAllShareRender();
	}
}