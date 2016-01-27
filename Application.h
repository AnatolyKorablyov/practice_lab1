#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Figure.h"
#include "WorkPlace.h" 
#include "btnAdd.h"
#include "btnUndoRedo.h"
#include "Story.h"

class Application{
private:
	bool Frame;
	WorkPlace WP;
	sf::RenderWindow window;
	std::vector<Figure*> shapes;
	std::vector<UI*> UIcomponents;

	std::vector<storyR*> Story;
	std::vector<storyR*>::iterator iter = Story.begin();

public:
	Application();
	~Application();
	virtual void drawAll();
	virtual void HandlerUI(Vector2f posMouse, Event event);
	virtual void eventHandler(Vector2f posMouse);
	virtual void update();
};

