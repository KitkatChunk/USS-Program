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

	int _health;
	int _score;

	private:
	// game objects
	Background* m_pBackground;
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Hazard* m_pHazard;
	Bullet* m_pBullet;
	Label* m_pHealthLabel;
	Label* m_pScoreLabel;

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__LEVEL_1_SCENE__) */
