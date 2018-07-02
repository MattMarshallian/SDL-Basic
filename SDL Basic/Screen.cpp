#include "stdafx.h"
#include "Screen.h"


Screen::Screen() :m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr)
{
}


Screen::~Screen()
{
}

bool Screen::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Explosion Fire",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (nullptr == m_window) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

	if (nullptr == m_renderer) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (nullptr == m_texture) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];
	memset(m_buffer, 0x00, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

	m_buffer[30000] = 0xFFFFFFFF; // set color of single pixel

	for (unsigned int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; ++i) {
		m_buffer[i] = 0x0000FF11;
	}

	update();

	return true;
}

bool Screen::processEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	};
	return true;
}

void Screen::close()
{
	delete[] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer[(y * WINDOW_WIDTH + x)] = color;
}

void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
