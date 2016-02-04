#include "Triangle.h"


Triangle::Triangle(){
	shape.setPointCount(3);
	color = sf::Color(240, 1, 163, 255);
	setPropert();
	setFrame();
}


Triangle::~Triangle(){

}

void Triangle::setFrame() {
	sf::Vector2f sizeFrame = { shape.getPoint(1).x - shape.getPoint(2).x, shape.getPoint(1).y };
	accentuation.setPosition(shape.getPosition());
	accentuation.setSize(sf::Vector2f(sizeFrame.x, sizeFrame.y));
	accentuation.setOrigin(sizeFrame.x / 2, radius);

	pointMarker[0] = sf::Vector2f(pos.x - radius + shape.getPoint(2).x, pos.y - radius);
	pointMarker[1] = sf::Vector2f(pos.x - radius + shape.getPoint(1).x, pos.y - radius);
	pointMarker[2] = sf::Vector2f(pos.x - radius + shape.getPoint(1).x, pos.y - radius + shape.getPoint(1).y);
	pointMarker[3] = sf::Vector2f(pos.x - radius + shape.getPoint(2).x, pos.y - radius + shape.getPoint(2).y);
}