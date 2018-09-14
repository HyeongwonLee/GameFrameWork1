#pragma once
#include "SDL.h"
#include <iostream>
#include <stdio.h>

class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update() {};
	void handleEvent();
	void clean();
	bool running() { return m_bRunning; }
};