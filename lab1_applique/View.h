#pragma once
#include <SFML\Graphics.hpp> 
#include "Model.h"

class ViewVisual{
private:
	Model mdl;
public:
	ViewVisual();
	~ViewVisual();
	void drawAll(sf::RenderWindow &window, Model *mdl);
};

