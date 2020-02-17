#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "ScoreLabel.h"
#include "RollButton.h"
#include "BetButton.h"
#include "QuitButton.h"
#include "ResetButton.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	ScoreLabel* m_pScoreLabel;
	glm::vec2 m_mousePosition;
	
	RollButton* m_pRollButton;
	BetButton* m_pBetButton;
	QuitButton* m_pQuitButton;
	ResetButton* m_pResetButton;
};

#endif /* defined (__LEVEL_1_SCENE__) */
