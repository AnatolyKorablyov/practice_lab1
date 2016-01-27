#include "Circle.h"



Circle::Circle(){
	name = "Circle";/*
	shape.setPointCount(4 * int(radius));
	for (int i = 0; i <radius; i++) {
		shape.setPoint(i, Vector2f(float(i), sqrt(radius * radius - i * i)));
	}
	float coordX = radius;
	for (int i = int(radius); i < 2 * radius; i++) {
		shape.setPoint(i, Vector2f(coordX, -(sqrt(radius * radius - (coordX)* (coordX)))));
		coordX -= 1;
	}
	for (int i = 2 * int(radius); i <3 * radius; i++) {
		shape.setPoint(i, Vector2f(coordX, -(sqrt(radius * radius - (coordX)* (coordX)))));
		coordX -= 1;
	}
	for (int i = 3 * int(radius); i <4 * radius; i++) {
		shape.setPoint(i, Vector2f(coordX, (sqrt(radius * radius - (coordX)* (coordX)))));
		coordX += 1;
	}*/
	color = Color(95, 127, 165, 255);
	setPropert();
	//shape.setOrigin(0, 0);
}


Circle::~Circle()
{
}

bool Circle::getRect(Vector2f posM) {
	return ((posM.x - pos.x)*(posM.x - pos.x) + (posM.y - pos.y)*(posM.y - pos.y) <= (radius * size.x) * (radius * size.x)); // окружность
}

void Circle::frameSetProperties() {
	accentuation.setPosition(shape.getPosition());
	accentuation.setOrigin(radius * size.x, radius * size.y);
	accentuation.setSize(Vector2f(radius * size.x * 2, radius *  size.y * 2));

	pointMarker[0] = Vector2f(pos.x - radius * size.x, pos.y - radius * size.y);
	pointMarker[1] = Vector2f(pos.x + radius * size.x, pos.y - radius * size.y);
	pointMarker[2] = Vector2f(pos.x + radius * size.x, pos.y + radius * size.y);
	pointMarker[3] = Vector2f(pos.x - radius * size.x, pos.y + radius * size.y);
}