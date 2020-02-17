#include "BetButton.h"
#include "Game.h"

BetButton::BetButton()
// call super constructor
	:Button(
		"../Assets/textures/BetButton.png",
		"BetButton",
		BET_BUTTON, glm::vec2(525.0f, 550.0f)), m_isClicked(false)
{

}

BetButton::~BetButton()
{
}

bool BetButton::ButtonClick()
{

	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Bet" << std::endl;
			
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}