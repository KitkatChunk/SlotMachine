#include "QuitButton.h"
#include "Game.h"

QuitButton::QuitButton()
// call super constructor
	:Button(
		"../Assets/textures/StartButton.png",
		"QuitButton",
		START_BUTTON, glm::vec2(100.0f, 300.0f)), m_isClicked(false)
{

}

QuitButton::~QuitButton()
{
}

bool QuitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Quit" << std::endl;
			TheGame::Instance()->quit();
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
