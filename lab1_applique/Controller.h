#pragma once
#include <SFML\Graphics.hpp>
#include "Model.h"
#include "View.h"
#include "Triangle.h"

class Controller{
private:
	Model mdl;
	ViewVisual viw;
public:
	Controller();
	~Controller();
	void moveMouse(sf::RenderWindow &window);
};

