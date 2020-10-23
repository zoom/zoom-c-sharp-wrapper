# Zoom Windows SDK C# Wrapper <span align="center"><img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Community-Project.png" width="200px" max-height="100px" style="margin:auto;"/></span>

**Note: Zoom does not actively enhance the interfaces in the C# wrapper. This wrapper is provided as a reference and will not be actively supported by Zoom.**

<div align="center">
<img src="https://s3.amazonaws.com/user-content.stoplight.io/8987/1541013063688" width="400px" max-height="400px" style="margin:auto;"/>
</div>

## Table of Contents 
- [Latest SDK News](#latest-sdk-news)   
- [Full Documentation && Community Support](#full-documentation-community-support)   
- [Disclaimer](#disclaimer)   
- [Getting Started](#getting-started)   
  - [Prerequisites](#prerequisites)   
  - [Installing](#installing)   
- [Documentation](#documentation)   
- [Versioning](#versioning)   
- [Change log](#change-log)   
- [Frequently Asked Questions (FAQ)](#frequently-asked-questions-faq)   
- [Support](#support)   
- [License](#license)   
- [Contributiors](#contributiors)   
- [Acknowledgments](#acknowledgments)   


## Latest SDK News
1.  Starting from 5.2.41727.0928, the Windows SDK requires building with Visual Studio 2019.
2. Starting from Client SDK 5.0, if you are using tokens to start a meeting, you will only need to retrieve ZAK from Zoom API. The user token has been deprecated. 
3. To follow with Zoom client's recent changes, Zoom SDK has temporary remove the "Unmute All" interface in Client SDK 5.0.
4. To align with Zoom’s [recent announcement](https://blog.zoom.us/wordpress/2020/04/22/zoom-hits-milestone-on-90-day-security-plan-releases-zoom-5-0/) pertaining to our security initiative, Zoom Client SDKs have added **AES 256-bit GCM encryption** support, which provides more protection for meeting data and greater resistance to tampering. **The system-wide account enablement of AES 256-bit GCM encryption will take place on June 01, 2020.** You are **strongly recommended** to start the required upgrade to this latest version 4.6.21666.0428 at your earliest convenience. Please note that any Client SDK versions below 4.6.21666.0428 will **no longer be operational** from June 01.

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
  * Visual Studio 2019


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

### Initializing SDK with JWT token
When initializing the SDK, you will need to compose a JWT token using your SDK key & secret.

* How to compose JWT token for SDK initialization

You may generate your JWT token using the online tool https://jwt.io/. **It is highly recommended to generate your JWT token in your backend server.**

JWT is generated with three core parts: Header, Payload, and Signature. When combined, these parts are separated by a period to form a token: aaaaa.bbbbb.cccc.

Please follow this template to compose your payload for SDK initialization:

** Header
```
{
  "alg": "HS256",
  "typ": "JWT"
}
```
** Payload
```
{
         "appKey": "string",     // Your SDK key
         "iat": long,   // access token issue timestamp (unit: second)
         "exp": long,  // access token expire timestamp, MAX: iat + 2 days (unit: second)
         "tokenExp": long // token expire timestamp, MIN:iat + 30 minutes (unit: second)
}
```
**The minimum value of `tokenExp` should be at least 30 minutes, otherwise, SDK will reject the authentication request.**
** Signature
```
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  "Your SDK secret here"
)
```
You do not need to secret base64 encoded your signature. Once the JWT token is generated, please do not reveal it or publish it. **It is highly recommended to handle your SDK key and secret and generate JWT in a backend server to be consumed by your application. Do not generate JWT in a production application.**


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
