#include "btnUndoRedo.h"
#include <iostream>


btnUndo::btnUndo(){
	name = "Undo";
	pos = {2, 2};
	size = {20, 16};
	text.setString("Undo");
	setPropertiesBtn();
}

void btnUndo::drawUI(RenderWindow & window) {
	window.draw(btnShape);
	window.draw(text);
}

void btnUndo::commandBtn(std::vector<Figure*> &shapes, std::vector<storyR*>::iterator &it) {
	it--;
	shapes = (*it)->shapes;
}


btnUndo::~btnUndo()
{
}

//// Button REDO
btnRedo::btnRedo() {
	name = "Redo";
	pos = { 24, 2 };
	size = { 20, 16 };
	text.setString("Redo");
	setPropertiesBtn();
}

void btnRedo::drawUI(RenderWindow & window) {
	window.draw(btnShape);
	window.draw(text);
}

void btnRedo::commandBtn(std::vector<Figure*> &shapes, std::vector<storyR*>::iterator &it) {
	it++;
	shapes = (*it)->shapes;
	/*
	int num = (*it)->shapes.typeFigure;
	shapes[num]->pos = (*it)->shapes.pos;
	shapes[num]->size = (*it)->shapes.size;
	shapes[num]->setProper();*/
}

btnRedo::~btnRedo()
{
}
