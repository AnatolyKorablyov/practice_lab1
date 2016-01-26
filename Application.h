#pragma once
#include "Story.h"
#include "btnUndoRedo.h"
#include "Story.h"
#include "Figure.h"
#include "btnAdd.h"
#include "btnUndoRedo.h"

struct Application {
	std::vector<storyR*> Story;
	std::vector<storyR*>::iterator it;
	sf::RenderWindow window;
	std::vector<Figure*> shapes;
	std::vector<UI*> UIcomponents;

	Application() {
		UIcomponents.push_back(new btnAddCircle);
		UIcomponents.push_back(new btnAddTriangle);
		UIcomponents.push_back(new btnAddRectangle);
		UIcomponents.push_back(new btnUndo);

		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		window.create(sf::VideoMode(800, 480), "Applique", sf::Style::Default, settings);
	}
};