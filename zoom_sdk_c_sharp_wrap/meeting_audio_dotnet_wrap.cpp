#include "stdafx.h"
#include "meeting_audio_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate event
	private ref class IUserAudioStatusDotNetWrapImpl sealed : public IUserAudioStatusDotNetWrap
	{
	public:
		IUserAudioStatusDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IUserAudioStatus* pStatus)
		{
			m_pStatus = pStatus;
		}

		virtual unsigned int GetUserId()
		{
			if (m_pStatus)
				m_pStatus->GetUserId();
			return 0;
		}

		virtual AudioStatus GetStatus()
		{
			if (m_pStatus)
				return (AudioStatus)m_pStatus->GetStatus();

			return AudioStatus::Audio_None;
		}

		virtual AudioType   GetAudioType()
		{
			if (m_pStatus)
				return (AudioType)m_pStatus->GetAudioType();

			return AudioType::AUDIOTYPE_NONE;
		}
	private:
		ZOOM_SDK_NAMESPACE::IUserAudioStatus* m_pStatus;
	};

	class MeetingAudioControllerEventHanlder
	{
	public:
		static MeetingAudioControllerEventHanlder& GetInst()
		{
			static MeetingAudioControllerEventHanlder inst;
			return inst;
		}

		virtual void onUserAudioStatusChange(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IUserAudioStatus* >* lstAudioStatusChange, const wchar_t* strAudioStatusList)
		{
			if (CMeetingAudioControllerDotNetWrap::Instance && lstAudioStatusChange && lstAudioStatusChange->GetCount() > 0)
			{
				int count = lstAudioStatusChange->GetCount();
				array<IUserAudioStatusDotNetWrap^ >^ arrayAudio = gcnew array<IUserAudioStatusDotNetWrap^ >(count);
				if (arrayAudio)
				{
					for (int i = 0; i < count; i++)
					{
						arrayAudio[i] = gcnew IUserAudioStatusDotNetWrapImpl(lstAudioStatusChange->GetItem(i));
					}

					CMeetingAudioControllerDotNetWrap::Instance->procUserAudioStatusChange(arrayAudio);
				}
			}
		}

		virtual void onUserActiveAudioChange(ZOOM_SDK_NAMESPACE::IList<unsigned int>* plstActiveAudio)
		{
			if (CMeetingAudioControllerDotNetWrap::Instance)
				CMeetingAudioControllerDotNetWrap::Instance->procUserActiveAudioChange(Convert(plstActiveAudio));
		}

	private:
		MeetingAudioControllerEventHanlder() {}
	};
	//

	void CMeetingAudioControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingAudioControllerWrap& meetingAudio = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingAudioController();
		meetingAudio.m_cbonUserActiveAudioChange =
			std::bind(&MeetingAudioControllerEventHanlder::onUserActiveAudioChange, &MeetingAudioControllerEventHanlder::GetInst(), std::placeholders::_1);

		meetingAudio.m_cbonUserAudioStatusChange =
			std::bind(&MeetingAudioControllerEventHanlder::onUserAudioStatusChange, &MeetingAudioControllerEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}

	void CMeetingAudioControllerDotNetWrap::procUserAudioStatusChange(array<IUserAudioStatusDotNetWrap^ >^ lstAudioStatusChange)
	{
		event_onUserAudioStatusChange(lstAudioStatusChange);
	}

	void CMeetingAudioControllerDotNetWrap::procUserActiveAudioChange(array<unsigned int>^ lstActiveAudio)
	{
		event_onUserActiveAudioChange(lstActiveAudio);
	}

	SDKError CMeetingAudioControllerDotNetWrap::JoinVoip()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().JoinVoip();
	}

	SDKError CMeetingAudioControllerDotNetWrap::LeaveVoip()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().LeaveVoip();
	}

	SDKError CMeetingAudioControllerDotNetWrap::MuteAudio(unsigned int userid, bool allowUnmuteBySelf)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().MuteAudio(userid, allowUnmuteBySelf);
	}

	SDKError CMeetingAudioControllerDotNetWrap::UnMuteAudio(unsigned int userid)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().UnMuteAudio(userid);
	}

	bool CMeetingAudioControllerDotNetWrap::CanUnMuteBySelf()
	{
		return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().CanUnMuteBySelf();
	}

	SDKError CMeetingAudioControllerDotNetWrap::EnableMuteOnEntry(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().EnableMuteOnEntry(bEnable);
	}

	SDKError CMeetingAudioControllerDotNetWrap::EnablePlayChimeWhenEnterOrExit(bool bEnable)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingAudioController().EnablePlayChimeWhenEnterOrExit(bEnable);
	}
}