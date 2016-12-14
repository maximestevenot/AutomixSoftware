#include "stdafx.h"

#include "AutoMixDataManagement.h"
#include "AudioExportationMock.h"

namespace AutoMixDataManagement {

	AudioExportationProxy::AudioExportationProxy(System::String ^ path)
	{
		_path = path;
		_realSubject = gcnew AudioExportationMock(_path);
	}

	void AudioExportationProxy::exportTrackList(TrackCollection^ tracks)
	{
		if (!tracks)
		{
			return;
		}

		try 
		{
			_realSubject->exportTrackList(tracks);
		}
		catch (System::IO::IOException^)
		{
			System::Diagnostics::Debug::WriteLine("Impossible d'écrire dans le fichier spécifié.");
		}
	}

}