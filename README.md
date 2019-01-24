# Zoom Windows SDK C# Wrapper

**Note: Zoom does not actively enhance the interfaces in the C# wrapper. This wrapper is provided as a reference and will not be actively supported by Zoom.**

> Our brand new [Zoom Developer Community Forum](https://devforum.zoom.us/) is now online!!! Check it out! We are here to help! :D

## Disclaimer

**Please be aware that all hard-coded variables and constants shown in the documentation and in the demo, such as Zoom Token, Zoom Access, Token, etc., are ONLY FOR DEMO AND TESTING PURPOSES. We STRONGLY DISCOURAGE the way of HARDCODING any Zoom Credentials (username, password, API Keys & secrets, SDK keys & secrets, etc.) or any Personal Identifiable Information (PII) inside your application. WE DON’T MAKE ANY COMMITMENTS ABOUT ANY LOSS CAUSED BY HARD-CODING CREDENTIALS OR SENSITIVE INFORMATION INSIDE YOUR APP WHEN DEVELOPING WITH OUR SDK**.

## Getting Started

The following instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
* For detailed instructions, please refer to our documentation website: [https://marketplace.zoom.us/docs/sdk/windows/c-wrapper](https://marketplace.zoom.us/docs/sdk/windows/c-wrapper);
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

2.Download the Windows SDK

[https://github.com/zoom/zoom-sdk-windows](https://github.com/zoom/zoom-sdk-windows)

3.Copy files

Copy `zoom-sdk-windows\bin` to `zoom_sdk_csharp_wrap_github\bin`

4. run demo project,

a>`zoom_sdk_csharp_wrap_github\zoom_sdk_demo\zoom_sdk_demo.csproj`

b>change vs project's solution configuration to "release"

c>change vs project's solution platform to "x86"

d>build and run.


## Documentation

Please visit [[https://marketplace.zoom.us/docs/sdk/windows/c-wrapper](https://marketplace.zoom.us/docs/sdk/windows/c-wrapper)] for details of each features and functions.

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

Please refer to [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* :star: If you like our SDK, please give us a "Star". Your support is what keeps us moving forward and delivering happiness to you! Thanks a million! :smiley:
* If you need any support or assistance, we are here to help you: [Zoom Developer Community Forum](https://devforum.zoom.us/);

---
Copyright ©2019 Zoom Video Communications, Inc. All rights reserved.
