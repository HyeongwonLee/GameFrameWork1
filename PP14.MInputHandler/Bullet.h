#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Bullet : public SDLGameObject
{
private:
	bool CANSHOT = false;
public:
	bool shot();
	Bullet(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};