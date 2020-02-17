#include "ScoreLabel.h"
#include "Game.h"


ScoreLabel::ScoreLabel(std::string text, std::string fontName, int fontSize, SDL_Color colour, glm::vec2 position, int fontStyle, bool isCentered) :
	m_fontName(fontName), m_fontColour(colour), m_text(text), m_isCentered(isCentered), m_fontSize(fontSize), m_fontStyle(fontStyle)
{
	m_fontPath = "../Assets/fonts/" + fontName + ".ttf";

	m_buildFontID();

	FontManager::Instance()->load(m_fontPath, m_fontID, fontSize, fontStyle);

	FontManager::Instance()->textToTexture(text, m_fontID, m_fontID, colour);
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_fontID);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
}

ScoreLabel::~ScoreLabel()
{

}

void ScoreLabel::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->drawText(m_fontID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, m_isCentered);
}

void ScoreLabel::update()
{
}

void ScoreLabel::clean()
{

}

void ScoreLabel::setText(std::string newText)
{

	m_text = newText;

	m_buildFontID();

	FontManager::Instance()->load(m_fontPath, m_fontID, m_fontSize, m_fontStyle);

	FontManager::Instance()->textToTexture(newText, m_fontID, m_fontID, m_fontColour);
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_fontID);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(getPosition());
}

void ScoreLabel::setColour(SDL_Color newColour)
{
	FontManager::Instance()->load(m_fontPath, m_fontID, m_fontSize, m_fontStyle);
	FontManager::Instance()->textToTexture(m_text, m_fontID, m_fontID, newColour);
}

void ScoreLabel::setSize(int newSize)
{
	m_fontSize = newSize;

	m_buildFontID();

	FontManager::Instance()->load(m_fontPath, m_fontID, m_fontSize);

	FontManager::Instance()->textToTexture(m_text, m_fontID, m_fontID, m_fontColour);
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_fontID);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(getPosition());
}

void ScoreLabel::m_buildFontID()
{
	m_fontID = m_fontName;
	m_fontID += "-";
	m_fontID += std::to_string(m_fontSize);
	m_fontID += "-";
	m_fontID += m_text;

	/*std::cout << "fontID: " << m_fontID << std::endl;
	std::cout << "TextureMap Size: " << TheTextureManager::Instance()->getTextureMapSize() << std::endl;*/
}

