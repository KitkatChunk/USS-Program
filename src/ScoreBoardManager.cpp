#include <iostream>
#include "ScoreBoardManager.h"
#include "Game.h"

ScoreBoardManager* ScoreBoardManager::m_pInstance = nullptr;

void ScoreBoardManager::Start()
{
	const SDL_Color yellow = { 255, 255, 0, 255 };
	m_pHealthLabel = new Label("Health: 5", "Consolas", 26, yellow,
		glm::vec2(Config::SCREEN_WIDTH * 0.2f, Config::SCREEN_HEIGHT * 0.95f));

	m_pScoreLabel = new Label("Score: 0", "Consolas", 26, yellow,
		glm::vec2(Config::SCREEN_WIDTH * 0.7f, Config::SCREEN_HEIGHT * 0.95f));
}

void ScoreBoardManager::Draw() const
{
	m_pHealthLabel->draw();
	m_pScoreLabel->draw();
}

int ScoreBoardManager::getScore()
{
	return m_score;
}

void ScoreBoardManager::setScore(const int newScore)
{
	m_score = newScore;
	m_pScoreLabel->setText("Score: " + std::to_string(m_score));
}

int ScoreBoardManager::getLives()
{
	return m_lives;
}

void ScoreBoardManager::setLives(const int newLives)
{
	m_lives = newLives;
	if(m_lives < 1)
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}
	m_pHealthLabel->setText("Health: " + std::to_string(m_lives));
}

ScoreBoardManager::ScoreBoardManager()
{
	Start();
	setScore(Config::SCORE);
	setLives(Config::LIVES);
}

ScoreBoardManager::~ScoreBoardManager()
= default;
