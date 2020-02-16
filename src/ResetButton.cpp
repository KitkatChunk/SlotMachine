#include "ResetButton.h"
#include "Game.h"

ResetButton::ResetButton()
// call super constructor
	:Button(
		"../Assets/textures/StartButton.png",
		"BetButton",
		RESET_BUTTON, glm::vec2(360.0f, 200.0f)), m_isClicked(false)
{

}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{

	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Reset" << std::endl;
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