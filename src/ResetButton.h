#pragma once
#ifndef __Reset_BUTTON__
#define __Reset_BUTTON__

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

#endif /* defined (__Reset_BUTTON__) */