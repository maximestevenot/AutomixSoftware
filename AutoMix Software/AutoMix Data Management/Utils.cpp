#include "stdafx.h"
#include "Utils.h"

namespace AutomixDataManagement {

		using namespace System;

		String^ nameFromPath(String^ path)
		{
			int index = path->LastIndexOf("\\");
			return path->Substring(index + 1);
		}

		String^ getExtension(String^ fileName)
		{
			int lastDotIndex = fileName->LastIndexOf(".");
			return fileName->Substring(lastDotIndex + 1)->ToLower();
		}
	}