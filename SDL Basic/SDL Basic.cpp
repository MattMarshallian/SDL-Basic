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
		// Updade particles

		// Draw particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; ++y) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; ++x) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}
		screen.setPixel(400, 300, 255, 255, 255);

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (false == screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}
