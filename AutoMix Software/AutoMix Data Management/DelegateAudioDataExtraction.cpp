// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "DelegateAudioDataExtraction.h"

using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace Newtonsoft::Json;

namespace AutoMixDataManagement {

	void DelegateAudioDataExtraction::extractDelegate(AutoMixDataManagement::Track^ track)
	{
		_startInfo->Arguments = "\"" + track->Path + "\" \"" + track->Name + ".json\" \"" + _tempDirectory->FullName + "\\profile.yaml\"";
		Process^ extractor = gcnew Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		extractor->WaitForExit();
		Threading::Thread::Sleep(50);

		try 
		{
			StreamReader^ file = File::OpenText(_tempDirectory->FullName + "\\" + track->Name + ".json");
			JsonTextReader^ reader = gcnew JsonTextReader(file);
			Linq::JObject^ obj = (Linq::JObject^)Linq::JToken::ReadFrom(reader);

			track->Duration = Convert::ToUInt32((double)obj["metadata"]["audio_properties"]["length"] * 1000);
			track->BPM = Convert::ToUInt32((int)(obj["rhythm"]["bpm"]));
			track->Key = (String^)(obj["tonal"]["key_key"]) + (String^)(obj["tonal"]["key_scale"]);
		} 
		catch (FileNotFoundException^ e)
		{
			e->Message;
			//trackcollection delete track
		}
	}
}