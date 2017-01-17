#pragma once

public ref class DelegateAudioDataExtraction
{
public:
	DelegateAudioDataExtraction(System::Diagnostics::ProcessStartInfo^ startInfo):_startInfo(startInfo) {}

	void extractDelegate(AutoMixDataManagement::TrackCollection::Enumerator i)
	{
		System::String^ parameters = i.Current->Path + " " + i.Current->Name + _startInfo->Arguments;
		_startInfo->Arguments = parameters;
		System::Diagnostics::Process^ extractor = gcnew System::Diagnostics::Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		extractor->WaitForExit();
	}

private:
	System::Diagnostics::ProcessStartInfo^ _startInfo;
};