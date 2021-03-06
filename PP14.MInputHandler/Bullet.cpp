#include "Bullet.h"
#include "Player.h"
#include "TextureManager.h"


Bullet ::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	draw();
}

void Bullet::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Bullet::update()
{
	m_velocity.setX(5);
	m_velocity.setY(0);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}
void Bullet::clean()
{
}
