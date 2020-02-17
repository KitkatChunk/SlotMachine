#include "RollButton.h"
#include "Game.h"

RollButton::RollButton()
// call super constructor
	:Button(
		"../Assets/textures/RollButton.png",
		"startButton",
		START_BUTTON, glm::vec2(700.0f, 550.0f)), m_isClicked(false)
{

}

RollButton::~RollButton()
{
}

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Roll!" << std::endl;
			TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
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