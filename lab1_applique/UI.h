#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"

class UI {
protected:
	sf::String name;
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Font font;
	sf::RectangleShape btnShape;
	sf::Text text;
	bool pressed = false;
	void setPropertiesBtn();
	
public:
	UI();
	~UI();
	bool checkIntersects(sf::Vector2f posM);
	virtual void drawUI(sf::RenderWindow & window) = 0;
	virtual void commandBtn(std::vector<Figure*> & shapes) = 0;
};