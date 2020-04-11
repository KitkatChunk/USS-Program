#pragma once
#include "Config.h"
#include "Label.h"
#ifndef __SCORE_BOARD_MANAGER__
#define __SCORE_BOARD_MANAGER__
class ScoreBoardManager
{
public:
	static ScoreBoardManager* Instance()
	{
		if(m_pInstance == nullptr)
		{
			m_pInstance = new ScoreBoardManager();
			return m_pInstance;
		}
		return m_pInstance;
	}

	void Start();
	void Draw() const;

	int getScore();
	void setScore(int newScore);
	
	int getLives();
	void setLives(int newLives);
	
private:
	ScoreBoardManager();
	~ScoreBoardManager();

	int m_score{};
	int m_lives{};

	Label* m_pHealthLabel{};
	Label* m_pScoreLabel{};
	
	static ScoreBoardManager* m_pInstance;
};
#endif
/* defined (__SCORE_BOARD_MANAGER__) */