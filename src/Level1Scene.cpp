#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "ScoreBoardManager.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBackground->draw();
	m_pHazard->draw();
	
	for (auto bullet : m_pBullets)
	{
		bullet->draw();
	}

	for(auto enemy : m_pEnemies)
	{
		enemy->draw();
	}
	
	m_pPlayer->draw();
	ScoreBoardManager::Instance()->Draw();
}

void Level1Scene::update()
{
	for (auto bullet : m_pBullets)
	{
		bullet->respawn(m_pPlayer);
		bullet->update();

		for(auto enemy : m_pEnemies)
		{
			if(CollisionManager::squaredRadiusCheck(bullet, enemy))
			{
				ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 100);
				enemy->_reset();
				bullet->m_pisFiring = false;
			}
		}
	}

	for(auto enemy : m_pEnemies)
	{
		enemy->update();
		if(CollisionManager::squaredRadiusCheck(enemy,m_pPlayer))
		{
			enemy->_reset();
		}
	}
	
	shotCount++;
	
	m_pPlayer->update();
	m_pBackground->update();
	m_pHazard->update();

	if(CollisionManager::squaredRadiusCheck(m_pHazard, m_pPlayer))
	{
		m_pHazard->_reset();
	}

	if(ScoreBoardManager::Instance()->getScore() >= 1000)
	{
		TheGame::Instance()->changeSceneState(SceneState::LEVEL2_SCENE);
	}
}

void Level1Scene::clean()
{
	//removeAllChildren();
}

void Level1Scene::handleEvents()
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
				
				case SDLK_0:
					TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
					break;
				case SDLK_8:
					TheGame::Instance()->changeSceneState(SceneState::WIN_SCENE);
					break;
				
				case SDLK_1:
					TheGame::Instance()->changeSceneState(SceneState::LEVEL2_SCENE);
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

void Level1Scene::start()
{
	m_pPlayer = new Player(); // instantiates Player
	addChild(m_pPlayer);

	m_buildBullets();
	m_buildEnemies();

	m_pHazard = new Hazard(); // instantiates Island
	addChild(m_pHazard);

	m_pBackground = new Background(); //instantiates background
	addChild(m_pBackground);

	ScoreBoardManager::Instance()->Start();
	ScoreBoardManager::Instance()->getLives();
	ScoreBoardManager::Instance()->getScore();
	//m_pBackground->setBackground("space.png");
}

//void Level1Scene::damage()
//{
//	ScoreBoardManager::Instance()->setLives(ScoreBoardManager::Instance()->getLives() - 1);
//	
//	if(ScoreBoardManager::Instance()->getLives() <= 0)
//	{
//		Game::Instance()->changeSceneState(END_SCENE);
//	}
//}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::m_buildEnemies()
{
	for (auto i = 0; i < m_enemyNum; ++i)
	{
		auto enemy = new Enemy();
		m_pEnemies.push_back(enemy);
		addChild(enemy);
	}
}

void Level1Scene::m_buildBullets()
{
	for (auto i = 0; i < m_bulletNum; ++i)
	{
		auto bullet = new Bullet();
		m_pBullets.push_back(bullet);
		addChild(bullet);
	}
}
