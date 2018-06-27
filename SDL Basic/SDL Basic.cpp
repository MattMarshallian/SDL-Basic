// SDL Basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Screen.h"

// #undef ponizej to jakas sztuczka z
// https://stackoverflow.com/questions/6847360/error-lnk2019-unresolved-external-symbol-main-referenced-in-function-tmainc
// co ciekawe, to samo trzeba bylo zrobic na MinGW
#undef main


using namespace std;

int main()
{
	Screen screen;
	if (false == screen.init()) {
		cout << "Error initialization SDL" << endl;
	}

	while (true) { // ta pętla żre cały jeden rdzeń procesora
		// Upgrade particles
		// Draw particles
		// Check for messages/events
		if (false == screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}
