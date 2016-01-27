#include "Square.h"
#include <math.h>


Square::Square(){
	name = "Square";
	shape.setPointCount(4);
	shape.setRotation(45);/*
	shape.setPoint(0, Vector2f(0, 0));
	shape.setPoint(1, Vector2f(radius * 2, 0));
	shape.setPoint(2, Vector2f(radius * 2, radius * 2));
	shape.setPoint(3, Vector2f(0, radius * 2));*/
	color = Color(89, 0, 163, 255);
	setPropert();

}


Square::~Square()
{
}

bool Square::getRect(Vector2f posM) {
	return (pos.x - radius * size.x  < posM.x && pos.x + radius * size.x > posM.x && pos.y - radius * size.y < posM.y && pos.y + radius * size.y > posM.y);
}

void Square::frameSetProperties() {
	pointMarker[0] = Vector2f(pos.x + (cos(-135 * 3.14 / 180) * radius), pos.y + (sin(-135 * 3.14 / 180) * radius));
	pointMarker[1] = Vector2f(pos.x + (cos(-45 * 3.14 / 180) * radius), pos.y + (sin(-45 * 3.14 / 180) * radius));
	pointMarker[2] = Vector2f(pos.x + (cos(45 * 3.14 / 180) * radius), pos.y + (sin(45 * 3.14 / 180) * radius));
	pointMarker[3] = Vector2f(pos.x + (cos(135 * 3.14 / 180) * radius), pos.y + (sin(135 * 3.14 / 180) * radius));

	accentuation.setPosition(shape.getPosition());
	accentuation.setSize(Vector2f(pointMarker[1].x - pointMarker[0].x, pointMarker[2].y - pointMarker[1].y));
	accentuation.setOrigin(accentuation.getSize().x / 2, accentuation.getSize().y / 2);

	
}