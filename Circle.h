#pragma once
#include "Figure.h"

class Circle : public Figure{
public:
	Circle();
	~Circle();
	virtual bool getRect(Vector2f posMouse) override;
};


