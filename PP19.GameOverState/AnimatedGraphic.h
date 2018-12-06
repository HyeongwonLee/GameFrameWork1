#pragma once
#include "LoaderParams.h"
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	virtual void update();

	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
private:

	
	int m_currentFrame;
	int m_numFrames;
	int m_animSpeed;
};