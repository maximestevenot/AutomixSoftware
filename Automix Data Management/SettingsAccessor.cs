// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.IO;
using System.Xml;
using Automix_Data_Management.Model;
using System.Reflection;

namespace Automix_Data_Management
{
    /// <summary>
    /// Allow to set or get preferences/settings of the user
    /// </summary>
    public abstract class SettingsAccessor
    {
        private static string _dir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware";
        private static XmlDocument configFile;

        public class SettingText : Attribute
        {
            public string Text { get; private set; }

            public SettingText(string text)
            {
                this.Text = text;
            }
        }

        public enum Settings : int
        {
            [SettingText("tempDir")]
            tempDir = 0,
            [SettingText("transitionDuration")]
            transitionDuration = 1,
            [SettingText("mixDuration")]
            mixDuration = 2,
            [SettingText("bpmP")]
            bpmPriority = 3,
            [SettingText("keyTonalityP")]
            keyTonalityPriority = 4,
            [SettingText("keyNumberP")]
            keyNumberPriority = 5,
            [SettingText("danceabilityP")]
            danceabilityPriority = 6,
            [SettingText("MP3Quality")]
            MP3Quality = 7
        }

        public static void SetSetting(Settings setting, String param)
        {
            configFile = OpenOrCreateConfigFile();

            switch (setting)
            {
                case Settings.tempDir:
                    if (!Directory.Exists(param))
                    {
                        Directory.CreateDirectory(param);
                    }
                    MakeSettlement(setting.ToText(), param + "\\AutomixSoftware");
                    break;
                case Settings.transitionDuration:
                case Settings.mixDuration:
                case Settings.bpmPriority:
                case Settings.keyNumberPriority:
                case Settings.keyTonalityPriority:
                case Settings.danceabilityPriority:
                case Settings.MP3Quality:
                    MakeSettlement(setting.ToText(), param);
                    break;
            }
        }

        public static String GetSetting(Settings setting)
        {
            configFile = OpenOrCreateConfigFile();
            XmlNode node;
            node = configFile.DocumentElement.SelectSingleNode(setting.ToText());
            return node.InnerText;
        }

        private static void MakeSettlement(String section, String param)
        {
            XmlNode node = configFile.DocumentElement.SelectSingleNode(section);
            if (node != null)
            {
                node.InnerText = param;
            }
            else
            {
                XmlNode root = configFile.DocumentElement;
                XmlElement elem = configFile.CreateElement(section);
                elem.InnerText = param;
                root.AppendChild(elem);
            }

            configFile.Save(_dir + "\\config.xml");
        }

        private static XmlDocument OpenOrCreateConfigFile()
        {
            if (!Directory.Exists(_dir))
            {
                Directory.CreateDirectory(_dir);
            }

            if (!File.Exists(_dir + "\\config.xml"))
            {
                CreateDefaultConfigFile();
            }

            XmlDocument file = new XmlDocument();
            file.Load(_dir + "\\config.xml");

            return file;
        }

        private static void CreateDefaultConfigFile()
        {
            XmlWriterSettings settings = new XmlWriterSettings
            {
                Indent = true
            };

            XmlWriter writer = XmlWriter.Create(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware\\config.xml", settings);
            writer.WriteStartElement("configuration");
            writer.WriteElementString("tempDir", Path.GetTempPath()+"//AutomixSoftware");
            writer.WriteElementString("transitionDuration", "10");
            writer.WriteElementString("mixDuration", "30");
            writer.WriteElementString("bpmP", "10");
            writer.WriteElementString("keyNumberP", "10");
            writer.WriteElementString("keyTonalityP", "10");
            writer.WriteElementString("danceabilityP", "10");
            writer.WriteElementString("MP3Quality", "320");
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }

        public static Parameters LoadParametersFromFile()
        {
            var param = new Parameters();

            configFile = OpenOrCreateConfigFile();
            XmlNode node;

            node = configFile.DocumentElement.SelectSingleNode("tempDir");
            param.TempDir = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("transitionDuration");
            param.TransitionDuration = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("mixDuration");
            param.MixDuration = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("bpmP");
            param.BpmPriority = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("keyNumberP");
            param.KeyNumberPriority = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("keyTonalityP");
            param.KeyTonalityPriority = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("danceabilityP");
            param.DanceabilityPriority = node.InnerText;
            node = configFile.DocumentElement.SelectSingleNode("MP3Quality");
            param.MP3Quality = node.InnerText;

            return param;
        }

        public static void SaveParametersInFile(Parameters param)
        {
            configFile = OpenOrCreateConfigFile();

            MakeSettlement(Settings.tempDir.ToText(), param.TempDir);
            MakeSettlement(Settings.mixDuration.ToText(), param.MixDuration);
            MakeSettlement(Settings.transitionDuration.ToText(), param.TransitionDuration);
            MakeSettlement(Settings.bpmPriority.ToText(), param.BpmPriority);
            MakeSettlement(Settings.keyTonalityPriority.ToText(), param.KeyTonalityPriority);
            MakeSettlement(Settings.keyNumberPriority.ToText(), param.KeyNumberPriority);
            MakeSettlement(Settings.danceabilityPriority.ToText(), param.DanceabilityPriority);
            MakeSettlement(Settings.MP3Quality.ToText(), param.MP3Quality);
        }
    }
}

public static class EnumExtensions
{
    public static string ToText(this Enum enumeration)
    {
        Type type = enumeration.GetType();
        MemberInfo[] memInfo = type.GetMember(enumeration.ToString());

        if (null != memInfo && memInfo.Length > 0)
        {
            object[] attrs = memInfo[0].GetCustomAttributes(typeof(Automix_Data_Management.SettingsAccessor.SettingText), false);
            if (null != attrs && attrs.Length > 0)
                return ((Automix_Data_Management.SettingsAccessor.SettingText)attrs[0]).Text;
        }

        return enumeration.ToString();
    }
}