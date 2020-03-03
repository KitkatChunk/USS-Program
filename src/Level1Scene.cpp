#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

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
	m_pMine->draw();
	m_pBullet->draw();
	m_pEnemy->draw();
	m_pPlayer->draw();
	m_pHealthLabel->draw();
	m_pScoreLabel->draw();
}

void Level1Scene::update()
{
	m_pPlayer->update();
	m_pEnemy->update();
	m_pBullet->respawn(m_pPlayer);
	m_pBullet->update();
	m_pBackground->update();
	m_pMine->update();

	m_pHealthLabel->setText("Health: " + std::to_string(_health));
	//m_pPlane->setVelocity(m_pPlane->getVelocity() * 0.97f);
	
	// plane moving with mouse motion
	//m_pPlane->setPosition(glm::vec2(m_mousePosition.x, m_pPlane->getPosition().y));

	//CollisionManager::AABBCheck(m_pPlane, m_pMine);
	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pMine);
	if(m_pMine->getIsColliding())
	{
		std::cout<<"hit"<< std::endl;
		damage();
	}
}

void Level1Scene::clean()
{
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
				case SDLK_1:
					TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
					break;
				case SDLK_2:
					TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
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
				m_pBullet->fire();
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
	_health = 10;
	
	SDL_Color yellow = { 255, 255, 0, 255 };
	m_pHealthLabel = new Label("Health: ", "Dock51", 26, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.1f, Config::SCREEN_HEIGHT * 0.95f));
	addChild(m_pHealthLabel);

	m_pScoreLabel = new Label("Score", "Dock51", 26, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.6f, Config::SCREEN_HEIGHT * 0.95f));
	addChild(m_pScoreLabel);
	
	m_pPlayer = new Player(); // instantiates Player
	addChild(m_pPlayer);

	m_pBullet = new Bullet();
	addChild(m_pBullet);

	m_pEnemy = new Enemy(); // instantiates Enemy
	addChild(m_pEnemy);

	m_pMine = new Mine(); // instantiates Island
	addChild(m_pMine);

	m_pBackground = new Background(); //instantiates background
	addChild(m_pBackground);
}

void Level1Scene::damage()
{
	_health--;
	death();
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::death()
{
	if(_health <= 0)
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}
}
