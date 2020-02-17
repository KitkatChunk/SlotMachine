#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBackground->draw();
	m_pScoreLabel->draw();
	m_pRollButton->draw();
	m_pBetButton->draw();
	m_pQuitButton->draw();
	m_pResetButton->draw();
}

void Level1Scene::update()
{
	
	//Roll
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick();
	//Bet
	m_pBetButton->setMousePosition(m_mousePosition);
	m_pBetButton->ButtonClick();
	//Quit
	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();
	//reset
	m_pResetButton->setMousePosition(m_mousePosition);
	m_pResetButton->ButtonClick();
}

void Level1Scene::clean()
{
	delete m_pScoreLabel;

}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				m_pBetButton->setMouseButtonClicked(true);
				m_pQuitButton->setMouseButtonClicked(true);
				m_pResetButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);
				m_pBetButton->setMouseButtonClicked(false);
				m_pQuitButton->setMouseButtonClicked(false);
				m_pResetButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:
				
				break;
			case SDLK_d:
				
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:
				
				break;
			case SDLK_d:
				
				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{

	
	SDL_Color blue = { 0, 0, 255, 255 };
	m_pScoreLabel = new ScoreLabel("Score:", "Consolas", 40, blue, glm::vec2(100.0f, 550.0f));
	m_pScoreLabel->setParent(this);
	addChild(m_pScoreLabel);

	m_pBackground = new Background();
	addChild(m_pBackground);

	// allocates memory on the heap for this game object
	m_pRollButton = new RollButton();
	m_pRollButton->setMouseButtonClicked(false);

	m_pBetButton = new BetButton();
	m_pBetButton->setMouseButtonClicked(false);

	m_pQuitButton = new QuitButton();
	m_pQuitButton->setMouseButtonClicked(false);

	m_pResetButton = new ResetButton();
	m_pResetButton->setMouseButtonClicked(false);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

