using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

// General Information about an assembly is controlled through the following
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
[assembly: AssemblyTitle("Automix Data Management")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("LesProjecteurs")]
[assembly: AssemblyProduct("Automix Software")]
[assembly: AssemblyCopyright("Copyright © 2016-2017 LesProjecteurs - All Rights Reserved")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCulture("")]

// Setting ComVisible to false makes the types in this assembly not visible
// to COM components.  If you need to access a type in this assembly from
// COM, set the ComVisible attribute to true on that type.
[assembly: ComVisible(false)]

// The following GUID is for the ID of the typelib if this project is exposed to COM
[assembly: Guid("ea011bc3-8963-4062-a9c4-0a5a2a6bcd7c")]

// Set configuration of log4net
[assembly: log4net.Config.XmlConfigurator(ConfigFile = "log4net.config")]

// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version
//      Build Number
//      Revision
//
// You can specify all the values or you can default the Build and Revision Numbers
// by using the '*' as shown below:
// [assembly: AssemblyVersion("1.0.*")]
[assembly: AssemblyVersion("1.2.0.0")]
[assembly: AssemblyFileVersion("1.2.0.0")]
[assembly: InternalsVisibleTo("Automix Data Management.Tests")]
[assembly: InternalsVisibleTo("Automix Data Management.Explorables")]

