#include "Bullet.h"
#include "Game.h"

Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/textures/tile.png",
		"bullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bullet");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 400.0f));
	setVelocity(glm::vec2(0, 0));
	_reset();
	setIsColliding(false);
	setType(GameObjectType::BULLET);
	TheSoundManager::Instance()->load("../Assets/audio/thunder.ogg", "hit", SOUND_SFX);
	TheSoundManager::Instance()->load("../Assets/audio/laser.ogg", "spawn", SOUND_SFX);
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("bullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Bullet::update()
{
	_move();
	_checkBounds();
	//setPosition(spawnPoint);
	if(!m_pisFiring)
	{
		setPosition(spawnPoint);
	}
}

void Bullet::clean()
{
}

void Bullet::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Bullet::_checkBounds()
{
	if (getPosition().y <= 0) 
	{
		m_pisFiring=false;
		_reset();
	}
}

void Bullet::_reset()
{
	//setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 400.0f));
	//setPosition(spawnPoint);
	setVelocity(glm::vec2(0,0));
}

void Bullet::fire()
{
	setVelocity(glm::vec2(0, -5));
	m_pisFiring= true;
}

void Bullet::respawn(Player* player)
{
	spawnPoint= player->getPosition();
}
