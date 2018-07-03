// SDL Basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

// #undef ponizej to jakas sztuczka z
// https://stackoverflow.com/questions/6847360/error-lnk2019-unresolved-external-symbol-main-referenced-in-function-tmainc
// co ciekawe, to samo trzeba bylo zrobic na MinGW
#undef main


using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Screen screen;
	if (false == screen.init()) {
		cout << "Error initialization SDL" << endl;
	}

	Swarm swarm;

	while (true) { // ta pętla żre cały jeden rdzeń procesora
		// Updade particles

		swarm.update();

		int elapsed = SDL_GetTicks();
		unsigned int red = static_cast<unsigned char>((1 + sin(elapsed * 0.0003)) * 128);
		unsigned int green = static_cast<unsigned char>((1 + sin(elapsed * 0.0005)) * 128);
		unsigned int blue = static_cast<unsigned char>((1 + sin(elapsed * 0.0007)) * 128);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; ++i) {
			Particle particle = pParticles[i];

			int x = static_cast<int>((particle.m_x + 1) * Screen::SCREEN_WIDTH / 2);
			int y = static_cast<int>((particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2);

			screen.setPixel(x, y, red, green, blue);
		}

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
