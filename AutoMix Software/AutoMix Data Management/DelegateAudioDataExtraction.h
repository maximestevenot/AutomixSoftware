#pragma once

public ref class DelegateAudioDataExtraction
{
public:
	DelegateAudioDataExtraction(System::Diagnostics::ProcessStartInfo^ startInfo, System::IO::DirectoryInfo^ tempDirectory):_startInfo(startInfo), _tempDirectory(tempDirectory) {}

	void extractDelegate(AutoMixDataManagement::Track^ track)
	{
		_startInfo->Arguments = "\"" + track->Path + "\" \"" + track->Name + ".json\" \"" + _tempDirectory->FullName + "\\profile.yaml\"";
		System::Diagnostics::Process^ extractor = gcnew System::Diagnostics::Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		extractor->WaitForExit();
	}

private:
	System::Diagnostics::ProcessStartInfo^ _startInfo;
	System::IO::DirectoryInfo^ _tempDirectory;
};