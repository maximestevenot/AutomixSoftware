// TestDLL.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <InputOutputLibrary.h>
#include <cstdlib>
#include <ostream>
#include <iostream>

#pragma comment(lib, "..\\Debug\\InputOutputLibrary.lib")


int main()
{
	
	mp3_to_wav(L"Bob Marley - Three Little Birds.mp3", L"../Debug/three_little_birds_export.wav");
	mp3_to_wav(L"Cascada - Everytime We Touch (Fallen Superhero Remix)_01.mp3", L"../Debug/everytime_we_touch_export.wav");
	mp3_to_wav(L"Da Tweekaz - Frozen (Disney Tool)_01.mp3", L"../Debug/frozen_export.wav");
	mp3_to_wav(L"Eurythmics - Sweet Dreams (Are Made Of This) (Hardstyle Remix)_01.mp3", L"../Debug/sweet_dreams_export.wav");
	
	system("	\"copy /B \"..\\Debug\\three_little_birds_export.wav\" + \"..\\Debug\\everytime_we_touch_export.wav\" + \"..\\Debug\\frozen_export.wav\" + \"..\\Debug\\sweet_dreams_export.wav\" \"..\\Debug\\wavexportFile.wav\" \"	");

	std::cout << "encoding... please wait" << std::endl;
	wav_to_mp3("../Debug/wavexportFile.wav", "../Debug/mp3exportFile.mp3");
	
    return 0;
}

