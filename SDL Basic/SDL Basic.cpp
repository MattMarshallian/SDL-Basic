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
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (nullptr == window) {
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

	if (nullptr == renderer) {
		cout << "Cannot create renderer " << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if (nullptr == texture) {
		cout << "Cannot create texture " << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];
	memset(buffer, 0x00, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

	buffer[30000] = 0xFFFFFFFF; // set color of single pixel

	for (unsigned int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; ++i) {
		buffer[i] = 0x0000FF11;
	}

	SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

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

	delete[] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

// ble ble - usunac pozniej
