#pragma once
#include "UI.h"
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

class btnAddCircle : public UI{
private:
	Circle circ;
public:
	btnAddCircle();
	~btnAddCircle();
	virtual void drawUI(RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> &shapes) override;
};

class btnAddTriangle : public UI{
private:
	Triangle trian;
public:
	btnAddTriangle();
	~btnAddTriangle();
	virtual void drawUI(RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> &shapes) override;
};

class btnAddRectangle : public UI{
private:
	Square squar;
public:
	btnAddRectangle();
	~btnAddRectangle();
	virtual void drawUI(RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> &shapes) override;

};