#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;
#include <stdio.h>  
#include <stdlib.h>  
#include <vcclr.h>  
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/sdk_wrap.h"
#include "meeting_h323_helper_dotnet_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	static const wchar_t* PlatformString2WChar(String^ str)
	{
		if (nullptr == str)
		{
			return NULL;
		}

		pin_ptr<const wchar_t> wch = PtrToStringChars(str);
		return wch;
	}

	class PlatformString2CharHelper
	{
	public:
		PlatformString2CharHelper(String^ str)
		{
			ch = PlatformString2Char(str);
		}
		~PlatformString2CharHelper()
		{
			if (ch)
			{
				free(ch);
			}
		}

		char* PlatformString2Char(String^ str)
		{
			if (nullptr == str)
			{
				return NULL;
			}

			pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((str->Length + 1) * 2);
			errno_t err = 0;
			char *ch = (char *)malloc(sizeInBytes);
			if (ch)
			{
				err = wcstombs_s(&convertedChars,
					ch, sizeInBytes,
					wch, sizeInBytes);
				if (0 == err)
				{
				}
			}

			return ch;
		}

		const char* c_str()
		{
			return ch;
		}

	private:
		PlatformString2CharHelper()
		{
			ch = NULL;
		}
		char* ch;
	};

	static String^ Char2PlatformString(const char* ch)
	{
		if (ch)
		{
			return gcnew String(ch);
		}
		return nullptr;
	}

	static String^ WChar2PlatformString(const wchar_t* wch)
	{
		if (wch)
		{
			return gcnew String(wch);
		}
		return nullptr;
	}

	static array<BYTE >^ NativeBuffer2PlatformBuffer(const char* buf, int len)
	{
		if (NULL == buf || len <= 0)
			return nullptr;

		array< Byte >^ byteArray = gcnew array< Byte >(len);
		if (nullptr == byteArray)
			return byteArray;

		Marshal::Copy((IntPtr)const_cast<char*>(buf), byteArray, 0, len);
		return byteArray;
	}

	class PlatformBuffer2NativeBufferHelper
	{
	public:
		PlatformBuffer2NativeBufferHelper(array<Byte>^ byte_array, int len)
		{
			m_pBuf = NULL;
			if (nullptr == byte_array || len <= 0)
				return;
			m_pBuf = new char[len];
			if (NULL == m_pBuf)
				return;

			for (int i = byte_array->GetLowerBound(0); i <= byte_array->GetUpperBound(0); i++) {
				char dc = *(Byte^)byte_array->GetValue(i);
				m_pBuf[i] = dc;
				if (i == (len-1))
					break;
			}
		}
		~PlatformBuffer2NativeBufferHelper()
		{
			if (m_pBuf)
				delete[] m_pBuf;
		}

		const char* Data()
		{
			return m_pBuf;
		}

	private:
		char* m_pBuf;
	};

	static void Convert_HWND(HWND hwnd, HWNDDotNet^% DotNetWnd)
	{
		if (nullptr == DotNetWnd)
			return;
		DotNetWnd->value = (UInt32)hwnd;
	}

	static array<unsigned int >^ Convert(ZOOM_SDK_NAMESPACE::IList<unsigned int >* plst)
	{
		if (NULL == plst || plst->GetCount() <= 0)
			return nullptr;

		int count = plst->GetCount();
		array< unsigned int >^ array_ = gcnew array< unsigned int >(count);
		if (nullptr == array_)
			return nullptr;

		for (int i = 0; i < count; i++)
		{
			unsigned int item = plst->GetItem(i);
			array_[i] = (unsigned int)item;
		}
		return array_;
	}

	static array<String^ >^ Convert(ZOOM_SDK_NAMESPACE::IList<const wchar_t* >* plst)
	{
		if (NULL == plst || plst->GetCount() <= 0)
			return nullptr;

		int count = plst->GetCount();
		array< String^ >^ array_ = gcnew array< String^ >(count);
		if (nullptr == array_)
			return nullptr;

		for (int i = 0; i < count; i++)
		{
			const wchar_t* item = plst->GetItem(i);
			array_[i] = WChar2PlatformString(item);
		}

		return array_;
	}

	static array<H323Device^ >^ Convert(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IH323Device* >* plst)
	{
		if (NULL == plst || plst->GetCount() <= 0)
			return nullptr;

		int count = plst->GetCount();
		array<H323Device^ >^ array_ = gcnew array<H323Device^ >(count);
		if (nullptr == array_)
			return nullptr;

		for (int i = 0; i < count; i++)
		{
			ZOOM_SDK_NAMESPACE::IH323Device* device_ = plst->GetItem(i);
			array_[i]->name = WChar2PlatformString(device_->GetName());
			array_[i]->e164num = WChar2PlatformString(device_->GetE164Num());
			array_[i]->ip = WChar2PlatformString(device_->GetIP());
			array_[i]->type = (H323DeviceType)device_->GetDeviceType();
		}

		return array_;
	}


	static DateTime time_t2DateTime(time_t date) 
	{
		double msec = static_cast<double>(date);
		return DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind::Utc).AddMilliseconds(msec);

	}
	static time_t DateTime2time_t(DateTime date) {
		TimeSpan diff = date.ToUniversalTime() - DateTime(1970, 1, 1);
		return static_cast<time_t>(diff.TotalMilliseconds);

	}

	private ref class IUserInfoDotNetWrapImpl sealed : public IUserInfoDotNetWrap
	{
	public:
		IUserInfoDotNetWrapImpl(ZOOM_SDK_NAMESPACE::IUserInfo* pInfo)
		{
			m_pInfo = pInfo;
		}

		virtual String^ GetUserName()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetUserName());
			return nullptr;
		}

		virtual String^ GetEmail()
		{
			if (m_pInfo)
				return WChar2PlatformString(m_pInfo->GetEmail());
			return nullptr;
		}

		virtual bool IsHost()
		{
			if (m_pInfo)
				return m_pInfo->IsHost();
			return false;
		}

		virtual unsigned int GetUserID()
		{
			if (m_pInfo)
				return m_pInfo->GetUserID();
			return 0;
		}

		virtual bool IsVideoOn()
		{
			if (m_pInfo)
				return m_pInfo->IsVideoOn();
			return false;
		}

		virtual bool IsAudioMuted()
		{
			if (m_pInfo)
				return m_pInfo->IsAudioMuted();
			return false;
		}

		virtual AudioType GetAudioJoinType()
		{
			if (m_pInfo)
				return (AudioType)m_pInfo->GetAudioJoinType();
			return AudioType::AUDIOTYPE_NONE;
		}

		virtual bool IsMySelf()
		{
			if (m_pInfo)
				return m_pInfo->IsMySelf();
			return false;
		}

		virtual bool IsInWaitingRoom()
		{
			if (m_pInfo)
				return m_pInfo->IsInWaitingRoom();
			return false;
		}

		virtual bool IsRaiseHand()
		{
			if (m_pInfo)
				return m_pInfo->IsRaiseHand();
			return false;
		}

		virtual UserRole GetUserRole()
		{
			if (m_pInfo)
				return (UserRole)m_pInfo->GetUserRole();
			return UserRole::USERROLE_NONE;
		}

		virtual bool IsPurePhoneUser()
		{
			if (m_pInfo)
				return m_pInfo->IsPurePhoneUser();
			return false;
		}

	private:
		ZOOM_SDK_NAMESPACE::IUserInfo* m_pInfo;
	};
}