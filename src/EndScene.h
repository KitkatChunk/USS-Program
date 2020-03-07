#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ResetButton.h"
#include "QuitButton.h"

class EndScene : public Scene
{
	public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	glm::vec2 getMousePosition();

	private:
	Label* m_EndLabel;
	ResetButton* m_pResetButton;
	QuitButton* m_pQuitButton;

	glm::vec2 m_mousePosition;
};
#endif /* defined (__END_SCENE__) */
