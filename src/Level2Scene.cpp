#include "Level2Scene.h"
#include "Game.h"
#include <iostream>

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
	m_pBullet1->draw();
	m_pBullet2->draw();
	m_pBullet3->draw();
	m_pBullet4->draw();
	m_pBullet5->draw();
	m_pEnemy->draw();
	m_pPlayer->draw();
	m_pHealthLabel->draw();
	m_pScoreLabel->draw();
}

void Level2Scene::update()
{
	shotCount1++;
	shotCount2++;
	shotCount3++;
	shotCount4++;
	shotCount5++;
	
	m_pPlayer->update();
	m_pEnemy->update();
	m_pBullet1->respawn(m_pPlayer);
	m_pBullet1->update();
	m_pBullet2->respawn(m_pPlayer);
	m_pBullet2->update();
	m_pBullet3->respawn(m_pPlayer);
	m_pBullet3->update();
	m_pBullet4->respawn(m_pPlayer);
	m_pBullet4->update();
	m_pBullet5->respawn(m_pPlayer);
	m_pBullet5->update();
	m_pBackground->update();
	m_pHazard->update();

	m_pHealthLabel->setText("Health: " + std::to_string(_health));
	m_pScoreLabel->setText("Score: " + std::to_string(_score));

	if(CollisionManager::squaredRadiusCheck(m_pPlayer, m_pHazard))
	{
		damage();
	}

	if(CollisionManager::squaredRadiusCheck(m_pBullet1, m_pEnemy))
	{
		_score= _score + 100;
		m_pBullet1->m_pisFiring = false;
	}

	if(CollisionManager::squaredRadiusCheck(m_pBullet2, m_pEnemy))
	{
		_score= _score + 100;
		m_pBullet2->m_pisFiring = false;
	}

	if(CollisionManager::squaredRadiusCheck(m_pBullet3, m_pEnemy))
	{
		_score= _score + 100;
		m_pBullet3->m_pisFiring = false;
	}

	if(CollisionManager::squaredRadiusCheck(m_pBullet4, m_pEnemy))
	{
		_score= _score + 100;
		m_pBullet4->m_pisFiring = false;
	}

	if(CollisionManager::squaredRadiusCheck(m_pBullet5, m_pEnemy))
	{
		_score= _score + 100;
		m_pBullet5->m_pisFiring = false;
	}

	if(_score >= 2000)
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
					if(shotCount1 >= 50)
					{
						m_pBullet1->fire();
					}
					
					if(shotCount2 >= 70 && m_pBullet1->getPosition() != m_pPlayer->getPosition())
					{
						m_pBullet2->fire();
						shotCount2 = 0;
					}

					if(shotCount3 >= 90 && m_pBullet2->getPosition() != m_pPlayer->getPosition())
					{
						m_pBullet3->fire();
						shotCount3 = 0;
					}

					if(shotCount4 >= 110 && m_pBullet3->getPosition() != m_pPlayer->getPosition())
					{
						m_pBullet4->fire();
						shotCount4 = 0;
					}

					if(shotCount5 >= 130 && m_pBullet4->getPosition() != m_pPlayer->getPosition())
					{
						m_pBullet5->fire();
						shotCount5 = 0;
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
	shotCount1 = 50;
	shotCount2 = 60;
	shotCount3 = 75;
	shotCount4 = 95;
	shotCount5 = 110;
	_health = 5;
	
	SDL_Color yellow = { 255, 255, 0, 255 };
	m_pHealthLabel = new Label("Health: ", "Dock51", 26, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.1f, Config::SCREEN_HEIGHT * 0.95f));
	addChild(m_pHealthLabel);

	m_pScoreLabel = new Label("Score", "Dock51", 26, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.6f, Config::SCREEN_HEIGHT * 0.95f));
	addChild(m_pScoreLabel);
	
	m_pPlayer = new Player(); // instantiates Player
	addChild(m_pPlayer);

	m_pBullet1 = new Bullet();
	addChild(m_pBullet1);
	m_pBullet2 = new Bullet();
	addChild(m_pBullet2);
	m_pBullet3 = new Bullet();
	addChild(m_pBullet3);
	m_pBullet4 = new Bullet();
	addChild(m_pBullet4);
	m_pBullet5 = new Bullet();
	addChild(m_pBullet5);

	m_pEnemy = new Enemy(); // instantiates Enemy
	addChild(m_pEnemy);

	m_pHazard = new Hazard(); // instantiates Island
	addChild(m_pHazard);

	m_pBackground = new Background(); //instantiates background
	addChild(m_pBackground);
	//m_pBackground->setBackground("space.png");
}

void Level2Scene::damage()
{
	_health--;
	
	if(_health <= 0)
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}
}

glm::vec2 Level2Scene::getMousePosition()
{
	return m_mousePosition;
}
