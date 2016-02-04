#pragma once
#include "Figure.h"

class Triangle : public Figure{
private:
	void setFrame() override;
public:
	Triangle();
	~Triangle();
};

