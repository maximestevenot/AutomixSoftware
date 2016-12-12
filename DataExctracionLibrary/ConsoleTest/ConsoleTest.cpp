// ConsoleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <DataExctracionLibrary.h>
#include <iostream>

#pragma comment(lib, "..\\Debug\\DataExctracionLibrary.lib")

using namespace std;

int main()
{
	cout << fnDataExctracionLibrary() << endl;

	while (1);
    return 0;
}

