// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
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
    /// Allow to set or get preferences of the user
    /// </summary>
    public abstract class SettingsAccessor
    {
        private static string _dir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware";
        private static XmlDocument configFile;

        public static string GetTempDir()
        {
            string path;
            try
            {
                if (!Directory.Exists(_dir))
                {
                    Directory.CreateDirectory(_dir);
                }
                XmlReader reader = XmlReader.Create(_dir + "\\config.xml");
                if (reader.ReadToDescendant("tempDir"))
                {
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                        path = reader.ReadElementContentAsString() + "\\";
                    }
                    else
                    {
                        //TODO throw BadFormattedConfigFileException
                        path = "Unexpected node type\n";
                    }
                }
                else
                {
                    SetTempDir(Path.GetTempPath() + "AutomixSoftware");
                    path = Path.GetTempPath() + "AutomixSoftware";
                }

                reader.Close();
            }
            catch (Exception e) when (e is SecurityException || e is FileNotFoundException)
            {
                path = Path.GetTempPath() + "AutomixSoftware";
                SetTempDir(Path.GetTempPath() + "AutomixSoftware");
            }
            catch (Exception e) when (e is FormatException || e is InvalidCastException)
            {
                //TODO throw BadFormattedConfigFileException
                path = "Unexpected node type\n";
            }

            return path;
        }

        public static void SetTempDir(string path)
        {
            path += "\\AutomixSoftware";
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            XmlDocument configFile = new XmlDocument();
            configFile.Load(_dir + "\\config.xml");
            XmlNode tempDir = configFile.DocumentElement.SelectSingleNode("//tempDir");
            Console.WriteLine(tempDir.InnerText);
            tempDir.InnerText = path;
            Console.WriteLine(tempDir.InnerText);
        }

        public enum Settings : int
        {
            tempDir = 0,
            transitionDuration = 1,
            mixDuration = 2
        }

        private static XmlWriter OpenOrCreateConfigFile()
        {
            if (!Directory.Exists(_dir))
            {
                Directory.CreateDirectory(_dir);
            }

            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            XmlWriter writer = XmlWriter.Create(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware\\config.xml", settings);

            return writer;
        }

        public static void SetSetting(Settings setting, String param)
        {
            configFile = new XmlDocument();
            try
            {
                configFile.Load(_dir + "\\config.xml"); // Verify if config.xml exists first
            } catch (FileNotFoundException e)
            {
                File.Create(_dir + "\\config.xml");
                configFile.Load(_dir + "\\config.xml");
            }
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
            }
        }

        private static void MakeSettlement(String section, String param)
        {
            XmlNode node = configFile.DocumentElement.SelectSingleNode(section);
            if (node != null) {
                node.InnerText = param;
            } else
            {
                XmlNode root = configFile.DocumentElement;
                XmlElement elem = configFile.CreateElement(section);
                elem.InnerText = param;
                root.AppendChild(elem);
            }

            configFile.Save(_dir+"\\config.xml");
        }

        public static void SetTransitionDuration(int transitionDuration)
        {
            XmlWriter writer = OpenOrCreateConfigFile();
            writer.WriteStartElement("parameters");
            writer.WriteElementString("transitionDuration", transitionDuration.ToString());
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }

        public static void SetMixDuration(int mixDuration)
        {
            XmlWriter writer = OpenOrCreateConfigFile();
            writer.WriteStartElement("parameters");
            writer.WriteElementString("mixDuration", mixDuration.ToString());
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }

        public static int GetTransitionDuration()
        {
            int transitionDuration;
            try
            {
                if (!Directory.Exists(_dir))
                {
                    Directory.CreateDirectory(_dir);
                }
                XmlReader reader = XmlReader.Create(_dir + "\\config.xml");
                if (reader.ReadToDescendant("transitionDuration"))
                {
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                        transitionDuration = reader.ReadElementContentAsInt();
                    }
                    else
                    {
                        //TODO throw BadFormattedConfigFileException
                        transitionDuration = -1;
                    }
                }
                else
                {
                    transitionDuration = -1;
                }

                reader.Close();
            }
            catch (Exception e) when (e is SecurityException || e is FileNotFoundException)
            {
                transitionDuration = -1;
            }
            catch (Exception e) when (e is FormatException || e is InvalidCastException)
            {
                //TODO throw BadFormattedConfigFileException
                transitionDuration = -1;
            }

            if (transitionDuration == -1)
            {
                SetTransitionDuration(SmoothMix.DEFAULTTRANSITIONDURATION);
            }

            return transitionDuration;
        }

        public static int GetMixDuration()
        {
            int mixDuration;
            try
            {
                if (!Directory.Exists(_dir))
                {
                    Directory.CreateDirectory(_dir);
                }
                XmlReader reader = XmlReader.Create(_dir + "\\config.xml");
                if (reader.ReadToDescendant("mixDuration"))
                {
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                        mixDuration = reader.ReadElementContentAsInt();
                    }
                    else
                    {
                        //TODO throw BadFormattedConfigFileException
                        mixDuration = -1;
                    }
                }
                else
                {
                    mixDuration = -1;
                }

                reader.Close();
            }
            catch (Exception e) when (e is SecurityException || e is FileNotFoundException)
            {
                mixDuration = -1;
            }
            catch (Exception e) when (e is FormatException || e is InvalidCastException)
            {
                //TODO throw BadFormattedConfigFileException
                mixDuration = -1;
            }

            if (mixDuration == -1)
            {
                SetTransitionDuration(SmoothMix.DEFAULTMIXDURATION);
            }

            return mixDuration;
        }
    }

}
