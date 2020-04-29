# Zoom Windows SDK C# Wrapper <span align="center"><img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Community-Project.png" width="200px" max-height="100px" style="margin:auto;"/></span>

**Note: Zoom does not actively enhance the interfaces in the C# wrapper. This wrapper is provided as a reference and will not be actively supported by Zoom.**

<div align="center">
<img src="https://s3.amazonaws.com/user-content.stoplight.io/8987/1541013063688" width="400px" max-height="400px" style="margin:auto;"/>
</div>

## :rotating_light: Announcement :rotating_light:
The Client SDK hereby introduced the **AES 256-bit GCM encryption** as addressed in our [90-Day Security Plan](https://blog.zoom.us/wordpress/2020/04/22/zoom-hits-milestone-on-90-day-security-plan-releases-zoom-5-0/) to **our SDK version 4.6.21666.0428**. Please note that: This AES 256-bit GCM encryption is **backward INCOMPATIBLE, which means the older version of SDK will NOT be able to join a meeting with GCM encryption enabled,** and as mentioned in the [90-Day Security Plan](https://blog.zoom.us/wordpress/2020/04/22/zoom-hits-milestone-on-90-day-security-plan-releases-zoom-5-0/), **the system-wide account enablement of AES 256-bit GCM encryption will take place on May 30, 2020**. Please plan to upgrade your SDK accordingly, and we will soon take away the older version of SDK that are not compatible with GCM encryption. Thank you!

## Latest SDK Notifications
1. Our brand new [Zoom Developer Community Forum](https://devforum.zoom.us/) is now online!!! Check it out! We are here to help! :D

## Full Documentation && Community Support
You can find the full Zoom Windows SDK C# wrapper documentation and the community support forum here:
<div align="center">
   <a target="_blank" href="https://marketplace.zoom.us/docs/sdk/native-sdks/windows/c-sharp-wrapper" style="text-decoration:none">
   <img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Doc-button.png" width="350px" max-height="350px" style="margin:1vh 1vw;"/>
   </a>
   <a target="_blank" href="https://devforum.zoom.us/c/desktop-sdk" style="text-decoration:none">
   <img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Forum-button.png" width="350px" max-height="350px" style="margin:1vh 1vw;"/>
   </a>
</div>

## Disclaimer

**Please be aware that all hard-coded variables and constants shown in the documentation and in the demo, such as Zoom Token, Zoom Access, Token, etc., are ONLY FOR DEMO AND TESTING PURPOSES. We STRONGLY DISCOURAGE the way of HARDCODING any Zoom Credentials (username, password, API Keys & secrets, SDK keys & secrets, etc.) or any Personal Identifiable Information (PII) inside your application. WE DON’T MAKE ANY COMMITMENTS ABOUT ANY LOSS CAUSED BY HARD-CODING CREDENTIALS OR SENSITIVE INFORMATION INSIDE YOUR APP WHEN DEVELOPING WITH OUR SDK**.

## Getting Started

The following instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
* For detailed instructions, please refer to our documentation website: [https://marketplace.zoom.us/docs/sdk/native-sdks/windows/c-sharp-wrapper](https://marketplace.zoom.us/docs/sdk/native-sdks/windows/c-sharp-wrapper);
* If you need support or assistance, please visit our [Zoom Developer Community Forum](https://devforum.zoom.us/);

### Prerequisites

Before you try out our SDK, you would need the following to get started:

* **A Zoom Account**: If you do not have one, you can sign up at [https://zoom.us/signup](https://zoom.us/signup).
  * Once you have your Zoom Account, sign up for a 60-days free trial at [https://marketplace.zoom.us/](https://marketplace.zoom.us/)
* **A device with Windows OS**:
  * OS: Windows XP or later. Currently Windows 10 UWP is not supported.
  * CPU: Zoom C# wrapper currently only supports x86


### Installing

Clone or download a copy of our SDK files from GitHub. After you unzipped the file, you should have the following folders:

```
.
├── bin
├── zoom_sdk_c_sharp_wrap
└── zoom_sdk_demo
```
Please follow the below steps to get started:

1.The wrap `Dll` locate at `zoom_sdk_csharp_wrap_github\bin\zoom_sdk_dotnet_wrap.dll`.

2.Run the demo project,

a>`zoom_sdk_csharp_wrap_github\zoom_sdk_demo\zoom_sdk_demo.csproj`

b>change vs project's solution configuration to "release"

c>change vs project's solution platform to "x86"

d>build and run.


## Documentation

Please visit [https://marketplace.zoom.us/docs/sdk/native-sdks/windows/c-sharp-wrapper](https://marketplace.zoom.us/docs/sdk/native-sdks/windows/c-sharp-wrapper)] for details of each features and functions.

## Versioning

For the versions available, see the [tags on this repository](https://github.com/zoom/zoom-sdk-windows/tags).

## Change log

Please refer to our [CHANGELOG](https://github.com/zoom/zoom-c-sharp-wrapper/blob/master/CHANGELOG.md) for all changes.

## Frequently Asked Questions (FAQ)

* Please visit our [Zoom Developer Community Forum](https://devforum.zoom.us/) for further assistance.

## Support

For any issues regarding our SDK, please visit our new Community Support Forum at https://devforum.zoom.us/.

## License

Use of this software is subject to important terms and conditions as set forth in the License file

Please refer to [LICENSE.md](https://github.com/zoom/zoom-c-sharp-wrapper/blob/master/LICENSE) file for details

## Contributiors

This project is a Zoom Community Project that is initialized by Zoom and welcoming the community developers to contribute.

Please see [CONTRIBUTORS](https://github.com/zoom/zoom-c-sharp-wrapper/blob/master/CONTRIBUTORS.md) for the project contributors.

## Acknowledgments

* :star: If you like our SDK, please give us a "Star". Your support is what keeps us moving forward and delivering happiness to you! Thanks a million! :smiley:
* If you need any support or assistance, we are here to help you: [Zoom Developer Community Forum](https://devforum.zoom.us/);

---
Copyright ©2020 Zoom Video Communications, Inc. All rights reserved.
