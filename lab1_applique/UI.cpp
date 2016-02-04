#include "UI.h"


UI::UI() {
	font.loadFromFile("andika.ttf");
	text.setFont(font);
	text.setCharacterSize(8);
	text.setColor(sf::Color::Black);
}


UI::~UI()
{
}

bool UI::checkIntersects(sf::Vector2f posM) {
	return (pos.x < posM.x && pos.y < posM.y && pos.x + size.x > posM.x && pos.y + size.y > posM.y);

}

void UI::setPropertiesBtn() {
	btnShape.setSize(size);
	btnShape.setPosition(pos.x, pos.y);
	btnShape.setFillColor(sf::Color::Color(0, 0, 0, 0));
	btnShape.setOutlineColor(sf::Color::Color(0, 0, 0, 255));
	btnShape.setOutlineThickness(1);
	text.setPosition(pos.x + 1, pos.y + size.y - 8);
}
