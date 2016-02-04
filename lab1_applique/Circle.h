#pragma once
#include "Figure.h"

class Circle : public Figure{
private:
	void setFrame() override;
public:
	Circle();
	~Circle();
};

