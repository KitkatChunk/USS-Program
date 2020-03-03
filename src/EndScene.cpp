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
}

void EndScene::update()
{
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
}
