#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Hazard.h"
#include "Enemy.h"
#include "Background.h"
#include "Label.h"
#include "Bullet.h"
#include "Config.h"

class Level1Scene : public Scene
{
	public:
	Level1Scene();
	~Level1Scene();
	
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

	// game objects
	Background* m_pBackground;
	Player* m_pPlayer;
	Hazard* m_pHazard;
	
	int m_enemyNum = Config::NUM_OF_ENEMIES;
	std::vector<Enemy*> m_pEnemies;
	void m_buildEnemies();
	//Enemy* m_pEnemy;

	int m_bulletNum = Config::NUM_OF_BULLETS;
	std::vector<Bullet*> m_pBullets;
	void m_buildBullets();

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__LEVEL_1_SCENE__) */
