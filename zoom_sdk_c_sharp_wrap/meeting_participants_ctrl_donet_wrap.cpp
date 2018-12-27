#include "stdafx.h"
#include "meeting_participants_ctrl_donet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	//translate event
	class ParticipantsEventHandler
	{
	public:
		static ParticipantsEventHandler& GetInst()
		{
			static ParticipantsEventHandler inst;
			return inst;
		}

		void onUserJoin(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
		{
			if (CMeetingParticipantsControllerDotNetWrap::Instance)
			{
				CMeetingParticipantsControllerDotNetWrap::Instance->procUserJoin(Convert(lstUserID));
			}
		}

		void onUserLeft(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
		{
			if (CMeetingParticipantsControllerDotNetWrap::Instance)
			{
				CMeetingParticipantsControllerDotNetWrap::Instance->procUserLeft(Convert(lstUserID));
			}
		}

		void onHostChangeNotification(unsigned int userId)
		{
			if (CMeetingParticipantsControllerDotNetWrap::Instance)
				CMeetingParticipantsControllerDotNetWrap::Instance->procHostChangeNotification(userId);
		}

		void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userId)
		{
			if (CMeetingParticipantsControllerDotNetWrap::Instance)
				CMeetingParticipantsControllerDotNetWrap::Instance->procLowOrRaiseHandStatusChanged(bLow, userId);
		}

		void onUserNameChanged(unsigned int userId, const wchar_t* userName)
		{
			if (CMeetingParticipantsControllerDotNetWrap::Instance)
				CMeetingParticipantsControllerDotNetWrap::Instance->procUserNameChanged(userId, WChar2PlatformString(userName));
		}
	private:
		ParticipantsEventHandler() {}
	};
	//

	void CMeetingParticipantsControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingParticipantsControllerWrap& meetingParticipants = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController();
		meetingParticipants.m_cbonUserJoin =
			std::bind(&ParticipantsEventHandler::onUserJoin,
				&ParticipantsEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);

		meetingParticipants.m_cbonUserLeft =
			std::bind(&ParticipantsEventHandler::onUserLeft,
				&ParticipantsEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);

		meetingParticipants.m_cbonHostChangeNotification =
			std::bind(&ParticipantsEventHandler::onHostChangeNotification,
				&ParticipantsEventHandler::GetInst(), std::placeholders::_1);

		meetingParticipants.m_cbonLowOrRaiseHandStatusChanged =
			std::bind(&ParticipantsEventHandler::onLowOrRaiseHandStatusChanged,
				&ParticipantsEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);

		meetingParticipants.m_cbonUserNameChanged =
			std::bind(&ParticipantsEventHandler::onUserNameChanged,
				&ParticipantsEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2);
	}
	void CMeetingParticipantsControllerDotNetWrap::procUserJoin(array<unsigned int >^ lstUserID)
	{
		event_onUserJoin(lstUserID);
	}

	void CMeetingParticipantsControllerDotNetWrap::procUserLeft(array<unsigned int >^ lstUserID)
	{
		event_onUserLeft(lstUserID);
	}

	void CMeetingParticipantsControllerDotNetWrap::procHostChangeNotification(unsigned int userId)
	{
		event_onHostChangeNotification(userId);
	}

	void CMeetingParticipantsControllerDotNetWrap::procLowOrRaiseHandStatusChanged(bool lower, unsigned int userId)
	{
		event_onLowOrRaiseHandStatusChanged(lower, userId);
	}

	void CMeetingParticipantsControllerDotNetWrap::procUserNameChanged(unsigned int userId, String^ userName)
	{
		event_onUserNameChanged(userId, userName);
	}

	array<unsigned int >^ CMeetingParticipantsControllerDotNetWrap::GetParticipantsList()
	{
		ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstParticipants = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().GetParticipantsList();
		if (lstParticipants && lstParticipants->GetCount() > 0)
		{
			return Convert(lstParticipants);
		}

		return nullptr;
	}

	IUserInfoDotNetWrap^ CMeetingParticipantsControllerDotNetWrap::GetUserByUserID(unsigned int userId)
	{
		return gcnew IUserInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().GetUserByUserID(userId));
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::LowerAllHands()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().LowerAllHands();
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::ChangeUserName(const unsigned int userId, String^ userName, bool saveUserName)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().ChangeUserName(userId, PlatformString2WChar(userName), saveUserName);
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::LowerHand(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().LowerHand(userId);
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::RaiseHand()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().RaiseHand();
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::MakeHost(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().MakeHost(userId);
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::ExpelUser(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().ExpelUser(userId);
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::ReclaimHost()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().ReclaimHost();
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::CanReclaimHost(bool^% canReclaimHost)
	{
		bool c_bCanReclaimHost = false;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().CanReclaimHost(c_bCanReclaimHost);
		if (canReclaimHost)
			*canReclaimHost = c_bCanReclaimHost;
		return err;
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::ReclaimHostByHostKey(String^ hostKey)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().ReclaimHostByHostKey(PlatformString2WChar(hostKey));
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::CanBeCoHost(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().CanbeCohost(userId);
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::AssignCoHost(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().AssignCoHost(userId);
	}

	SDKError CMeetingParticipantsControllerDotNetWrap::RevokeCoHost(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingParticipantsController().RevokeCoHost(userId);
	}
}