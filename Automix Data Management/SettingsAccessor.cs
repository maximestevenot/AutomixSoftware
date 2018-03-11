﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.IO;
using System.Security;
using System.Xml;
using Automix_Data_Management.Exportation;

namespace Automix_Data_Management
{
    /// <summary>
    /// Allow to set or get preferences/settings of the user
    /// </summary>
    public abstract class SettingsAccessor
    {
        private static string _dir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware";
        private static XmlDocument configFile;
        
        public enum Settings : int
        {
            tempDir = 0,
            transitionDuration = 1,
            mixDuration = 2,
            bpmPriority = 3,
            keyTonalityPriority = 4,
            keyNumberPriority = 5,
            danceabilityPriority = 6
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
                    MakeSettlement("tempDir", param + "\\AutomixSoftware");
                    break;
                case Settings.transitionDuration:
                    MakeSettlement("transitionDuration", param);
                    break;
                case Settings.mixDuration:
                    MakeSettlement("mixDuration", param);
                    break;
                case Settings.bpmPriority:
                    MakeSettlement("bpmP", param);
                    break;
                case Settings.keyNumberPriority:
                    MakeSettlement("keyNumberP", param);
                    break;
                case Settings.keyTonalityPriority:
                    MakeSettlement("keyTonalityP", param);
                    break;
                case Settings.danceabilityPriority:
                    MakeSettlement("danceabilityP", param);
                    break;
            }
        }

        public static String GetSetting(Settings setting)
        {
            configFile = OpenOrCreateConfigFile();
            XmlNode node;

            switch (setting)
            {
                case Settings.tempDir:
                    node = configFile.DocumentElement.SelectSingleNode("tempDir");
                    return node.InnerText;
                case Settings.transitionDuration:
                    node = configFile.DocumentElement.SelectSingleNode("transitionDuration");
                    return node.InnerText;
                case Settings.mixDuration:
                    node = configFile.DocumentElement.SelectSingleNode("mixDuration");
                    return node.InnerText;
                case Settings.bpmPriority:
                    node = configFile.DocumentElement.SelectSingleNode("bpmP");
                    return node.InnerText;
                case Settings.keyNumberPriority:
                    node = configFile.DocumentElement.SelectSingleNode("keyNumberP");
                    return node.InnerText;
                case Settings.keyTonalityPriority:
                    node = configFile.DocumentElement.SelectSingleNode("keyTonalityP");
                    return node.InnerText;
                case Settings.danceabilityPriority:
                    node = configFile.DocumentElement.SelectSingleNode("danceabilityP");
                    return node.InnerText;
                default:
                    return "Setting Not Found";
            }
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
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            XmlWriter writer = XmlWriter.Create(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware\\config.xml", settings);
            writer.WriteStartElement("configuration");
            writer.WriteElementString("tempDir", _dir);
            writer.WriteElementString("transitionDuration", "10");
            writer.WriteElementString("mixDuration", "30");
            writer.WriteElementString("bpmP", "0");
            writer.WriteElementString("keyNumberP", "0");
            writer.WriteElementString("keyTonalityP", "0");
            writer.WriteElementString("danceabilityP", "0");
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }
    }
}
