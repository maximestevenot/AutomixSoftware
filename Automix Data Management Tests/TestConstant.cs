// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using Automix_Data_Management.Storage;

namespace Automix_Data_Management_Tests
{
    internal static class TestConstant
    {
        public static readonly string TempDirPath = new SettingsManager().GetSetting(SettingsManager.SettingTypes.TempDir);
        public static readonly string TestCheckSum = "0001";
        public static readonly string TestFilePath = "test.mp3";
        public static readonly string DataBasePath = "automix_software_collection_test.db";
    }
}
