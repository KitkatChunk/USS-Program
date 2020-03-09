#include "SplashScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

SplashScene::SplashScene()
{
	SplashScene::start();
}

SplashScene::~SplashScene()
{
}

void SplashScene::draw()
{
	m_pLogo->draw();
}

void SplashScene::update()
{
	count++;
	seconds = float(count)/60;
	transition();
}

void SplashScene::clean()
{
	removeAllChildren();
}

void SplashScene::handleEvents()
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
				break;
			}
			break;
			
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
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

void SplashScene::start()
{
	count=0;
	seconds = 0;

	m_pLogo = new Logo();
	m_pLogo->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pLogo);
}

glm::vec2 SplashScene::getMousePosition()
{
	return m_mousePosition;
}

void SplashScene::transition()
{
	if(count%60 == 0)
		std::cout<<seconds<< std::endl;
	
	if(seconds == 3)
	{
		TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
	}
}
