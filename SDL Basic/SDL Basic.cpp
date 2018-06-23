// SDL Basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SDL.h>

// #undef ponizej to jakas sztuczka z
// https://stackoverflow.com/questions/6847360/error-lnk2019-unresolved-external-symbol-main-referenced-in-function-tmainc
// co ciekawe, to samo trzeba bylo zrobic na MinGW
#undef main

#include <iostream>

using namespace std;

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL screwed up" << endl;
		return 1;
	}

	cout << "Hello world with SDL2" << endl;

	SDL_Quit();

    return 0;
}

// ble ble - usunac pozniej
