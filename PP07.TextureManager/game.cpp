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
		m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);


		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		//SDL_FreeSurface(pTempSurface);


		//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

		//m_sourceRectangle.w = 128;
		//m_sourceRectangle.h = 82;

		//m_destinationRectangle.x = m_sourceRectangle.x = 0;
		//m_destinationRectangle.y = m_sourceRectangle.y = 0;
		//m_destinationRectangle.w = m_sourceRectangle.w;
		//m_destinationRectangle.h = m_sourceRectangle.h;

		//m_destinationRectangle2.x = 200;
		//m_destinationRectangle2.y = 200;
		//m_destinationRectangle2.w = m_sourceRectangle.w;
		//m_destinationRectangle2.h = m_sourceRectangle.h;

	}

	else {
		return false;
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);

	m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1,
		m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);

	//SDL_RenderClear(m_pRenderer);

	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle2);

	//SDL_RenderPresent(m_pRenderer);
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
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}