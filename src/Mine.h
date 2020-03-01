#pragma once
#ifndef __MINE__
#define __MINE__
#include "DisplayObject.h"

class Mine : public DisplayObject
{
	public:
	Mine();
	~Mine();
	
	void draw() override;
	void update() override;
	void clean() override;

	private:
	void _move();
	void _checkBounds();
	void _reset();
};
#endif /* defined (__MINE__) */
