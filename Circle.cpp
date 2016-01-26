#include "Circle.h"



Circle::Circle(){	
	shape.setPointCount(4 * radius);
	for (int i = 0; i <radius; i++) {
		shape.setPoint(i, Vector2f(i, sqrt(radius * radius - i * i)));
	}
	int coordX = radius;
	for (int i = radius; i <2 * radius; i++) {
		shape.setPoint(i, Vector2f(coordX, -(sqrt(radius * radius - (coordX)* (coordX)))));
		coordX -= 1;
	}
	for (int i = 2 * radius; i <3 * radius; i++) {
		shape.setPoint(i, Vector2f(coordX, -(sqrt(radius * radius - (coordX)* (coordX)))));
		coordX -= 1;
	}
	for (int i = 3 * radius; i <4 * radius; i++) {
		shape.setPoint(i, Vector2f(coordX, (sqrt(radius * radius - (coordX)* (coordX)))));
		coordX += 1;
	}

	color = Color(89, 125, 163, 255);
	setPropert();
	shape.setOrigin(0, 0);
}


Circle::~Circle()
{
}

bool Circle::getRect(Vector2f posM) {
	return ((posM.x - pos.x)*(posM.x - pos.x) + (posM.y - pos.y)*(posM.y - pos.y) <= (radius * size.x) * (radius * size.x)); // окружность
}