#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvent();
		g_game->update();
		g_game->render();
		SDL_Delay(10); // add the delay
	}
	//	SDL_Delay(5000);
	g_game->clean();
	return 0;
}