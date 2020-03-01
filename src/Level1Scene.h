#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Mine.h"
#include "Enemy.h"
#include "Background.h"
#include "Label.h"

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

	private:
	// game objects
	Label* m_pHealthLabel;
	Label* m_pScoreLabel;
	Background* m_pBackground;
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Mine* m_pMine;

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__LEVEL_1_SCENE__) */
