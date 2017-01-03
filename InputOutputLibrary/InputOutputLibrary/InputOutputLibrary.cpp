// InputOutputLibrary.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"



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


INPUTOUTPUTLIBRARY_API int lame_encoding(char* sourcefile, char* destinationfile)
{
	int read, write;

	FILE *wav = fopen(sourcefile, "rb");
	FILE *mp3 = fopen(destinationfile, "wb");

	const int WAV_SIZE = 8192;
	const int MP3_SIZE = 8192;

	short int wav_buffer[WAV_SIZE * 2];
	unsigned char mp3_buffer[MP3_SIZE];

	lame_t lame = lame_init();
	lame_set_in_samplerate(lame, 44100);
	lame_set_VBR(lame, vbr_default);
	lame_init_params(lame);

	do {
		read = fread(wav_buffer, 2 * sizeof(short int), WAV_SIZE, wav);
		if (read == 0)
			write = lame_encode_flush(lame, mp3_buffer, MP3_SIZE);
		else
			write = lame_encode_buffer_interleaved(lame, wav_buffer, read, mp3_buffer, MP3_SIZE);
		fwrite(mp3_buffer, write, 1, mp3);
	} while (read != 0);

	lame_close(lame);
	fclose(mp3);
	fclose(wav);

	return 0;
}


// Il s'agit du constructeur d'une classe qui a été exportée.
// consultez InputOutputLibrary.h pour la définition de la classe
CInputOutputLibrary::CInputOutputLibrary()
{
    return;
}
