// ConsoleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <DataExtractionLibrary.h>
#include <iostream>

#pragma comment(lib, "..\\Debug\\DataExtractionLibrary.lib")

using namespace std;

int main()
{
	cout << fnDataExtractionLibrary() << endl;

	while (1);
    return 0;
}

