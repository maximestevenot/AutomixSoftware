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
    public class SettingsAccessor
    {
        private readonly string Dir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware";
        private XmlDocument _configFile;

        public SettingsAccessor()
        {
            _configFile = OpenOrCreateConfigFile();
        }

        public class SettingText : Attribute
        {
            public string Text { get; }

            public SettingText(string text)
            {
                Text = text;
            }
        }

        public enum Settings
        {
            [SettingText("tempDir")]
            TempDir = 0,
            [SettingText("transitionDuration")]
            TransitionDuration = 1,
            [SettingText("mixDuration")]
            MixDuration = 2,
            [SettingText("bpmP")]
            BpmPriority = 3,
            [SettingText("keyTonalityP")]
            KeyTonalityPriority = 4,
            [SettingText("keyNumberP")]
            KeyNumberPriority = 5,
            [SettingText("danceabilityP")]
            DanceabilityPriority = 6,
            [SettingText("MP3Quality")]
            Mp3Quality = 7
        }

        public void SetSetting(Settings setting, string param)
        {
            if (setting == Settings.TempDir)
            {
                if (!Directory.Exists(param))
                {
                    Directory.CreateDirectory(param);
                }
                MakeSettlement(setting.ToText(), param + "\\AutomixSoftware");
            }
            else if (setting == Settings.TransitionDuration || setting == Settings.MixDuration ||
                     setting == Settings.BpmPriority || setting == Settings.KeyNumberPriority ||
                     setting == Settings.KeyTonalityPriority || setting == Settings.DanceabilityPriority ||
                     setting == Settings.Mp3Quality)
            {
                MakeSettlement(setting.ToText(), param);
            }
        }

        public string GetSetting(Settings setting)
        {
            var node = _configFile.DocumentElement?.SelectSingleNode(setting.ToText());
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

            _configFile.Save(Dir + "\\config.xml");

        }

        private XmlDocument OpenOrCreateConfigFile()
        {
            if (!Directory.Exists(Dir))
            {
                Directory.CreateDirectory(Dir);
            }

            if (!File.Exists(Dir + "\\config.xml"))
            {
                CreateDefaultConfigFile();
            }

            var file = new XmlDocument();
            try
            {
                file.Load(Dir + "\\config.xml");
            }
            catch (System.Xml.XmlException e)
            {
                CreateDefaultConfigFile();
                //log this
            }
            file.Load(Dir + "\\config.xml");
            return file;
        }

        private void CreateDefaultConfigFile()
        {
            var settings = new XmlWriterSettings
            {
                Indent = true
            };

            var defaultParameters = new Parameters();
            var writer = XmlWriter.Create(Dir + "\\config.xml", settings);

            writer.WriteStartElement("configuration");
            writer.WriteElementString(Settings.TempDir.ToText(), defaultParameters.TempDir);
            writer.WriteElementString(Settings.MixDuration.ToText(), defaultParameters.MixDuration);
            writer.WriteElementString(Settings.TransitionDuration.ToText(), defaultParameters.TransitionDuration);
            writer.WriteElementString(Settings.BpmPriority.ToText(), defaultParameters.BpmPriority);
            writer.WriteElementString(Settings.KeyTonalityPriority.ToText(), defaultParameters.KeyTonalityPriority);
            writer.WriteElementString(Settings.KeyNumberPriority.ToText(), defaultParameters.KeyNumberPriority);
            writer.WriteElementString(Settings.DanceabilityPriority.ToText(), defaultParameters.DanceabilityPriority);
            writer.WriteElementString(Settings.Mp3Quality.ToText(), defaultParameters.Mp3Quality);
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }

        public Parameters LoadParametersFromFile()
        {
            var param = new Parameters();

            var document = _configFile.DocumentElement;
            if (document == null)
            {
                return param;
            }

            var node = document.SelectSingleNode(Settings.TempDir.ToText());
            if (node != null)
            {
                param.TempDir = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.TransitionDuration.ToText());
            if (node != null)
            {
                param.TransitionDuration = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.MixDuration.ToText());
            if (node != null)
            {
                param.MixDuration = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.BpmPriority.ToText());
            if (node != null)
            {
                param.BpmPriority = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.KeyNumberPriority.ToText());
            if (node != null)
            {
                param.KeyNumberPriority = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.KeyTonalityPriority.ToText());
            if (node != null)
            {
                param.KeyTonalityPriority = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.DanceabilityPriority.ToText());
            if (node != null)
            {
                param.DanceabilityPriority = node.InnerText;
            }

            node = document.SelectSingleNode(Settings.Mp3Quality.ToText());
            if (node != null)
            {
                param.Mp3Quality = node.InnerText;
            }

            return param;
        }

        public void SaveParametersInFile(Parameters param)
        {
            MakeSettlement(Settings.TempDir.ToText(), param.TempDir);
            MakeSettlement(Settings.MixDuration.ToText(), param.MixDuration);
            MakeSettlement(Settings.TransitionDuration.ToText(), param.TransitionDuration);
            MakeSettlement(Settings.BpmPriority.ToText(), param.BpmPriority);
            MakeSettlement(Settings.KeyTonalityPriority.ToText(), param.KeyTonalityPriority);
            MakeSettlement(Settings.KeyNumberPriority.ToText(), param.KeyNumberPriority);
            MakeSettlement(Settings.DanceabilityPriority.ToText(), param.DanceabilityPriority);
            MakeSettlement(Settings.Mp3Quality.ToText(), param.Mp3Quality);
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