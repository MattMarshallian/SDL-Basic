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
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL screwed up" << endl;
		return 1;
	}

	cout << "Hello world with SDL2" << endl;

	SDL_Window *window = SDL_CreateWindow("Particle Explosion Fire",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (nullptr == window) {
		SDL_Quit();
		return 2;
	}

	SDL_Event event;
	bool quit = false;
	while (!quit) { // ta pętla żre cały jeden rdzeń procesora
		// Upgrade particles
		// Draw particles
		// Check for messages/events
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		};
	}

	SDL_Quit();

    return 0;
}

// ble ble - usunac pozniej
