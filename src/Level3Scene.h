#pragma once
#ifndef __LEVEL_3_SCENE__
#define __LEVEL_3_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Hazard.h"
#include "Enemy.h"
#include "Background.h"
#include "Label.h"
#include "Bullet.h"
#include "Config.h"

class Level3Scene : public Scene
{
	public:
	Level3Scene();
	~Level3Scene();
	
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
	Enemy* m_pEnemy;
	Hazard* m_pHazard;

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__LEVEL_3_SCENE__) */
