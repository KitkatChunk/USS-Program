#pragma once
#ifndef __HAZARD__
#define __HAZARD__
#include "DisplayObject.h"

class Hazard : public DisplayObject
{
	public:
	Hazard();
	~Hazard();
	
	void draw() override;
	void update() override;
	void clean() override;
	void _reset();

	private:
	void _move();
	void _checkBounds();
};
#endif /* defined (__HAZARD__) */
