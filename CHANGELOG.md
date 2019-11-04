# CHANGELOG

## 2019-11-04

* No interface changes for C# wrapper, please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2019-09-04

* No interface changes for C# wrapper, please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2019-07-15

**Added**

* Wrapped all native Windows SDK interfaces into C++ wrapper except the following testing related interfaces:
  * `ITestAudioDeviceHelper`
  * `ITestAudioDeviceHelperEvent`
  * `ITestVideoDeviceHelper`
  * `ITestVideoDeviceHelperEvent`
* Wrapped the following custom UI related interfaces into C# wrapper
  * `CCustomizedUIMgrDotNetWrap`
  * `CCustomizedVideoContainerDotNetWrap`
  * `CCustomizedShareRenderDotNetWrap`
* Added some new interfaces into the C# wrapper
  * `CCustomizedResourceHelperDotNetWrap`
  * `CMeetingLiveStreamControllerDotNetWrap`
  * `CPreMeetingServiceDotNetWrap`
  * `CScheduleMeetingItemDotNetWrap`
  * `CVideoSettingContextDotNetWrap`

**Changed & Fixed**

* Modify the implementation of the following interfaces in C# wrapper

## 2019-03-25

* No interface changes for C# wrapper, please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2019-01-23

* No interface changes for C# wrapper, please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2018-10-29

No interface changes

## 2018-09-11

No interface changes

## 2018-08-20

No interface changes

## 2018-07-26

The start meeting logic for API users has changed. Please read below before upgrading to this version.

### Added

1. Add new start meeting methods for API user
