#include "ScoreBoardManager.h"

ScoreBoardManager* ScoreBoardManager::m_pInstance = nullptr;

void ScoreBoardManager::Start()
{
	SDL_Color yellow = { 255, 255, 0, 255 };
	m_pHealthLabel = new Label("Health: ", "Dock51", 26, yellow,
		glm::vec2(Config::SCREEN_WIDTH * 0.1f, Config::SCREEN_HEIGHT * 0.95f));

	m_pScoreLabel = new Label("Score", "Dock51", 26, yellow,
		glm::vec2(Config::SCREEN_WIDTH * 0.6f, Config::SCREEN_HEIGHT * 0.95f));

}

void ScoreBoardManager::Draw()
{
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
	m_pHealthLabel->setText("Lives: " + std::to_string(m_lives));
}

ScoreBoardManager::ScoreBoardManager()
{
	Start();
	setScore(Config::SCORE);
	setLives(Config::LIVES);
}

ScoreBoardManager::~ScoreBoardManager()
= default;
