// TestDLL.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <InputOutputLibrary.h>

#pragma comment(lib, "..\\Debug\\InputOutputLibrary.lib")


int main()
{
	mp3_to_wav(L"C:\\Users\\gabon\\Music\\wanna_be_like_you_sim_gretina.mp3", L"C:\\Users\\gabon\\Music\\wav\\wanna_be_like_you_sim_gretina.wav");
    return 0;
}

