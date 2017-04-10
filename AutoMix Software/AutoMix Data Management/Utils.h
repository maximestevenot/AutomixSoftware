// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixDataManagement {

	/// <summary>
	/// Provides some tools to manipulate strings
	/// </summary>
	public ref class Utils
	{
	public:
		
		/// <summary>
		/// Extract the name of a file (including extension) from a path
		/// </summary>
		/// <param name="path">The file path</param>
		/// <param name="outputFile">The name in a new <c>String^</c></param>
		static System::String^ nameFromPath(System::String^ path);

		/// <summary>
		/// Extract the extension of a file name
		/// </summary>
		/// <param name="path">The file name</param>
		/// <param name="outputFile">The extension in a new <c>String^</c></param>
		static System::String^ getExtension(System::String^ fileName);

		/// <summary>
		/// Convert a musical key into Openkey notation
		/// </summary>
		/// <param name="key">The music key</param>
		/// <param name="scale">The music scale : major or minor</param>
		/// <param name="outputFile">The openkey in a new <c>String^</c></param>
		static System::String^ convertToOpenKey(System::String^ key, System::String^ scale);
	};
}