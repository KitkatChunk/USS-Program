#include "Shot.h"
#include "Game.h"

Shot::Shot()
{
	TheTextureManager::Instance()->load("../Assets/textures/shot.png",
		"shot", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bullet");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 400.0f));
	setVelocity(glm::vec2(0, 0));
	_reset();
	setIsColliding(false);
	setType(GameObjectType::BULLET);
	TheSoundManager::Instance()->load("../Assets/audio/laser.wav", "fire", SOUND_SFX);
}

Shot::~Shot()
{
}

void Shot::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("shot", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Shot::update()
{
	_move();
	_checkBounds();
	
	if(!m_pisFiring)
	{
		setPosition(spawnPoint);
	}
}

void Shot::clean()
{
}

void Shot::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Shot::_checkBounds()
{
	if (getPosition().y >= Config::SCREEN_HEIGHT) 
	{
		m_pisFiring=false;
		_reset();
	}
}

void Shot::_reset()
{
	setVelocity(glm::vec2(0,0));
}

void Shot::fire()
{
	m_pisFiring= true;
	setVelocity(glm::vec2(0, 5));
	
	if(getPosition() == spawnPoint)
		TheSoundManager::Instance()->playSound("fire", 0);
}

void Shot::respawn(L2Enemy* enemy)
{
	spawnPoint= enemy->getPosition();
}
