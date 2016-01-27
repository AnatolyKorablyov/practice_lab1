#pragma once
#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle();
	~Triangle();
	virtual bool getRect(Vector2f posMouse) override;
	virtual void frameSetProperties() override;
};

