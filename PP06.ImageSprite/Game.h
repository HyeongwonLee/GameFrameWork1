#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include <iostream>



class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	int m_currentFrame;
	TextureManager m_textureManager;

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update() ;
	void handleEvent();
	void clean();
	bool running() { return m_bRunning; }
};
