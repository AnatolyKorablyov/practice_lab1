#include "btnUndoRedo.h"



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
	int num = (*it)->typeFigure;
	shapes[num]->pos = (*it)->pos;
	shapes[num]->size = (*it)->size;
	shapes[num]->setProper();
}


btnUndo::~btnUndo()
{
}

//// Button REDO
btnRedo::btnRedo() {
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
	int num = (*it)->typeFigure;
	shapes[num]->pos = (*it)->pos;
	shapes[num]->size = (*it)->size;
	shapes[num]->setProper();
}

btnRedo::~btnRedo()
{
}
