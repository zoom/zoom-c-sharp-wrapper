using System;
using Newtonsoft.Json;

namespace zoom_sdk_demo
{
    /// <summary>
    /// Subclass of JsonConverter that serializes/deserializes timespans (to/from seconds). Allows to
    /// optionally specify precision of resultant seconds.
    /// </summary>
    public class TimeSpanConverter : JsonConverter
    {
        public override void WriteJson(
            JsonWriter writer,
            object value,
            JsonSerializer serializer
            )
        {
            var ts = (TimeSpan)value;
            var tsVal = ts.TotalSeconds;

            tsVal = _decimalPlaces.Map(n => Math.Round(tsVal, n)) ?? tsVal;

            serializer.Serialize(writer, tsVal);
        }

        public override object ReadJson(
            JsonReader reader,
            Type objectType,
            object existingValue,
            JsonSerializer serializer
            )
        {
            if (reader.TokenType == JsonToken.Null)
                return null;

            var value = serializer.Deserialize<double>(reader);
            return TimeSpan.FromSeconds(value);
        }

        public override bool CanConvert(Type objectType)
        {
            return objectType == typeof(TimeSpan) || objectType == typeof(TimeSpan?);
        }

        public TimeSpanConverter()
        {
        }

        /// <summary>
        /// Creates an instance that rounds the seconds it produces to the specified <paramref name="decimalPlaces"/>.
        /// </summary>
        public TimeSpanConverter(
            int decimalPlaces
            )
        {
            _decimalPlaces = decimalPlaces;
        }

        private readonly int? _decimalPlaces;
    }
}