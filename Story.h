#pragma once

struct storyR {
public:
	sf::String command;
	int typeFigure;
	sf::Vector2f pos;
	sf::Vector2f size;

	storyR(sf::String com, int typeFig, sf::Vector2f coord, sf::Vector2f siz) {
		command = com;
		typeFigure = typeFig;
		pos = coord;
		size = siz;
	}
};