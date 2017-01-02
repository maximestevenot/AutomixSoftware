// InputOutputLibrary.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "InputOutputLibrary.h"


// Il s'agit d'un exemple de variable exportée
INPUTOUTPUTLIBRARY_API int nInputOutputLibrary=0;

// Il s'agit d'un exemple de fonction exportée.
INPUTOUTPUTLIBRARY_API int fnInputOutputLibrary(void)
{
    return 42;
}


INPUTOUTPUTLIBRARY_API int mp3_to_wav(wchar_t* sourcefile, wchar_t* destinationfile)
{
	HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);


	const WCHAR *wszSourceFile = sourcefile;
	const WCHAR *wszTargetFile = destinationfile;


	const LONG MAX_AUDIO_DURATION_MSEC = 18000000; // 5 hours max

	HRESULT hr = S_OK;

	IMFSourceReader *pReader = nullptr;
	HANDLE hFile = INVALID_HANDLE_VALUE;

	// Initialize the COM library.
	hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	// Initialize the Media Foundation platform.
	if (SUCCEEDED(hr))
	{
		hr = MFStartup(MF_VERSION);
	}

	// Create the source reader to read the input file.
	if (SUCCEEDED(hr))
	{
		hr = MFCreateSourceReaderFromURL(wszSourceFile, nullptr, &pReader);
		if (FAILED(hr))
		{
			printf("Error opening input file: %S\n", wszSourceFile, hr);
		}
	}

	// Open the output file for writing.
	if (SUCCEEDED(hr))
	{
		hFile = CreateFile(wszTargetFile, GENERIC_WRITE, FILE_SHARE_READ, nullptr,
			CREATE_ALWAYS, 0, nullptr);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
			printf("Cannot create output file: %S\n", wszTargetFile, hr);
		}
	}

	// Write the WAVE file.
	if (SUCCEEDED(hr))
	{
		hr = WriteWaveFile(pReader, hFile, MAX_AUDIO_DURATION_MSEC);
	}

	if (FAILED(hr))
	{
		printf("Failed, hr = 0x%X\n", hr);
	}

	// Clean up.
	if (hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
	}

	SafeRelease(&pReader);
	MFShutdown();
	CoUninitialize();

	return SUCCEEDED(hr) ? 0 : 1;
};


// Il s'agit du constructeur d'une classe qui a été exportée.
// consultez InputOutputLibrary.h pour la définition de la classe
CInputOutputLibrary::CInputOutputLibrary()
{
    return;
}
