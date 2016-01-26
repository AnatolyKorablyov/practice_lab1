#include "btnAdd.h"


// Button add Circle

btnAddCircle::btnAddCircle(){
	name = "add";
	pos = { 2, 22 };
	size = { 36, 36 };
	text.setString("Circle");
	setPropertiesBtn();
}


btnAddCircle::~btnAddCircle()
{
}

void btnAddCircle::drawUI(RenderWindow & window) {
	window.draw(btnShape);
	window.draw(text);
}

void btnAddCircle::commandBtn(std::vector<Figure*> &shapes, std::vector<storyR*>::iterator & it) {
	shapes.push_back(new Circle);
}



// Button add Triangle

btnAddTriangle::btnAddTriangle(){
	name = "add";
	pos = { 42, 22 };
	size = { 36, 36 };
	text.setString("Triangle");
	setPropertiesBtn();
}


btnAddTriangle::~btnAddTriangle()
{
}

void btnAddTriangle::drawUI(RenderWindow & window) {
	window.draw(btnShape);
	window.draw(text);
}
void btnAddTriangle::commandBtn(std::vector<Figure*> &shapes, std::vector<storyR*>::iterator &it) {
	shapes.push_back(new Triangle);
}


// Button add Rectangle

btnAddRectangle::btnAddRectangle(){
	name = "add";
	pos = {82, 22 };
	size = { 36, 36 };
	text.setString("Square");
	setPropertiesBtn();
}


btnAddRectangle::~btnAddRectangle()
{
}

void btnAddRectangle::drawUI(RenderWindow & window) {
	window.draw(btnShape);
	window.draw(text);
}

void btnAddRectangle::commandBtn(std::vector<Figure*> &shapes, std::vector<storyR*>::iterator &it) {
	shapes.push_back(new Square);
}
