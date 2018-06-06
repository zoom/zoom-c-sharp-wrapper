#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class AudioStatus : int 
	{
		Audio_None,
		Audio_Muted,
		Audio_UnMuted,
		Audio_Muted_ByHost,
		Audio_UnMuted_ByHost,
		Audio_MutedAll_ByHost,
		Audio_UnMutedAll_ByHost,
	};

	public interface class IUserAudioStatusDotNetWrap
	{
	public:
		unsigned int GetUserId();
		AudioStatus GetStatus();
		AudioType   GetAudioType();
	};

	public delegate void onUserAudioStatusChange(array<IUserAudioStatusDotNetWrap^ >^ lstAudioStatusChange);
	public delegate void onUserActiveAudioChange(array<unsigned int>^ lstActiveAudio);

	public interface class IMeetingAudioControllerDotNetWrap
	{
	public:
		SDKError JoinVoip();
		SDKError LeaveVoip();
		SDKError MuteAudio(unsigned int userid, bool allowUnmuteBySelf);
		SDKError UnMuteAudio(unsigned int userid);
		bool CanUnMuteBySelf();
		SDKError EnableMuteOnEntry(bool bEnable);
		SDKError EnablePlayChimeWhenEnterOrExit(bool bEnable);

		void Add_CB_onUserAudioStatusChange(onUserAudioStatusChange^ cb);
		void Add_CB_onUserActiveAudioChange(onUserActiveAudioChange^ cb);
	};

	private ref class CMeetingAudioControllerDotNetWrap sealed : public IMeetingAudioControllerDotNetWrap
	{
	public:
		static property CMeetingAudioControllerDotNetWrap^ Instance
		{
			CMeetingAudioControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procUserAudioStatusChange(array<IUserAudioStatusDotNetWrap^ >^ lstAudioStatusChange);
		void procUserActiveAudioChange(array<unsigned int>^ lstActiveAudio);

		virtual SDKError JoinVoip();
		virtual SDKError LeaveVoip();
		virtual SDKError MuteAudio(unsigned int userid, bool allowUnmuteBySelf);
		virtual SDKError UnMuteAudio(unsigned int userid);
		virtual bool CanUnMuteBySelf();
		virtual SDKError EnableMuteOnEntry(bool bEnable);
		virtual SDKError EnablePlayChimeWhenEnterOrExit(bool bEnable);
		virtual void Add_CB_onUserAudioStatusChange(onUserAudioStatusChange^ cb)
		{
			event_onUserAudioStatusChange += cb;
		}

		virtual void Add_CB_onUserActiveAudioChange(onUserActiveAudioChange^ cb)
		{
			event_onUserActiveAudioChange += cb;
		}
	private:

		event onUserAudioStatusChange^ event_onUserAudioStatusChange;
		event onUserActiveAudioChange^ event_onUserActiveAudioChange;
		static CMeetingAudioControllerDotNetWrap^ m_Instance = gcnew CMeetingAudioControllerDotNetWrap;
	};
}