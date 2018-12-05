#pragma once
#include "LoaderParams.h"
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	virtual void update();
private:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	int m_currentFrame;
	int m_numFrames;
	int m_animSpeed;
};