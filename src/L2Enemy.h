#pragma once
#ifndef __L2ENEMY__
#define __L2ENEMY__

#include "DisplayObject.h"

class L2Enemy : public DisplayObject
{
	public:
	L2Enemy();
	~L2Enemy();
	
	//GameObject Life Cycle
	void draw() override;
	void update() override;
	void clean() override;
	void _reset();

	private:
	int m_prng;
	void _move();
	void _checkBounds();
};
#endif /* defined (__L2ENEMY__)*/
