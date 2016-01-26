#include "Square.h"



Square::Square(){

	shape.setPointCount(4);
	shape.setPoint(0, Vector2f(0, 0));
	shape.setPoint(1, Vector2f(radius * 2, 0));
	shape.setPoint(2, Vector2f(radius * 2, radius * 2));
	shape.setPoint(3, Vector2f(0, radius * 2));
	color = Color(89, 0, 163, 255);
	setPropert();

}


Square::~Square()
{
}

bool Square::getRect(Vector2f posM) {
	return (pos.x - radius * size.x  < posM.x && pos.x + radius * size.x > posM.x && pos.y - radius * size.y < posM.y && pos.y + radius * size.y > posM.y);
}