#include "Hazard.h"
#include "Game.h"

Hazard::Hazard()
{
	TheTextureManager::Instance()->load("../Assets/textures/hazard.png",
		"hazard", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("hazard");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0.0f, 5.0f));
	
	_reset();
	setIsColliding(false);
	setType(GameObjectType::HAZARD);

	TheSoundManager::Instance()->load("../Assets/audio/explosion.mp3", "explosion", SOUND_SFX);
}

Hazard::~Hazard()
{
}

void Hazard::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("hazard", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Hazard::update()
{
	_move();
	_checkBounds();
}

void Hazard::clean()
{
}

void Hazard::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Hazard::_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT + getHeight()) {
		_reset();
	}
}

void Hazard::_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (Config::SCREEN_WIDTH - getWidth()) + halfWidth + 1;
	int yComponent = rand() % (-Config::SCREEN_HEIGHT + 380) - getHeight();

	float yVelocity = rand() % 3 + 3;
	setVelocity(glm::vec2(0, yVelocity));
	
	setPosition(glm::vec2(xComponent, yComponent));
}
