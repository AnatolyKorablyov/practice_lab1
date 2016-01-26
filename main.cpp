#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Story.h"
#include "Figure.h"
#include "WorkPlace.h" 
#include "btnAdd.h"
#include "btnUndoRedo.h"

using namespace sf;
using namespace std;

int main() {
	WorkPlace WP;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(sf::VideoMode(800, 480), "Applique", sf::Style::Default, settings);

	vector<Figure*> shapes;
	vector<UI*> UIcomponents;
	UIcomponents.push_back(new btnAddCircle);
	UIcomponents.push_back(new btnAddTriangle);
	UIcomponents.push_back(new btnAddRectangle);
	UIcomponents.push_back(new btnUndo);
	UIcomponents.push_back(new btnRedo);

	vector<storyR*> Story;
	vector<storyR*>::iterator iter;
	while (window.isOpen()) {

		

		Event event;
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f posMouse = window.mapPixelToCoords(pixelPos);
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			for (auto i : UIcomponents) {
				if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && i->checkIntersects(posMouse)) {
					i->commandBtn(shapes, iter);
					if (i->name == "add") {
						Story.push_back(new storyR("add", shapes.size() - 1, shapes[shapes.size() - 1]->pos, shapes[shapes.size() - 1]->size));
						iter = Story.end();
						iter--;
					}
					
				}
			}
			for (int it = shapes.size() - 1; it >= 0; it--) {
				Figure * i = shapes[it];
				if (Keyboard::isKeyPressed(Keyboard::Delete) && i->frame) {
					shapes.erase(shapes.begin() + it);
					delete i;
				}
				else {
					if (event.type == Event::MouseButtonPressed && i->checkTapMarker(posMouse) && i->frame) {
						i->resizeS = true;
					}
					else if (event.type == Event::MouseButtonPressed && i->getFrame(posMouse) && i->frame) {
						i->isMove = true;
					}
					if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left){
						if (i->getRect(posMouse)) {
							i->frame = true;
							i->frameSetProperties();
						}
						else {
							i->frame = false;
						}
						if (i->isMove) {
							iter++;
							while (iter != Story.end()) {
								iter = Story.erase(iter);
							}
							Story.push_back(new storyR("move", it, i->pos, i->size));
							i->isMove = false;
							iter = Story.end();
							iter--;
						}
						if (i->resizeS) {
							iter++;
							while (iter != Story.end()) {
								iter = Story.erase(iter);
							}
							Story.push_back(new storyR("resize", it, i->pos, i->size));
							i->resizeS = false;
							iter = Story.end();
							iter--;
						}
				
					}
				}
			}
		}
		for (auto i : shapes) {
			if (i->isMove && WP.getRect(posMouse)) {
				i->move(posMouse);
				i->frameSetProperties();
			}
			if (i->resizeS && WP.getRect(posMouse)) {
				i->resize(posMouse);
				i->frameSetProperties();
			}
		}
		window.clear();
		window.draw(WP.canvas);
		window.draw(WP.backgroundUI);
		for (auto i : UIcomponents) {
			i->drawUI(window);
		}
		for (auto i : shapes) {
			window.draw(i->shape);
		}
		for (auto i : shapes) {
			if (i->frame) {
				window.draw(i->accentuation);
				for (int j = 0; j < 4; j++) {
					i->marker.setPosition(i->pointMarker[j].x, i->pointMarker[j].y);
					window.draw(i->marker);
				}
			}
		}
		window.display();
	}
	return 0;
}