#include "Logo.h"
#include "Game.h"

Logo::Logo()
{
	TheTextureManager::Instance()->load("../Assets/textures/logo.jpg",
		"logo", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("logo");
	setWidth(size.x);
	setHeight(size.y);
	
	setIsColliding(false);
	setType(GameObjectType::LOGO);
}

Logo::~Logo()
{
}

void Logo::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("logo", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Logo::update()
{
}

void Logo::clean()
{
}
