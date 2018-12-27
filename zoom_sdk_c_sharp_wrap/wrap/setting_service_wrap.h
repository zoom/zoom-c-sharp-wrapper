#pragma once
#include "common_include.h"
#include "video_setting_context_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ISettingService* InitISettingServiceFunc();
void UninitISettingServiceFunc(ZOOM_SDK_NAMESPACE::ISettingService* obj);

BEGIN_CLASS_DEFINE(ISettingService)
STAITC_CLASS(ISettingService)
INIT_UNINIT(ISettingService)

//virtual SDKError ShowSettingDlg(ShowSettingDlgParam& param) = 0;
DEFINE_FUNC_1(ShowSettingDlg, SDKError, ShowSettingDlgParam&, param)
//virtual SDKError HideSettingDlg() = 0;
DEFINE_FUNC_0(HideSettingDlg, SDKError)
//virtual IGeneralSettingContext* GetGeneralSettings() = 0;
DEFINE_FUNC_0(GetGeneralSettings, IGeneralSettingContext*)
//virtual IAudioSettingContext* GetAudioSettings() = 0;
DEFINE_FUNC_0(GetAudioSettings, IAudioSettingContext*)
//virtual IRecordingSettingContext* GetRecordingSettings() = 0;
DEFINE_FUNC_0(GetRecordingSettings, IRecordingSettingContext*)
//virtual IStatisticSettingContext* GetStatisticSettings() = 0;
DEFINE_FUNC_0(GetStatisticSettings, IStatisticSettingContext*)

DEFINE_FUNC_AND_MEMBER(GetVideoSettings, IVideoSettingContextWrap)

END_CLASS_DEFINE(ISettingService)
END_ZOOM_SDK_NAMESPACE