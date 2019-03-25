#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	
	public enum class SDKCustomizedStringType : int
	{
	SDK_Customized_LiveStream_MenuString_LiveOn_String = 0,///<The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item ON %S on live streaming. 
	SDK_Customized_LiveStream_MenuString_LiveView_String,///<The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item VIEW STREAM ON %S on live streaming.
	SDK_Customized_LiveStream_MenuString_LiveStop_String,///<The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item STOP LIVE STREAM on live streaming.
	SDK_Customized_LiveStream_MenuString_CopyURL_String,///<The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item COPY STREAMING LINK on live streaming.
	SDK_Customized_Title_App,	///<The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI.
	SDK_Customized_Title_ZoomVideo,  ///<The new string must be the same format as "Zoom Participant ID: %s   Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI.
	SDK_Customized_Title_FreeZoomVideo, ///<The new string must be the same format as "Zoom Participant ID: %s  %d-Minutes Meeting ID:%s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status. 
	SDK_Customized_Title_ViewOnly_ZoomVideo, ///<The new string must end up with "%s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI.
	SDK_Customized_Title_ViewOnly_FreeZoomVideo, ///<The new string must be the same format as "Zoom %d-Minutes Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status. 
	};
	
	public enum class SDKCustomizedURLType : int
	{
	SDKCustomizedURL_VITRULBG_HELP, ///<Set the custom help URL in the virtual background tab page.
	SDKCustomizedURL_VITRULBG_LEARN_MORE,///<Set the custom Learn More URL in the virtual background tab page.
	SDKCustomizedURL_SUPPORTURL, ///<Set the Support URL in the meeting.
	};

	public interface class ICustomizedResourceHelperDotNetWrap
	{
	public:
		SDKError AddCustomizedPictureResource(String^ key_, String^ absolute_resource_path);
		SDKError AddCustomizedStringResource(SDKCustomizedStringType customizedType, String^ customizedString);
		SDKError AddCustomizedURLResource(SDKCustomizedURLType customizedType, String^ customizedUrl);
	};

	private ref class CCustomizedResourceHelperDotNetWrap sealed: public ICustomizedResourceHelperDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
 		static property CCustomizedResourceHelperDotNetWrap^ Instance
 		{
 			CCustomizedResourceHelperDotNetWrap^ get() { return m_Instance; }
		}

		virtual SDKError AddCustomizedPictureResource(String^ key_, String^ absolute_resource_path);
		virtual SDKError AddCustomizedStringResource(SDKCustomizedStringType customizedType, String^ customizedString);
		virtual SDKError AddCustomizedURLResource(SDKCustomizedURLType customizedType, String^ customizedUrl);

	private:
		CCustomizedResourceHelperDotNetWrap();
		virtual ~CCustomizedResourceHelperDotNetWrap();
		static CCustomizedResourceHelperDotNetWrap^ m_Instance = gcnew CCustomizedResourceHelperDotNetWrap;
	};
}
