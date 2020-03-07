#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_EndLabel->draw();
	m_pResetButton->draw();
	m_pQuitButton->draw();
}

void EndScene::update()
{
	m_pResetButton->setMousePosition(m_mousePosition);
	m_pResetButton->ButtonClick();

	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();
}

void EndScene::clean()
{
	removeAllChildren();
}

void EndScene::handleEvents()
{
	SDL_Event event;
	
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;

			case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pResetButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				break;
			}
			break;
			
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pResetButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				break;
			}
			break;
			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
				
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
				
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
			
		default:
			break;
		}
	}
}

void EndScene::start()
{
	SDL_Color red = { 255, 0, 0, 255 };
	m_EndLabel = new Label("GAME OVER", "Dock51", 80, red, glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_EndLabel->setParent(this);
	addChild(m_EndLabel);

	m_pResetButton = new ResetButton();
	m_pResetButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pResetButton);

	m_pQuitButton = new QuitButton();
	m_pQuitButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.7f));
	addChild(m_pQuitButton);
}

glm::vec2 EndScene::getMousePosition()
{
	return m_mousePosition;
}