#pragma once
#include "Figure.h"

class Square : public Figure{
private:
	void setFrame() override;
public:
	Square();
	~Square();
};
