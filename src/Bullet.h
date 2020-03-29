#pragma once
#ifndef __BULLET__
#define __BULLET__
#include "DisplayObject.h"
#include "Player.h"

class Bullet : public DisplayObject
{
	public:
	Bullet();
	~Bullet();
	
	void draw() override;
	void update() override;
	void clean() override;
	void fire();
	void respawn(Player* player);
	bool m_pisFiring;

	private:
	//bool m_pisFiring;
	glm::vec2 spawnPoint;
	void _move();
	void _checkBounds();
	void _reset();
};
#endif /* defined (__BULLET__) */
