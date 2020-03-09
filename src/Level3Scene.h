#pragma once
#ifndef __LEVEL_3_SCENE__
#define __LEVEL_3_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Mine.h"
#include "Enemy.h"
#include "Background.h"
#include "Label.h"
#include "Bullet.h"

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

	int _health;
	int _score;

	private:
	// game objects
	Label* m_pHealthLabel;
	Label* m_pScoreLabel;
	Background* m_pBackground;
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Mine* m_pHazard;
	Bullet* m_pBullet;

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__LEVEL_3_SCENE__) */