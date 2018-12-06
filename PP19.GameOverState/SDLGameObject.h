#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include <SDL.h>


class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
protected:

	//int m_x;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	//int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};