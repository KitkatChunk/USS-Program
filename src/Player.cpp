#include "Player.h"
#include "Game.h"

Player::Player() :m_maxSpeed(10.0f), m_isMoving(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/spaceship.png",
		"player", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 435.0f));
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	setVelocity(glm::vec2(0.0f, 0.0f));
}

Player::~Player()
{
}

void Player::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("player", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Player::update()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	if(!m_isMoving)
	{
		setVelocity(glm::vec2(Util::lerp(currentVelocity.x, 0.0f, 0.02f), currentVelocity.y));
	}
	
	auto deltax = currentPosition.x + currentVelocity.x;
	setPosition(glm::vec2(deltax, currentPosition.y));

	m_checkBounds();
}

void Player::clean()
{
}

void Player::move(Move newMove)
{
	auto currentVelocity = getVelocity();
	
	switch(newMove)
	{
	case RIGHT:
		setVelocity(glm::vec2(1.0f * m_maxSpeed, 0.0f));
		break;
	case LEFT:
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, 0.0f));
		break;
	}
}

bool Player::getIsMoving()
{
	return m_isMoving;
}

void Player::setIsMoving(bool newState)
{
	m_isMoving = newState;
}

void Player::m_checkBounds()
{
	// check right bounds
	if(getPosition().x >= Config::SCREEN_WIDTH - getWidth() * 0.5f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH - getWidth() * 0.5f, getPosition().y));
	}

	// check left bounds
	if (getPosition().x <=  getWidth() * 0.5f)
	{
		setPosition(glm::vec2(getWidth() * 0.5f, getPosition().y));
	}
}