#pragma once
#ifndef __ENEMY__
#define __ENEMY__

#include "DisplayObject.h"

class Enemy : public DisplayObject
{
	public:
	Enemy();
	~Enemy();
	
	//GameObject Life Cycle
	void draw() override;
	void update() override;
	void clean() override;
	void _reset();

	private:
	void _move();
	void _checkBounds();
};
#endif /* defined (__ENEMY__)*/
