#include "ResetButton.h"
#include "Game.h"


ResetButton::ResetButton()
// call super constructor
	:Button(
		"../Assets/textures/ResetButton.png",
		"ResetButton",
		RESET_BUTTON, glm::vec2(350.0f, 575.0f)), m_isClicked(false)
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
			// Game::resetAll();
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
