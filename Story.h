#pragma once

#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

struct storyR {
public:
	std::vector<Figure*> shapes;
	std::vector<Figure*>::iterator it;
	storyR(std::vector<Figure*> shap) {
		for (auto i : shap) {
			if (i->name == "Circle")
				shapes.push_back(new Circle);
			else if (i->name == "Triangle")
				shapes.push_back(new Triangle);
			else if (i->name == "Square")
				shapes.push_back(new Square);
			it = shapes.end();
			it--;
			(*it)->pos = i->pos;
			(*it)->radius = i->radius;
			(*it)->setProper();
		}
	}
};