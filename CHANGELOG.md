# CHANGELOG

## Obtaining SDK packages from Marketplace

We are pleased to inform you that starting from v5.4.54524.1229, the Zoom SDK packages are moving to the Zoom App Marketplace. The packages are now available in the same location as your SDK Key & Secret. This change aims to provide you with a unified and seamless experience so that you can access the required SDK resources in one place. 

If you have not used Zoom SDK before, please follow the steps in https://marketplace.zoom.us/docs/guides/build/sdk-app to create an SDK app on the Marketplace.

If you already have an SDK app created, login to the **[Zoom App Marketplace](https://marketplace.zoom.us/)** using your developer account, click the **Manage** button on the top-right corner and locate your SDK app.
<img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/mkt-01.png" style="margin:1vh 1vw;"/>

Click on your SDK app, you can find the desired SDK packages from the **Download** tab
<img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/mkt-02.png" style="margin:1vh 1vw;"/>

## 2020-11-17
* Please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2020-10-09 
* Please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2020-06-30

* Please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2020-04-28

* Please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2020-04-04

* Add new interfaces for Custom UI
* Please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.


## 2020-02-10

* No interface changes for C# wrapper, please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

## 2019-12-16

* No interface changes for C# wrapper, please refer to [https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md](https://github.com/zoom/zoom-sdk-windows/blob/master/CHANGELOG.md) for changes in Windows SDK.

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
