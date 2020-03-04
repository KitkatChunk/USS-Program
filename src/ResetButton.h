#pragma once
#ifndef __RESET_BUTTON__
#define __RESET_BUTTON__

#include "Button.h"

class ResetButton : public Button
{
public:
	ResetButton();
	~ResetButton();

	bool ButtonClick() override;
	
private:
	bool m_isClicked;
};

#endif /* defined (__RESET_BUTTON__) */