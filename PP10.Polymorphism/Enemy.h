#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	virtual void update();
	void clean();
};