#pragma once
#define _USE_MATH_DEFINES
#include <SFML\Graphics.hpp>
#include <math.h>

class Figure{
protected:
	sf::Color color;
	sf::Vector2f pos = {300, 300};
	int radius = 50;
	void setPropert();
	virtual void setFrame() = 0;	
	/*virtual void moveF() = 0;
	virtual void resizeF() = 0;*/
	bool frame = false;

public:

	std::vector<sf::Vector2f> pointMarker;
	sf::CircleShape shape;
	sf::RectangleShape accentuation;
	sf::CircleShape marker;
	Figure();
	~Figure();
};

