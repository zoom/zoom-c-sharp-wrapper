#include "stdafx.h"
#include "customized_resource_helper_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	SDKError CCustomizedResourceHelperDotNetWrap::AddCustomizedPictureResource(String^ key_, String^ absolute_resource_path)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap()
			.AddCustomizedPictureResource(PlatformString2WChar(key_), PlatformString2WChar(absolute_resource_path));
	}

	SDKError CCustomizedResourceHelperDotNetWrap::AddCustomizedStringResource(SDKCustomizedStringType customizedType, String^ customizedString)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap()
			.AddCustomizedStringResource((ZOOM_SDK_NAMESPACE::SDKCustomizedStringType)customizedType, PlatformString2WChar(customizedString));
	}
	
	SDKError CCustomizedResourceHelperDotNetWrap::AddCustomizedURLResource(SDKCustomizedURLType customizedType, String^ customizedUrl)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKExtWrap::GetInst().GetCustomizedResourceHelperWrap()
			.AddCustomizedURLResource((ZOOM_SDK_NAMESPACE::SDKCustomizedURLType)customizedType, PlatformString2WChar(customizedUrl));
	}

	CCustomizedResourceHelperDotNetWrap::CCustomizedResourceHelperDotNetWrap()
	{
	}

	CCustomizedResourceHelperDotNetWrap::~CCustomizedResourceHelperDotNetWrap()
	{
	}
}