// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "Utils.h"

namespace AutoMixDataManagement {

	using namespace System;

	String^ Utils::nameFromPath(String ^ path)
	{
		int index = path->LastIndexOf("\\");
		return path->Substring(index + 1);
	}

	String^ Utils::getExtension(String^ fileName)
	{
		int lastDotIndex = fileName->LastIndexOf(".");
		return fileName->Substring(lastDotIndex + 1)->ToLower();
	}

	String^ Utils::convertToOpenKey(String^ key, String^ scale)
	{
		if (String::IsNullOrEmpty(key) || String::IsNullOrEmpty(scale))
		{
			return nullptr;
		}

		String^ openKey = "";

		if (key->Equals("A"))
		{
			openKey = scale->Equals("major") ? "4d" : "1m";
		}
		else if (key->Equals("B"))
		{
			openKey = scale->Equals("major") ? "6d" : "3m";
		}
		else if (key->Equals("C") || key->Equals("B#"))
		{
			openKey = scale->Equals("major") ? "1d" : "10m";
		}
		else if (key->Equals("D"))
		{
			openKey = scale->Equals("major") ? "3d" : "12m";
		}
		else if (key->Equals("E"))
		{
			openKey = scale->Equals("major") ? "5d" : "2m";
		}
		else if (key->Equals("F") || key->Equals("E#"))
		{
			openKey = scale->Equals("major") ? "12d" : "9m";
		}
		else if (key->Equals("G"))
		{
			openKey = scale->Equals("major") ? "2d" : "11m";
		}
		else if (key->Equals("A#"))
		{
			openKey = scale->Equals("major") ? "11d" : "8m";
		}
		else if (key->Equals("C#"))
		{
			openKey = scale->Equals("major") ? "8d" : "5m";
		}
		else if (key->Equals("D#"))
		{
			openKey = scale->Equals("major") ? "10d" : "7m";
		}
		else if (key->Equals("F#"))
		{
			openKey = scale->Equals("major") ? "4m" : "7d";
		}
		else if (key->Equals("G#"))
		{
			openKey = scale->Equals("major") ? "9d" : "6m";
		}

		return openKey;
	}
}