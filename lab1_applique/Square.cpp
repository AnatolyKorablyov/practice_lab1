#include "Square.h"



Square::Square()
{
	shape.setPointCount(4);
	shape.setRotation(45);
	color = sf::Color(89, 0, 163, 255);
	setPropert();
	setFrame();
}


Square::~Square()
{
}

void Square::setFrame() {
	float radian = float(M_PI / 180);
	pointMarker[0] = sf::Vector2f(pos.x + (cos(-135 * radian) * radius), pos.y + (sin(-135 * radian) * radius));
	pointMarker[1] = sf::Vector2f(pos.x + (cos(-45 * radian) * radius), pos.y + (sin(-45 * radian) * radius));
	pointMarker[2] = sf::Vector2f(pos.x + (cos(45 * radian) * radius), pos.y + (sin(45 * radian) * radius));
	pointMarker[3] = sf::Vector2f(pos.x + (cos(135 * radian) * radius), pos.y + (sin(135 * radian) * radius));

	sf::Vector2f sizeFrame = { pointMarker[2].x - pointMarker[0].x, pointMarker[2].y - pointMarker[0].y };
	accentuation.setPosition(shape.getPosition());
	accentuation.setSize(sf::Vector2f(sizeFrame.x, sizeFrame.y));
	accentuation.setOrigin(sizeFrame.x / 2, sizeFrame.y / 2);
}