using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using System;
using System.Linq;
using ZOOM_SDK_DOTNET_WRAP;

namespace zoomapp
{
    public class Startup
    {
        public IConfiguration Configuration { get; }

        public Startup(
            IWebHostEnvironment env
            )
        {
            var builder = new ConfigurationBuilder()
                .SetBasePath(env.ContentRootPath)
                .AddYamlFile("./_config/config.yaml", optional: false)
                .AddEnvironmentVariables();
            Configuration = builder.Build();
            var appConfig = Configuration.Get<AppConfig>();
            StartZoom(appConfig.Key, appConfig.Secret);
        }

        // This method gets called by the runtime. Use this method to add services to the container.
        // For more information on how to configure your application, visit https://go.microsoft.com/fwlink/?LinkID=398940
        public void ConfigureServices(IServiceCollection services)
        {
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(
            IApplicationBuilder app, 
            IWebHostEnvironment env
            )
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }

            app.UseRouting();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapGet("/join/{meetingId}", async context =>
                {
                    var meetingId = ulong.Parse((string)context.Request.RouteValues["meetingId"]);
                    JoinMeeting(meetingId);
                    await context.Response.WriteAsync("Meeting joined");
                });
            });
        }

        private void StartZoom(
            string zoomKey,
            string zoomSecret
            )
        {

            var param = new InitParam {
                web_domain = "https://zoom.us",
                enable_log = true,
                sdk_dll_path = "./"
            };
            var err = CZoomSDKeDotNetWrap.Instance.Initialize(param);
            Console.WriteLine($"Initialized with {err}");

            ZOOM_SDK_DOTNET_WRAP.CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().Add_CB_onAuthenticationReturn(onAuthenticationReturn);
            var authParams = new AuthParam {
                appKey = zoomKey,
                appSecret = zoomSecret
            };
            var authError = CZoomSDKeDotNetWrap.Instance.GetAuthServiceWrap().SDKAuth(authParams);
            Console.WriteLine($"SDK auth'd with {authError}");
        }

        public void onAuthenticationReturn(AuthResult ret)
        {
            if (ZOOM_SDK_DOTNET_WRAP.AuthResult.AUTHRET_SUCCESS == ret)
            {
                Console.WriteLine($"Auth returned {ret}");
            }
            else//error handle.todo
            {
            }
        }

        private void JoinMeeting(ulong meetingId)
        {
            var joinParam = new JoinParam {
                userType = SDKUserType.SDK_UT_WITHOUT_LOGIN,
                withoutloginJoin = new JoinParam4WithoutLogin {
                    meetingNumber = meetingId,
                    userName = "Rev.ai Zoom SDK"
                }
            };

            // Settings to disable video and audio on join and minimize screen
            CZoomSDKeDotNetWrap.Instance.GetSettingServiceWrap()
                .GetVideoSettings().EnableAutoTurnOffVideoWhenJoinMeeting(true);
            CZoomSDKeDotNetWrap.Instance.GetSettingServiceWrap()
                .GetAudioSettings().EnableAutoJoinAudio(true);
            var joinError = CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().Join(joinParam);

            if (SDKError.SDKERR_SUCCESS == joinError)
            {
                var res = CZoomSDKeDotNetWrap.Instance.GetAudioRawDataChannelWrap().Start(
                    RawDataMemoryMode.RawDataMemoryMode_Stack, 
                    new RevAudioReceiver()
                );
                Console.WriteLine($"Raw data channel start with {res}");
                CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingAudioController()
                    .Add_CB_onUserActiveAudioChange((list) =>
                    {
                        if (list == null || list.Length == 0)
                        {
                            return;
                        }
                        var users = list.Select(userId => CZoomSDKeDotNetWrap.Instance.GetMeetingServiceWrap().GetMeetingParticipantsController().GetUserByUserID(userId));

                        var usernames = users.Select(u => u.GetUserNameW());
                        Console.WriteLine($"Active speakers: {string.Join(" ", usernames)}");
                    });
            }
            else
            {
                Console.WriteLine($"Join failed with {joinError}");
            }
        }
    }
}
