#include "Figure.h"



Figure::Figure(){

}


Figure::~Figure(){

}

void Figure::setPropert() {
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(float(radius), float(radius));
	shape.setRadius(float(radius));
	shape.setOutlineColor(sf::Color::Green);
	shape.setOutlineThickness(2);

	accentuation.setFillColor(sf::Color::Color(255, 255, 255, 0));
	accentuation.setOutlineColor(sf::Color::Green);
	accentuation.setOutlineThickness(2);
	
	marker.setFillColor(sf::Color::Red);
	marker.setRadius(5);
	marker.setOrigin(5, 5);

	pointMarker.resize(4);
}