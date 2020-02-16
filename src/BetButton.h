#pragma once
#ifndef __Bet_BUTTON__
#define __Bet_BUTTON__

#include "Button.h"

class BetButton : public Button
{
public:
	BetButton();
	~BetButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__Bet_BUTTON__) */