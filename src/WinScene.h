#pragma once
#ifndef __WIN_SCENE__
#define __WIN_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ResetButton.h"
#include "QuitButton.h"

class WinScene : public Scene
{
	public:
	WinScene();
	~WinScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	glm::vec2 getMousePosition();

	private:
	Label* m_WinLabel;
	ResetButton* m_pResetButton;
	QuitButton* m_pQuitButton;

	glm::vec2 m_mousePosition;
};
#endif /* defined (__WIN_SCENE__) */
