#pragma once
#include <iostream>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"

class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

	GameObject m_go;
	Player m_player;

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvent();
	void clean();
	bool running() { return m_bRunning; }
};
