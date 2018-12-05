#include "SDLGameObject.h"

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};


class MenuButton : public SDLGameObject
{
private:
	void(*m_callback)();

	bool m_bReleased;


public:
	MenuButton(const LoaderParams* pParams, void(*callback)());
	MenuButton(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};