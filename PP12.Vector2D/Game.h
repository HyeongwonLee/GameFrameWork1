#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "Player.h"
#include "TextureManager.h"
#include "Enemy.h"
#include "LoaderParams.h"

class Game
{
private:
	Game() {}
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
	int m_currentFrame;

	static Game* s_pInstance;

	std::vector<GameObject*> m_gameObjects;

public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvent();
	void clean();
	bool running() { return m_bRunning; }

	SDL_Renderer* GetRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
};
typedef Game TheGame;