#pragma once
#ifndef __SHOT__
#define __SHOT__
#include "DisplayObject.h"
#include "L2Enemy.h"

class Shot : public DisplayObject
{
	public:
	Shot();
	~Shot();
	
	void draw() override;
	void update() override;
	void clean() override;
	void fire();
	void respawn(L2Enemy* enemy);
	bool m_pisFiring = false;

	private:
	//bool m_pisFiring;
	glm::vec2 spawnPoint;
	void _move();
	void _checkBounds();
	void _reset();
};
#endif /* defined (__SHOT__) */
