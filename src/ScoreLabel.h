#pragma once
#ifndef __Score_Label__
#define __Score_Label__

#include <string>

#include "DisplayObject.h"
#include "FontManager.h"
#include "Scene.h"

class ScoreLabel : public DisplayObject
{
public:
	ScoreLabel(std::string text = "Default Label Text", std::string fontName = "lazy", int size = 20, SDL_Color colour = { 0, 0, 0, 255 }, glm::vec2 position = glm::vec2(), int fontStyle = TTF_STYLE_NORMAL, bool isCentered = true);
	~ScoreLabel();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void setText(std::string newText);
	void setColour(SDL_Color newColour);
	void setSize(int newSize);

private:
	std::string m_fontPath;
	std::string m_fontID;
	SDL_Color m_fontColour;
	std::string m_fontName;
	std::string m_text;
	bool m_isCentered = true;
	int m_fontSize;
	int m_fontStyle;

	void m_buildFontID();
};

#endif /* defined (__Score_Label__) */