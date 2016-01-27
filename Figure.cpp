#include "Figure.h"
#include <iostream>

Figure::Figure() {
}

Figure::Figure(CircleShape shap){
	shape = shap;
}

Figure::~Figure()
{
}

void Figure::setPropert() {
	shape.setOutlineColor(Color::Green);
	shape.setOutlineThickness(2);
	shape.setPosition(pos.x, pos.y);
	shape.setOrigin(radius, radius);
	shape.setRadius(radius);
	shape.setFillColor(color);

	accentuation.setOutlineThickness(2);
	accentuation.setOutlineColor(Color::Color(100, 100, 100, 255));
	accentuation.setFillColor(Color::Color(0, 0, 0, 0));
	
	marker.setRadius(5);
	marker.setFillColor(Color::Red);
	marker.setOrigin(5, 5);
	for (int i = 0; i < 4; i++) {
		pointMarker.push_back(Vector2f(accentuation.getPoint(i).x, accentuation.getPoint(i).y));
	}
}



void Figure::move(Vector2f posMouse) {

	pos = { posMouse.x, posMouse.y };
	shape.setPosition(pos.x, pos.y);
	frameSetProperties();
}

void Figure::resize(Vector2f posMouse) {
	radius = sqrt(abs(posMouse.x - pos.x)*abs(posMouse.x - pos.x) + abs(posMouse.y - pos.y)*abs(posMouse.y - pos.y));
	//size = { abs(posMouse.x - pos.x) / (radius),  abs(posMouse.y - pos.y) / (radius) };
	//shape.setScale(size.x, size.y);
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);

}

void Figure::setProper() {
	shape.setPosition(pos.x, pos.y);
	shape.setRadius(radius);
}
bool Figure::getFrame(Vector2f posM) {
	return (pos.x - radius * size.x < posM.x && pos.x + radius * size.x > posM.x && pos.y - radius * size.y < posM.y && pos.y + radius * size.y > posM.y);
}

bool Figure::checkTapMarker(Vector2f posM) {
	bool tap = false;
	for (int i = 0; i < 4; i++) {
		if (pointMarker[i].x - 5 < posM.x && pointMarker[i].x + 5 > posM.x && pointMarker[i].y - 5 < posM.y && pointMarker[i].y + 5 > posM.y) {
			tap = true;
		}
	}
	return tap;
}