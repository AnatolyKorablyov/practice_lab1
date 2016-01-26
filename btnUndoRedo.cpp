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

void btnUndo::commandBtn(std::vector<Figure*> &shapes) {
	
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

void btnRedo::commandBtn(std::vector<Figure*> &shapes) {
	
}

btnRedo::~btnRedo()
{
}
