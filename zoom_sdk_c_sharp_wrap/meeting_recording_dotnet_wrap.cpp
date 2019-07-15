#include "stdafx.h"
#include "meeting_recording_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	private ref class ICustomizedLocalRecordingLayoutHelperDotNetWrapImpl sealed : public ICustomizedLocalRecordingLayoutHelperDotNetWrap
	{
	public:
		ICustomizedLocalRecordingLayoutHelperDotNetWrapImpl(ZOOM_SDK_NAMESPACE::ICustomizedLocalRecordingLayoutHelper* pObj)
		{
			m_pSDKObj = pObj;
		}

		ICustomizedLocalRecordingLayoutHelperDotNetWrapImpl() { m_pSDKObj = NULL; }
		~ICustomizedLocalRecordingLayoutHelperDotNetWrapImpl() {}

		virtual int GetSupportLayout()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->GetSupportLayout();
			}

			return 0;
		}

		virtual array<unsigned int>^ GetValidVideoSourceList()
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::IList<unsigned int>* plstSource = m_pSDKObj->GetValidVideoSourceList();

				if (NULL == plstSource || plstSource->GetCount() <= 0)
				{
					return nullptr;
				}

				int count = plstSource->GetCount();
				array<unsigned int>^ result = gcnew array<unsigned int>(count);
				if (nullptr == result)
				{
					return nullptr;
				}

				for (int i = 0; i < count; i++)
				{
					result[i] = plstSource->GetItem(i);
				}

				return result;
			}

			return nullptr;
		}

		virtual array<unsigned int>^ GetValidRecvSharingSourceList()
		{
			if (m_pSDKObj)
			{
				ZOOM_SDK_NAMESPACE::IList<unsigned int>* plstSource = m_pSDKObj->GetValidRecvSharingSourceList();

				if (NULL == plstSource || plstSource->GetCount() <= 0)
				{
					return nullptr;
				}

				int count = plstSource->GetCount();
				array<unsigned int>^ result = gcnew array<unsigned int>(count);
				if (nullptr == result)
				{
					return nullptr;
				}

				for (int i = 0; i < count; i++)
				{
					result[i] = plstSource->GetItem(i);
				}

				return result;
			}

			return nullptr;
		}

		virtual bool IsSendSharingSourceAvailable()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->IsSendSharingSourceAvailable();
			}

			return false;
		}

		virtual bool HasActiveVideoSource()
		{
			if (m_pSDKObj)
			{
				return m_pSDKObj->HasActiveVideoSource();
			}

			return false;
		}

		virtual SDKError SelectRecordingLayoutMode(RecordingLayoutMode mode)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectRecordingLayoutMode((ZOOM_SDK_NAMESPACE::RECORDING_LAYOUT_MODE)mode);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError AddVideoSourceToRecList(unsigned int userId)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->AddVideoSourceToRecList(userId);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectActiveVideoSource()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectActiveVideoSource();
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectRecvSharingSource(unsigned int userId)
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectRecvSharingSource(userId);
			}

			return SDKError::SDKERR_UNKNOWN;
		}

		virtual SDKError SelectSendSharingSource()
		{
			if (m_pSDKObj)
			{
				return (SDKError)m_pSDKObj->SelectSendSharingSource();
			}

			return SDKError::SDKERR_UNKNOWN;
		}

	private:
		ZOOM_SDK_NAMESPACE::ICustomizedLocalRecordingLayoutHelper* m_pSDKObj;
	};

	// Translate event
	class MeetingRecordingControllerEventHandler
	{
	public:
		static MeetingRecordingControllerEventHandler& GetInst()
		{
			static MeetingRecordingControllerEventHandler inst;
			return inst;
		}

		virtual void onRecording2MP4Done(bool bsuccess, int iResult, const wchar_t* szPath)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecording2MP4Done(bsuccess, iResult, WChar2PlatformString(szPath));
		}

		virtual void onRecording2MP4Processing(int iPercentage)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecording2MP4Processing(iPercentage);
		}

		virtual void onRecordingStatus(ZOOM_SDK_NAMESPACE::RecordingStatus status)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecordingStatus((RecordingStatus)status);
		}

		virtual void onRecordPriviligeChanged(bool bCanRec)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procRecordPriviligeChanged(bCanRec);
		}

		virtual void onCloudRecordingStatus(ZOOM_SDK_NAMESPACE::RecordingStatus status)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
				CMeetingRecordingControllerDotNetWrap::Instance->procCloudRecordingStatus((RecordingStatus)status);
		}

		virtual void onCustomizedLocalRecordingSourceNotification(ZOOM_SDK_NAMESPACE::ICustomizedLocalRecordingLayoutHelper* layoutHelper)
		{
			if (CMeetingRecordingControllerDotNetWrap::Instance)
			{
				CMeetingRecordingControllerDotNetWrap::Instance->procCustomizedLocalRecordingSourceNotification(
					gcnew ICustomizedLocalRecordingLayoutHelperDotNetWrapImpl(layoutHelper));
			}
		}

	private:
		MeetingRecordingControllerEventHandler() {}
	};
	//

	SDKError CMeetingRecordingControllerDotNetWrap::StartRecording(DateTime^% startTimestamp, String^ recPath)
	{
		time_t time_c;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().StartRecording(time_c, const_cast<wchar_t*>(PlatformString2WChar(recPath)));

		if (startTimestamp)
			startTimestamp = time_t2DateTime(time_c);
		
		return err;
	}

	SDKError CMeetingRecordingControllerDotNetWrap::StopRecording(DateTime^% stopTimestamp)
	{
		time_t time_c;
		SDKError err = (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().StopRecording(time_c);

		if (stopTimestamp)
			stopTimestamp = time_t2DateTime(time_c);

		return err;
	}

	SDKError CMeetingRecordingControllerDotNetWrap::CanStartRecording(bool cloudRecording, unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().CanStartRecording(cloudRecording, userId);
	}

	SDKError CMeetingRecordingControllerDotNetWrap::CanAllowDisAllowLocalRecording()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().CanAllowDisAllowLocalRecording();
	}

	SDKError CMeetingRecordingControllerDotNetWrap::StartCloudRecording()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().StartCloudRecording();
	}

	SDKError CMeetingRecordingControllerDotNetWrap::StopCloudRecording()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().StopCloudRecording();
	}

	SDKError CMeetingRecordingControllerDotNetWrap::IsSupportLocalRecording(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().IsSupportLocalRecording(userId);
	}

	SDKError CMeetingRecordingControllerDotNetWrap::AllowLocalRecording(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().AllowLocalRecording(userId);
	}

	SDKError CMeetingRecordingControllerDotNetWrap::DisAllowLocalRecording(unsigned int userId)
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().DisAllowLocalRecording(userId);
	}

	SDKError CMeetingRecordingControllerDotNetWrap::RequestCustomizedLocalRecordingSource()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().
			GetMeetingRecordingController().RequestCustomizedLocalRecordingSource();
	}

	void CMeetingRecordingControllerDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::IMeetingRecordingControllerWrap& meetingRec = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingRecordingController();
		meetingRec.m_cbonRecording2MP4Done =
			std::bind(&MeetingRecordingControllerEventHandler::onRecording2MP4Done,
				&MeetingRecordingControllerEventHandler::GetInst(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		meetingRec.m_cbonRecording2MP4Processing =
			std::bind(&MeetingRecordingControllerEventHandler::onRecording2MP4Processing,
				&MeetingRecordingControllerEventHandler::GetInst(), std::placeholders::_1);
		meetingRec.m_cbonRecordingStatus =
			std::bind(&MeetingRecordingControllerEventHandler::onRecordingStatus,
				&MeetingRecordingControllerEventHandler::GetInst(), std::placeholders::_1);
		meetingRec.m_cbonRecordPriviligeChanged =
			std::bind(&MeetingRecordingControllerEventHandler::onRecordPriviligeChanged,
				&MeetingRecordingControllerEventHandler::GetInst(), std::placeholders::_1);
		meetingRec.m_cbonCloudRecordingStatus =
			std::bind(&MeetingRecordingControllerEventHandler::onCloudRecordingStatus,
				&MeetingRecordingControllerEventHandler::GetInst(), std::placeholders::_1);
		meetingRec.m_cbonCustomizedLocalRecordingSourceNotification =
			std::bind(&MeetingRecordingControllerEventHandler::onCustomizedLocalRecordingSourceNotification,
				&MeetingRecordingControllerEventHandler::GetInst(), std::placeholders::_1);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecording2MP4Done(bool bsuccess, int iResult, String^ szPath)
	{
		event_onRecording2MP4Done(bsuccess, iResult, szPath);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecording2MP4Processing(int iPercentage)
	{
		event_onRecording2MP4Processing(iPercentage);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecordingStatus(RecordingStatus status)
	{
		event_onRecordingStatus(status);
	}

	void CMeetingRecordingControllerDotNetWrap::procRecordPriviligeChanged(bool bCanRec)
	{
		event_onRecordPriviligeChanged(bCanRec);
	}

	void CMeetingRecordingControllerDotNetWrap::procCloudRecordingStatus(RecordingStatus status)
	{
		event_onCloudRecordingStatus(status);
	}

	void CMeetingRecordingControllerDotNetWrap::procCustomizedLocalRecordingSourceNotification(ICustomizedLocalRecordingLayoutHelperDotNetWrap^ layoutHelper)
	{
		event_onCustomizedLocalRecordingSourceNotification(layoutHelper);
	}
}