using Newtonsoft.Json;

namespace zoom_sdk_demo
{
    public class ConnectedMessage
    {
        [JsonProperty("type")]
        public string Type { get; set; }

        [JsonProperty("id")]
        public string Id { get; set; }
    }
}
