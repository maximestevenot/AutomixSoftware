using System.IO;
using static Automix_Data_Management.Utils;
using static Automix_Data_Management.SettingsAccessor;

namespace Automix_Data_Management_Tests
{
    internal static class TestConstant
    {
        public static readonly string TempDirPath = GetSetting(Settings.tempDir);
        public static readonly string TestCheckSum = "0001";
        public static readonly string TestFilePath = "test.mp3";
        public static readonly string DataBasePath = "automix_software_collection_test.db";
    }
}
