#include "Level2Scene.h"
#include "Game.h"
#include <iostream>
#include "ScoreBoardManager.h"

Level2Scene::Level2Scene()
{
	start();
}

Level2Scene::~Level2Scene()
{
}

void Level2Scene::draw()
{
	m_pBackground->draw();
	m_pHazard->draw();
	
	for (auto bullet : m_pBullets)
	{
		bullet->draw();
	}

	m_pShot->draw();
	m_pEnemy->draw();
	m_pPlayer->draw();
	ScoreBoardManager::Instance()->Draw();
}

void Level2Scene::update()
{
	for (auto bullet : m_pBullets)
	{
		bullet->respawn(m_pPlayer);
		bullet->update();
		
		if(CollisionManager::squaredRadiusCheck(bullet, m_pEnemy))
		{
			ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 100);
			m_pEnemy->_reset();
			bullet->m_pisFiring = false;
		}
	}
	
	shotCount++;
	
	m_pPlayer->update();
	m_pEnemy->update();
	m_pShot->respawn(m_pEnemy);
	m_pShot->update();
	m_pBackground->update();
	m_pHazard->update();

	if(CollisionManager::squaredRadiusCheck(m_pHazard, m_pPlayer))
	{
		m_pHazard->_reset();
	}

	if(CollisionManager::squaredRadiusCheck(m_pEnemy,m_pPlayer))
	{
		m_pEnemy->_reset();
	}

	if(m_pEnemy->getPosition().x - m_pPlayer->getPosition().x == 0)
	{
		m_pShot->fire();
	}

	if(CollisionManager::squaredRadiusCheck(m_pShot, m_pPlayer))
	{
		m_pShot->m_pisFiring = false;
	}
	
	if(ScoreBoardManager::Instance()->getScore() >= 2000)
	{
		TheGame::Instance()->changeSceneState(SceneState::LEVEL3_SCENE);
	}
}

void Level2Scene::clean()
{
}

void Level2Scene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	
	while(SDL_PollEvent(&event))
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
			switch(event.button.button)
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
			
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					TheGame::Instance()->quit();
					break;
				
				case SDLK_9:
					TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
					break;
				case SDLK_0:
					TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
					break;
				case SDLK_8:
					TheGame::Instance()->changeSceneState(SceneState::WIN_SCENE);
					break;
				
				case SDLK_1:
					TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
					break;
				case SDLK_2:
					TheGame::Instance()->changeSceneState(SceneState::LEVEL3_SCENE);
					break;
			
				//Movement Controls
				case SDLK_a:
					m_pPlayer->move(LEFT);
					break;
				case SDLK_d:
					m_pPlayer->move(RIGHT);
					break;
				
				case SDLK_LEFT:
					m_pPlayer->move(LEFT);
					break;
				case SDLK_RIGHT:
					m_pPlayer->move(RIGHT);
					break;

				case SDLK_SPACE:
					if(shotCount > 0 && m_pBullets[0]->m_pisFiring == false)
					{
						m_pBullets[0]->fire();
						shotCount = 0;
					}
					
					if(shotCount > 1 && m_pBullets[1]->m_pisFiring == false)
					{
						m_pBullets[1]->fire();
						shotCount = 0;
					}

					if(shotCount > 1 && m_pBullets[2]->m_pisFiring == false)
					{
						m_pBullets[2]->fire();
						shotCount = 0;
					}

					if(shotCount > 1 && m_pBullets[3]->m_pisFiring == false)
					{
						m_pBullets[3]->fire();
						shotCount = 0;
					}

					if(shotCount > 1 && m_pBullets[4]->m_pisFiring == false)
					{
						m_pBullets[4]->fire();
						shotCount = 0;
					}
					break;
			}
			break;
			
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
				case SDLK_w:
					break;
				case SDLK_s:
					break;

				case SDLK_a:
					m_pPlayer->setIsMoving(false);
					break;
				case SDLK_d:
					m_pPlayer->setIsMoving(false);
					break;
				
				case SDLK_LEFT:
					m_pPlayer->setIsMoving(false);
					break;
				case SDLK_RIGHT:
					m_pPlayer->setIsMoving(false);
					break;
				
				case SDLK_SPACE:
					break;
			}
			break;
			
		default:
			break;
		}
	}
}

void Level2Scene::start()
{
	m_pPlayer = new Player(); // instantiates Player
	addChild(m_pPlayer);

	m_buildBullets();

	m_pEnemy = new L2Enemy(); // instantiates Enemy
	addChild(m_pEnemy);

	m_pShot = new Shot();
	addChild(m_pShot);

	m_pHazard = new Hazard(); // instantiates Island
	addChild(m_pHazard);

	m_pBackground = new Background(); //instantiates background
	addChild(m_pBackground);
	
	ScoreBoardManager::Instance()->Start();
	ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore());
	ScoreBoardManager::Instance()->setLives(ScoreBoardManager::Instance()->getLives());
	//m_pBackground->setBackground("space.png");
}

//void Level2Scene::damage()
//{
//	ScoreBoardManager::Instance()->setLives(ScoreBoardManager::Instance()->getLives() - 1);
//	
//	if(ScoreBoardManager::Instance()->getLives() <= 0)
//	{
//		Game::Instance()->changeSceneState(END_SCENE);
//	}
//}

glm::vec2 Level2Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level2Scene::m_buildBullets()
{
	for (auto i = 0; i < m_bulletNum; ++i)
	{
		auto bullet = new Bullet();
		m_pBullets.push_back(bullet);
		addChild(bullet);
	}
}
