#include "Background.h"
#include "Game.h"

Background::Background()
{
	TheTextureManager::Instance()->load("../Assets/textures/background.png",
		"background", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("background");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(0, 5));
	_reset();
	setIsColliding(false);
	setType(GameObjectType::BACKGROUND);
}

Background::~Background()
{
}

void Background::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("background", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Background::update()
{
	_move();
	_checkBounds();
}

void Background::clean()
{
}

void Background::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Background::_checkBounds()
{
	if (getPosition().y >= 0) 
	{
		_reset();
	}
}

void Background::_reset()
{
	//For ocean
	//setPosition(glm::vec2(0, -960));

	setPosition(glm::vec2(0, -200));
}
