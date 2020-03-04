#include "ResetButton.h"
#include "Game.h"

ResetButton::ResetButton()
	// call super constructor
	:Button(
		"../Assets/textures/ResetButton.png",
		"resetButton",
		RESET_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	
}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			Game::Instance()->changeSceneState(START_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
