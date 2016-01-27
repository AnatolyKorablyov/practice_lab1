#pragma once
#include "Figure.h"
class WorkPlace : public Figure
{
public:
	RectangleShape canvas;
	RectangleShape backgroundUI;
	Vector2f sizeR = { 800, 420 };
	WorkPlace();
	~WorkPlace();
	virtual bool getRect(Vector2f posMouse) override;
	virtual void frameSetProperties() override;
};

