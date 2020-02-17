#include "Background.h"
#include "Game.h"

Background::Background()
{
	TheTextureManager::Instance()->load("../Assets/textures/Background.png",
		"ocean", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
//	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ocean");
	setWidth(800);
	setHeight(600);
}

Background::~Background()
{
}

void Background::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("ocean", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Background::update()
{
}

void Background::clean()
{
}
