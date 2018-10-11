#pragma once
#include "SDL.h"
#include <iostream>



class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	SDL_Texture* m_pTexture;
	SDL_Texture* m_pTexture2;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_sourceRectangle2;
	SDL_Rect m_destinationRectangle;
	SDL_Rect m_destinationRectangle2;
	SDL_Rect m_sourceTree;
	SDL_Rect m_destinationTree;


public:
	Game() {}
	~Game() {}
	bool init(const char* title, float xpos, float ypos, float width, float height, bool fullscreen);

	void render();
	void update() ;
	void handleEvent();
	void clean();
	bool running() { return m_bRunning; }
};
