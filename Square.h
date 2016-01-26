#pragma once
#include "Figure.h"

class Square : public Figure{
public:
	Square();
	~Square();
	virtual bool getRect(Vector2f posMouse) override;
};

