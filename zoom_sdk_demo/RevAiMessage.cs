using Newtonsoft.Json;
using System;

namespace zoom_sdk_demo
{
    public class RevAiMessage
    {
        [JsonProperty("type")]
        public string Type { get; set; }
        /// <summary>
        /// Timestamp at which message begins
        /// </summary>
        [JsonProperty("ts")]
        [JsonConverter(typeof(TimeSpanConverter), new object[] { 3 })]
        public TimeSpan? Start { get; set; }
        /// <summary>
        /// Timestamp at which message ends
        /// </summary>
        [JsonProperty("end_ts")]
        [JsonConverter(typeof(TimeSpanConverter), new object[] { 3 })]
        public TimeSpan? End { get; set; }
        [JsonProperty("elements")]
        public Element[] Elements { get; set; }
        public class Element
        {
            /// <summary>
            /// Element type
            /// </summary>
            [JsonProperty("type")]
            public string Type { get; set; }
            /// <summary>
            /// Element value
            /// </summary>
            [JsonProperty("value")]
            public string Value { get; set; }
            /// <summary>
            /// Timestamp at which element begins
            /// </summary>
            [JsonProperty("ts")]
            [JsonConverter(typeof(TimeSpanConverter), new object[] { 3 })]
            public TimeSpan? Start { get; set; }
            /// <summary>
            /// Timestamp at which element ends
            /// </summary>
            [JsonProperty("end_ts")]
            [JsonConverter(typeof(TimeSpanConverter), new object[] { 3 })]
            public TimeSpan? End { get; set; }
            /// <summary>
            /// Revspeech confidence in element correctness
            /// </summary>
            [JsonProperty("confidence")]
            public double? Confidence { get; set; }
        }
    }
}