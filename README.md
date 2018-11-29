# Zoom-Windows-Csharp-wrapper
C# wrapper for Zoom Windows SDK

Note: Zoom does not actively enhance the interfaces in the c# wrapper. This wrapper is provided as a reference and will not be actively supported by Zoom. We have published the source code for this wrapper and are relying on our developer community to enhance it as needed. Please make sure that you commit the code changes back to git.

Please refer to https://developer.zoom.us/docs/windows/c-wrapper-introduction/

1.the wrap Dll locate at zoom_sdk_csharp_wrap_github\bin\zoom_sdk_dotnet_wrap.dll, now we only support x86.

2.download window sdk

https://github.com/zoom/zoom-sdk-windows

3.copy file

copy "zoom-sdk-windows\bin" to "zoom_sdk_csharp_wrap_github\bin"

4. run demo project,

a>"zoom_sdk_csharp_wrap_github\zoom_sdk_demo\zoom_sdk_demo.csproj"

b>change vs project's solution configuration to "release"

c>change vs project's solution platform to "x86"

d.build and run.

## Support

For any issues regarding our SDK, please visit our new Community Support Forum at https://devforum.zoom.us/.
