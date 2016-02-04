#include <SFML\Graphics.hpp>
#include "Controller.h"

int main() {
	Controller ctrl;

	sf::RenderWindow window(sf::VideoMode(800, 480), "applique");
	while (window.isOpen()) {
		ctrl.moveMouse(window);
	}
	return 0;
}