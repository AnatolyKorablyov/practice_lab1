#include "Circle.h"



Circle::Circle(){
	color = sf::Color(95, 127, 165, 255);
	setPropert();
	setFrame();
}


Circle::~Circle()
{
}

void Circle::setFrame() {
	sf::Vector2f sizeFrame = { float(radius * 2), float(radius * 2) };
	accentuation.setPosition(shape.getPosition());
	accentuation.setOrigin(radius, radius);
	accentuation.setSize(sizeFrame);

	pointMarker[0] = sf::Vector2f(pos.x - radius, pos.y - radius);
	pointMarker[1] = sf::Vector2f(pos.x + radius, pos.y - radius);
	pointMarker[2] = sf::Vector2f(pos.x + radius, pos.y + radius);
	pointMarker[3] = sf::Vector2f(pos.x - radius, pos.y + radius);
}