#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Story.h"
using namespace sf;

class UI{
protected:
	Vector2f pos;
	Vector2f size;
	Font font;
	bool pressed = false;
	void setPropertiesBtn();
public:
	String name;
	RectangleShape btnShape;
	Text text;
	UI();
	~UI();
	bool checkIntersects(Vector2f posM);
	virtual void drawUI(RenderWindow & window) = 0;
	virtual void commandBtn(std::vector<Figure*> &shapes) = 0;
};

