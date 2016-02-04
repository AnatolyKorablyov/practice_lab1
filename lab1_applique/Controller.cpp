#include "Controller.h"



Controller::Controller(){

}


Controller::~Controller(){

}

void Controller::moveMouse(sf::RenderWindow &window) {
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f posMouse = window.mapPixelToCoords(pixelPos);
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		else {
			for (auto i : mdl.UIcomponents) {
				if (i->checkIntersects(posMouse) && event.type == sf::Event::MouseButtonReleased) {
					i->commandBtn(mdl.shapes);
				}
			}
		}
	}
	viw.drawAll(window, &mdl);
}