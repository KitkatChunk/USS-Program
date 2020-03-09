#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
{
	TheTextureManager::Instance()->load("../Assets/textures/alien.png",
		"enemy", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(getWidth() * 0.5,getHeight()));
	setVelocity(glm::vec2(3,0));
	setIsColliding(false);
	setType(GameObjectType::ENEMY);
	TheSoundManager::Instance()->load("../Assets/audio/destruction.wav", "hit", SOUND_SFX);
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("enemy", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void Enemy::update()
{
	_move();
	_checkBounds();
}

void Enemy::clean()
{
}

void Enemy::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Enemy::_checkBounds()
{
	//right boundary
	if (getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f) 
	{
		setVelocity(glm::vec2(-2.0f, 0.0f));
	}

	//left boundary
	if (getPosition().x <= getWidth() * 0.5) 
	{
		setVelocity(glm::vec2(2.0f, 0.0f));
	}
}
