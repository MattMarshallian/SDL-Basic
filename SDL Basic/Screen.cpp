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
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (nullptr == m_window) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

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

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	clear();

	m_buffer[30000] = 0xFFFFFFFF; // set color of single pixel

	for (unsigned int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i) {
		m_buffer[i] = 0x0000000;
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


void Screen::clear() {
	memset(m_buffer, 0x00, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
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

	// it is inefficient 
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer[(y * SCREEN_WIDTH + x)] = color;
}

void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
