#include "Triangle.h"
#include <iostream>

Triangle::Triangle(){
	shape.setPointCount(3);
	shape.setPoint(0, Vector2f(radius, 0));
	shape.setPoint(1, Vector2f(2 * radius, 2 * radius));
	shape.setPoint(2, Vector2f(0, 2 * radius));
	color = Color(240, 1, 163, 255);
	setPropert();

}


Triangle::~Triangle()
{
}

bool Triangle::getRect(Vector2f posM) {
	Vector2f point0 = { pos.x, pos.y - radius * size.y };
	Vector2f point1 = { pos.x + (shape.getPoint(1).x* size.x - radius * size.x), pos.y + (shape.getPoint(1).y* size.y - radius * size.y) };
	Vector2f point2 = { pos.x + (shape.getPoint(2).x* size.x - radius * size.x), pos.y + (shape.getPoint(2).y* size.y - radius * size.y) };

	return (((posM.x - point0.x)*(point1.y - point0.y) - (posM.y - point0.y)*(point1.x - point0.x)) <= 0 &&
		((posM.x - point1.x)*(point2.y - point1.y) - (posM.y - point1.y)*(point2.x - point1.x)) <= 0 &&
		((posM.x - point0.x)*(point2.y - point0.y) - (posM.y - point0.y)*(point2.x - point0.x)) >= 0); // треугольник
}