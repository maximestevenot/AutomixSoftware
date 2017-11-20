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

namespace Automix_Data_Management
{
    /// <summary>
    /// Provides some tools to manipulate strings
    /// </summary>
    public abstract class Utils
    {

        /// <summary>
        /// Extracts the name of a file (including extension) from a path
        /// </summary>
        /// <param name="path">The file path</param>
        /// <returns>The name in a new <c>string</c></returns>
        public static string NameFromPath(string path)
        {
            if (string.IsNullOrEmpty(path))
            {
                return string.Empty;
            }

            var index = path.LastIndexOf("\\", StringComparison.Ordinal);
            return path.Substring(index + 1);
        }

        /// <summary>
        /// Extracts the extension from a file name
        /// </summary>
        /// <param name="fileName">The file name</param>
        /// <returns>The extension in a new <c>string</c></returns>
        public static string GetExtension(string fileName)
        {
            if (string.IsNullOrEmpty(fileName))
            {
                return string.Empty;
            }

            var lastDotIndex = fileName.LastIndexOf(".", StringComparison.Ordinal);
            return fileName.Substring(lastDotIndex + 1).ToLower();
        }

        /// <summary>
        /// Convert a musical key into Openkey notation
        /// </summary>
        /// <param name="key">The music key</param>
        /// <param name="scale">The music scale : major or minor</param>
        /// <returns>The openkey in a new <c>string</c></returns>
        public static string ConvertToOpenKey(string key, string scale)
        {
            if (string.IsNullOrEmpty(key) || string.IsNullOrEmpty(scale))
            {
                return string.Empty;
            }

            string openKeyString;

            // NOTE : string comparison is by default Ordinal (case-sensitive and culture-insensitive)
            //        e.g. what we want here in both the key and the scale comparisons
            switch (key)
            {
                case "A":
                    openKeyString = scale.Equals("major") ? "4d" : "1m";
                    break;
                case "B":
                    openKeyString = scale.Equals("major") ? "6d" : "3m";
                    break;
                case "C":
                    openKeyString = scale.Equals("major") ? "1d" : "10m";
                    break;
                case "D":
                    openKeyString = scale.Equals("major") ? "3d" : "12m";
                    break;
                case "E":
                    openKeyString = scale.Equals("major") ? "5d" : "2m";
                    break;
                case "F":
                    openKeyString = scale.Equals("major") ? "12d" : "9m";
                    break;
                case "G":
                    openKeyString = scale.Equals("major") ? "2d" : "11m";
                    break;
                case "A#":
                    openKeyString = scale.Equals("major") ? "11d" : "8m";
                    break;
                case "C#":
                    openKeyString = scale.Equals("major") ? "8d" : "5m";
                    break;
                case "D#":
                    openKeyString = scale.Equals("major") ? "10d" : "7m";
                    break;
                case "F#":
                    openKeyString = scale.Equals("major") ? "4m" : "7d";
                    break;
                case "G#":
                    openKeyString = scale.Equals("major") ? "9d" : "6m";
                    break;
                default:
                    openKeyString = string.Empty;
                    break;
            }

            return openKeyString;
        }

        public static string GetTempDir()
        {
            string path;
            try
            {
                XmlReader reader = XmlReader.Create(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware\\config.xml");
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
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            XmlWriter writer = XmlWriter.Create(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware\\config.xml", settings);
            writer.WriteStartElement("configuration");
            writer.WriteElementString("tempDir", path);
            writer.WriteEndElement();
            writer.Flush();
            writer.Close();
        }
    }
}
