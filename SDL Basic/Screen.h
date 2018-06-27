#pragma once

#include <SDL.h>

// in MinGW version class Screen is inside sdlbasic namespace
class Screen
{
public:
	const static int WINDOW_WIDTH = 800;
	const static int WINDOW_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
public:
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvents();
	void close();
};

