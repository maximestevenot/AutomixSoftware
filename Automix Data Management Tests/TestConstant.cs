using System.IO;

namespace Automix_Data_Management_Tests
{
    internal static class TestConstant
    {
        // TODO: directory choosen by the user
        public static readonly string TempDirPath = Path.GetTempPath() + "AutomixSoftware";
        public static readonly string TestCheckSum = "0001";
        public static readonly string TestFilePath = "test.mp3";
        public static readonly string DataBasePath = "automix_software_collection_test.db";
    }
}
