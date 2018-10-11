#include "Game.h"
#include <SDL_image.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// 

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
		SDL_Surface* pTempSurface2 = IMG_Load("Assets/Tree.png");

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		m_pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);

		SDL_FreeSurface(pTempSurface);

		SDL_FreeSurface(pTempSurface2);

		SDL_QueryTexture(m_pTexture2, NULL, NULL, &m_sourceTree.w, &m_sourceTree.h);

		SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_sourceRectangle2.w = 128;
		m_sourceRectangle2.h = 82;

		m_sourceTree.w = 200;
		m_sourceTree.h = 200;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		m_destinationRectangle2.x = 200;
		m_destinationRectangle2.y = 200;
		m_destinationRectangle2.w = m_sourceRectangle.w;
		m_destinationRectangle2.h = m_sourceRectangle.h;


		m_sourceTree.x = 0;
		m_sourceTree.y = 0;
		m_destinationTree.x = 150;
		m_destinationTree.y = 150;
		m_destinationTree.w = m_sourceTree.w;
		m_destinationTree.h = m_sourceTree.h;

	}

	else {
		return false;
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);


	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle2, &m_destinationRectangle2);

	//SDL_RenderCopy(m_pRenderer, m_pTexture2, &m_sourceTree, &m_destinationTree);

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "claning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvent()
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));

	m_sourceRectangle2.x = 128 * int(((SDL_GetTicks() / 50) % 6));
}