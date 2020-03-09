#include "Mine.h"
#include "Game.h"

Mine::Mine()
{
	TheTextureManager::Instance()->load("../Assets/textures/hazard.png",
		"hazard", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("hazard");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0, 5));
	
	_reset();
	//setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 400.0f));
	setIsColliding(false);
	setType(GameObjectType::HAZARD);
	//setVelocity(glm::vec2(0.0f, 0.0f));

	TheSoundManager::Instance()->load("../Assets/audio/explosion.mp3", "explosion", SOUND_SFX);
}

Mine::~Mine()
{
}

void Mine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("hazard", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Mine::update()
{
	_move();
	_checkBounds();
}

void Mine::clean()
{
}

void Mine::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Mine::_checkBounds()
{
	if (getPosition().y > 480 + getHeight()) {
		_reset();
	}
}

void Mine::_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
}
