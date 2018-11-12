#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "Player.h"
#include "TextureManager.h"
#include "Enemy.h"

class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	//GameObject m_go;
	//Player m_player;
	bool m_bRunning;
	int m_currentFrame;

	//int xpos;
	//int ypos;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;

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
