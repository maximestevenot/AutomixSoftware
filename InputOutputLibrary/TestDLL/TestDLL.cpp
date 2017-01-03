// TestDLL.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <InputOutputLibrary.h>

#pragma comment(lib, "..\\Debug\\InputOutputLibrary.lib")


int main()
{
	mp3_to_wav(L"Bob Marley - Three Little Birds.mp3", L"../Debug/Bob Marley - Three Little Birds_wav_export.mp3");
	wav_to_mp3("../Debug/Bob Marley - Three Little Birds_wav_export.mp3", "../Debug/Bob Marley - Three Little Birds_mp3_export.mp3");
    return 0;
}

