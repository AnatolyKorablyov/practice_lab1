#include "WorkPlace.h"



WorkPlace::WorkPlace(){
	backgroundUI.setSize(Vector2f(800, 60));
	backgroundUI.setFillColor(Color::Color(186, 199, 212, 250));
	backgroundUI.setPosition(0, 0);


	canvas.setSize(sizeR);
	canvas.setFillColor(Color::Color(255, 255, 255, 250));
	pos = { 0, 60 };
	canvas.setPosition(pos.x, pos.y);


}
WorkPlace::~WorkPlace()
{
}

bool WorkPlace::getRect(Vector2f posM) {
	return (pos.x   < posM.x && pos.x + sizeR.x > posM.x && pos.y < posM.y && pos.y + sizeR.y > posM.y);
}

void WorkPlace::frameSetProperties() {
}