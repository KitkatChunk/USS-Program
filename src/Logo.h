#pragma once
#ifndef __LOGO__
#define __LOGO__
#include "DisplayObject.h"

class Logo : public DisplayObject
{
	public:
	Logo();
	~Logo();
	
	void draw() override;
	void update() override;
	void clean() override;
};
#endif /* defined (__LOGO__) */
