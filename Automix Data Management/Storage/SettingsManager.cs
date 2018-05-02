// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System;
using System.IO;
using System.Xml;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Storage
{
    /// <summary>
    ///     Allow to set or get preferences/settings of the user
    /// </summary>
    public class SettingsManager
    {
        public enum SettingTypes
        {
            [SettingText("tempDir")] TempDir = 0,
            [SettingText("transitionDuration")] TransitionDuration = 1,
            [SettingText("mixDuration")] MixDuration = 2,
            [SettingText("bpmP")] BpmPriority = 3,
            [SettingText("keyTonalityP")] KeyTonalityPriority = 4,
            [SettingText("keyNumberP")] KeyNumberPriority = 5,
            [SettingText("danceabilityP")] DanceabilityPriority = 6,
            [SettingText("MP3Quality")] Mp3Quality = 7
        }

        private const string ConfigFileName = "\\config.xml";

        private static readonly string AppDataDirectory =
            Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware";

        private readonly XmlDocument _configFile;

        public SettingsManager()
        {
            _configFile = OpenOrCreateConfigFile();
        }

        public void SetSetting(SettingTypes settingType, string param)
        {
            if (settingType == SettingTypes.TempDir)
            {
                if (!Directory.Exists(param))
                {
                    Directory.CreateDirectory(param);
                }
                MakeSettlement(settingType.ToText(), param + "\\AutomixSoftware");
            }

            else if (settingType == SettingTypes.TransitionDuration || settingType == SettingTypes.MixDuration ||
                     settingType == SettingTypes.BpmPriority || settingType == SettingTypes.KeyNumberPriority ||
                     settingType == SettingTypes.KeyTonalityPriority ||
                     settingType == SettingTypes.DanceabilityPriority ||
                     settingType == SettingTypes.Mp3Quality)
            {
                MakeSettlement(settingType.ToText(), param);
            }
        }

        public string GetSetting(SettingTypes settingType)
        {
            var node = _configFile.DocumentElement?.SelectSingleNode(settingType.ToText());
            return node?.InnerText;
        }

        private void MakeSettlement(string section, string param)
        {
            var node = _configFile.DocumentElement?.SelectSingleNode(section);

            if (node != null)
            {
                node.InnerText = param;
            }

            else
            {
                XmlNode root = _configFile.DocumentElement;
                var elem = _configFile.CreateElement(section);
                elem.InnerText = param;
                root?.AppendChild(elem);
            }

            _configFile.Save(AppDataDirectory + ConfigFileName);
        }

        private static XmlDocument OpenOrCreateConfigFile()
        {
            if (!Directory.Exists(AppDataDirectory))
            {
                Directory.CreateDirectory(AppDataDirectory);
            }
            if (!File.Exists(AppDataDirectory + ConfigFileName))
            {
                CreateDefaultConfigFile();
            }

            var file = new XmlDocument();
            try
            {
                file.Load(AppDataDirectory + ConfigFileName);
            }
            catch (XmlException)
            {
                CreateDefaultConfigFile();
                //log this
            }

            file.Load(AppDataDirectory + ConfigFileName);
            return file;
        }

        private static void CreateDefaultConfigFile()
        {
            var settings = new XmlWriterSettings
            {
                Indent = true
            };

            var defaultParameters = new Settings();
            var writer = XmlWriter.Create(AppDataDirectory + ConfigFileName, settings);

            writer.WriteStartElement("configuration");
            writer.WriteElementString(SettingTypes.TempDir.ToText(), defaultParameters.TempDir);
            writer.WriteElementString(SettingTypes.MixDuration.ToText(), defaultParameters.MixDuration);
            writer.WriteElementString(SettingTypes.TransitionDuration.ToText(), defaultParameters.TransitionDuration);
            writer.WriteElementString(SettingTypes.BpmPriority.ToText(), defaultParameters.BpmPriority);
            writer.WriteElementString(SettingTypes.KeyTonalityPriority.ToText(), defaultParameters.KeyTonalityPriority);
            writer.WriteElementString(SettingTypes.KeyNumberPriority.ToText(), defaultParameters.KeyNumberPriority);
            writer.WriteElementString(SettingTypes.DanceabilityPriority.ToText(), defaultParameters.DanceabilityPriority);
            writer.WriteElementString(SettingTypes.Mp3Quality.ToText(), defaultParameters.Mp3Quality);
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }

        public Settings LoadParametersFromFile()
        {
            var param = new Settings();

            var document = _configFile.DocumentElement;
            if (document == null)
                return param;

            var node = document.SelectSingleNode(SettingTypes.TempDir.ToText());
            if (node != null)
            {
                param.TempDir = node.InnerText;

            }

            node = document.SelectSingleNode(SettingTypes.TransitionDuration.ToText());
            if (node != null)
            {
                param.TransitionDuration = node.InnerText;
            }

            node = document.SelectSingleNode(SettingTypes.MixDuration.ToText());
            if (node != null)
            {
                param.MixDuration = node.InnerText;
            }

            node = document.SelectSingleNode(SettingTypes.BpmPriority.ToText());
            if (node != null)
            {
                param.BpmPriority = node.InnerText;
            }

            node = document.SelectSingleNode(SettingTypes.KeyNumberPriority.ToText());
            if (node != null)
            {
                param.KeyNumberPriority = node.InnerText;
            }

            node = document.SelectSingleNode(SettingTypes.KeyTonalityPriority.ToText());
            if (node != null)
            {
                param.KeyTonalityPriority = node.InnerText;
            }

            node = document.SelectSingleNode(SettingTypes.DanceabilityPriority.ToText());
            if (node != null)
            {
                param.DanceabilityPriority = node.InnerText;
            }

            node = document.SelectSingleNode(SettingTypes.Mp3Quality.ToText());
            if (node != null)
            {
                param.Mp3Quality = node.InnerText;
            }

            return param;
        }

        public void SaveParametersInFile(Settings param)
        {
            MakeSettlement(SettingTypes.TempDir.ToText(), param.TempDir);
            MakeSettlement(SettingTypes.MixDuration.ToText(), param.MixDuration);
            MakeSettlement(SettingTypes.TransitionDuration.ToText(), param.TransitionDuration);
            MakeSettlement(SettingTypes.BpmPriority.ToText(), param.BpmPriority);
            MakeSettlement(SettingTypes.KeyTonalityPriority.ToText(), param.KeyTonalityPriority);
            MakeSettlement(SettingTypes.KeyNumberPriority.ToText(), param.KeyNumberPriority);
            MakeSettlement(SettingTypes.DanceabilityPriority.ToText(), param.DanceabilityPriority);
            MakeSettlement(SettingTypes.Mp3Quality.ToText(), param.Mp3Quality);
        }

        public class SettingText : Attribute
        {
            public SettingText(string text)
            {
                Text = text;
            }

            public string Text { get; }
        }
    }
}