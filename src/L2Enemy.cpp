#include "L2Enemy.h"
#include "Game.h"

L2Enemy::L2Enemy()
{
	TheTextureManager::Instance()->load("../Assets/textures/alien.png",
		"enemy", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(rand() % (Config::SCREEN_WIDTH - getWidth()) + 1,getHeight()*2));
	setVelocity(glm::vec2(0,4));
	setIsColliding(false);
	setType(GameObjectType::ENEMY);
	TheSoundManager::Instance()->load("../Assets/audio/destruction.wav", "hit", SOUND_SFX);
	m_prng = rand() % 10;
}

L2Enemy::~L2Enemy()
{
}

void L2Enemy::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("enemy", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void L2Enemy::update()
{
	_checkBounds();
	_move();
}

void L2Enemy::clean()
{
}

void L2Enemy::_move()
{
	if(getPosition().y >= Config::SCREEN_HEIGHT * 0.3f)
	{
		if(getPosition().x < Config::SCREEN_WIDTH - getWidth() * 0.5f)
		{
			if(getPosition().x > getWidth() * 0.5)
			{
				if(m_prng >= 9)
					setVelocity(glm::vec2(-4,0));
				if(m_prng <= 4)
					setVelocity(glm::vec2(4,0));
			}
		}
	}
	
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void L2Enemy::_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight()) {
		_reset();
	}

	if(getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f)
	{
		setVelocity(glm::vec2(0.0f, 4.0f));
	}

	//left boundary
	if (getPosition().x <= getWidth() * 0.5) 
	{
		setVelocity(glm::vec2(0.0f, 4.0f));
	}
}

void L2Enemy::_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (Config::SCREEN_WIDTH - getWidth()) + halfWidth + 1;
	int yComponent = -(rand() % (Config::SCREEN_HEIGHT - 300) + (getHeight()*2));
	
	setPosition(glm::vec2(xComponent, yComponent));
	m_prng = rand() % 10;
}
