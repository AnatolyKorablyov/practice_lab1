#pragma once
#include "UI.h"
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"

class btnAddCircle : public UI {
public:
	btnAddCircle();
	~btnAddCircle();
	virtual void drawUI(sf::RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> & shapes) override;
};

class btnAddTriangle : public UI {
public:
	btnAddTriangle();
	~btnAddTriangle();
	virtual void drawUI(sf::RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> & shapes) override;
};

class btnAddRectangle : public UI {
public:
	btnAddRectangle();
	~btnAddRectangle();
	virtual void drawUI(sf::RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> & shapes) override;

};