
#include "stdafx.h"
#include "AudioDataExportationMock.h"

#include <Windows.h>
#include <afx.h>

using namespace System;
using namespace System::IO;
using namespace System::Text;

namespace AutoMixDataManagement {

	AudioDataExportationMock::AudioDataExportationMock(System::String^ path)
	{
		_path = path;
	}

	void AudioDataExportationMock::exportTrackList(TrackCollection^) {
		FileStream^ file = File::Open(_path, FileMode::Open, FileAccess::Write, FileShare::None);
		try {
			array<Byte>^info = (gcnew UTF8Encoding(true))->GetBytes(_path);
			file->Write(info, 0, info->Length);
		}
		finally{
			if (file) {
				delete(IDisposable^)file;
			}
		}
	}
}