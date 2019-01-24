#pragma once
using namespace System;
//ref zoom_sdk_def.h
namespace ZOOM_SDK_DOTNET_WRAP {
	public enum class SDKError : int
	{
		SDKERR_SUCCESS = 0,///< Success Result
		SDKERR_NO_IMPL,///< Not support this feature now 
		SDKERR_WRONG_USEAGE,///< Wrong useage about this feature 
		SDKERR_INVALID_PARAMETER,///< Wrong parameter 
		SDKERR_MODULE_LOAD_FAILED,///< Load module failed 
		SDKERR_MEMORY_FAILED,///< No memory allocated 
		SDKERR_SERVICE_FAILED,///< Internal service error 
		SDKERR_UNINITIALIZE,///< Not initialize before use 
		SDKERR_UNAUTHENTICATION,///< Not Authentication before use
		SDKERR_NORECORDINGINPROCESS,///< No recording in process
		SDKERR_TRANSCODER_NOFOUND,///< can't find transcoder module
		SDKERR_VIDEO_NOTREADY,///< Video service not ready
		SDKERR_NO_PERMISSION,///< No premission to do this
		SDKERR_UNKNOWN,///< Unknown error 
		SDKERR_OTHER_SDK_INSTANCE_RUNNING,
	};

	public enum class SDK_LANGUAGE_ID : int
	{
		LANGUAGE_Unknow = 0,
		LANGUAGE_English,
		LANGUAGE_Chinese_Simplified,
		LANGUAGE_Chinese_Traditional,
		LANGUAGE_Japanese,
		LANGUAGE_Spanish,
		LANGUAGE_German,
		LANGUAGE_French,
		LANGUAGE_Italian,
		LANGUAGE_Portuguese,
		LANGUAGE_Russian,
	};

	public enum class CustomizedLanguageType : int
	{
		CustomizedLanguage_None,
		CustomizedLanguage_FilePath,
		CustomizedLanguage_Content,
	};

	public value class CustomizedLanguageInfo sealed
	{
	public:
		String^ language_name;
		String^ language_info;
		CustomizedLanguageType langType;
	};

	public value class ConfigurableOptions sealed
	{
	public:
		CustomizedLanguageInfo customized_language;
	};

	public value class InitParam sealed
	{
	public:
		String^ sdk_dll_path;
		String^ web_domain;///< Web Domain
		String^ brand_name;///< Branding name
		String^ support_url;///< Support Url
		void* res_instance;///< resource moudle handle
		unsigned int window_small_icon_id;///< windows small icon file path
		unsigned int window_big_icon_id;///< windows small icon file path
		SDK_LANGUAGE_ID language_id;///< sdk language ID
		ConfigurableOptions config_opts;
	};

	public value class HWNDDotNet sealed
	{
	public:
		UInt32 value;
	};

	public enum class SDKViewType : int
	{
		SDK_FIRST_VIEW,
		SDK_SECOND_VIEW,
	};
	
	public enum class AudioType : int
	{
		AUDIOTYPE_NONE,
		AUDIOTYPE_VOIP,
		AUDIOTYPE_PHONE,
		AUDIOTYPE_UNKNOW,
	};

	public enum class UserRole : int
	{
		USERROLE_NONE,
		USERROLE_HOST,
		USERROLE_COHOST,
		USERROLE_PANELIST,
		USERROLE_BREAKOUTROOM_MODERATOR,
		USERROLE_ATTENDEE,
	};

	public interface class IUserInfoDotNetWrap
	{
	public:
		String^ GetUserName();
		String^ GetEmail();
		bool IsHost();
		unsigned int GetUserID();
		bool IsVideoOn();
		bool IsAudioMuted();
		AudioType GetAudioJoinType();
		bool IsMySelf();
		bool IsInWaitingRoom();
		bool IsRaiseHand();
		UserRole GetUserRole();
		bool IsPurePhoneUser();
	};
}