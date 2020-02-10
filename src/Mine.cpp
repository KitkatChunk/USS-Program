#include "Mine.h"
#include "Game.h"

Mine::Mine()
{
	TheTextureManager::Instance()->load("../Assets/textures/mine.png",
		"mine", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("mine");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::MINE);
	//setVelocity(glm::vec2(0.0f, 0.0f));

	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);

}

Mine::~Mine()
{
}

void Mine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("mine", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Mine::update()
{
}

void Mine::clean()
{
}
