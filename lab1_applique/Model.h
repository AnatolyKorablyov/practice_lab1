#pragma once
#include <SFML\Graphics.hpp>
#include "Figure.h"
//#include "UI.h"
#include "btnAdd.h"

class Model{
public:
	sf::RectangleShape canvas;
	sf::RectangleShape UIbackground;
	std::vector<Figure*> shapes;
	std::vector<UI*> UIcomponents;
	Model();
	~Model();
};

