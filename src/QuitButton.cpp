#include "QuitButton.h"
#include "Game.h"

QuitButton::QuitButton()
	// call super constructor
	:Button(
		"../Assets/textures/QuitButton.png",
		"quitButton",
		QUIT_BUTTON, glm::vec2(200.0f, 300.0f)), m_isClicked(false)
{
}

QuitButton::~QuitButton()
{
}

bool QuitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			TheGame::Instance()->quit();
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
