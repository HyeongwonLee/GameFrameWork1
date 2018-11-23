#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

			m_pGameStateMachine = new GameStateMachine();
	        m_pGameStateMachine->changeState(MenuState::Instance());

		//if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
		//	"animate", m_pRenderer))
		//{
		//	return false;
		//}
		//if (!TheTextureManager::Instance()->load("assets/Bullet.png", "Bullet", m_pRenderer))
		//	return false;


		//m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	}

	else {
		return false;
	}

	return true;
}

void Game::render()
{

	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);

	//SDL_RenderClear(m_pRenderer); // clear to the draw colour
	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->draw();
	//}
	//SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean()
{
	std::cout << "claning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::handleEvent()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
}

void Game::update()
{

	m_pGameStateMachine->update();

	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->update();
	//}
}

void Game::quit()
{
	m_bRunning = false;
}