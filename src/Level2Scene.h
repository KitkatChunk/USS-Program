#pragma once
#ifndef __LEVEL_2_SCENE__
#define __LEVEL_2_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Hazard.h"
#include "Background.h"
#include "Label.h"
#include "Bullet.h"
#include "Config.h"
#include "L2Enemy.h"
#include "Shot.h"

class Level2Scene : public Scene
{
	public:
	Level2Scene();
	~Level2Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	void damage();

	// getters
	glm::vec2 getMousePosition();

	private:
	int shotCount;

	int m_bulletNum = Config::NUM_OF_BULLETS;
	std::vector<Bullet*> m_pBullets;
	void m_buildBullets();
	
	Background* m_pBackground;
	Player* m_pPlayer;
	L2Enemy* m_pEnemy;
	Shot* m_pShot;
	Hazard* m_pHazard;

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__LEVEL_2_SCENE__) */
