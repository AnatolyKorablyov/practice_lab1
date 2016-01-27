#include "Application.h"



Application::Application(){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(800, 480), "Applique", sf::Style::Default, settings);

	UIcomponents.push_back(new btnAddCircle);
	UIcomponents.push_back(new btnAddTriangle);
	UIcomponents.push_back(new btnAddRectangle);
	UIcomponents.push_back(new btnUndo);
	UIcomponents.push_back(new btnRedo);


	Story.push_back(new storyR(shapes));

	update();
}


Application::~Application(){
}

void Application::HandlerUI(Vector2f posMouse, Event event) {
	for (auto i : UIcomponents) {
		if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && i->checkIntersects(posMouse)) {
			if (i->name == "Undo" && iter != Story.begin()) {
				i->commandBtn(shapes, iter);
			}
			else if (i->name == "Redo" && iter != Story.end()) {
				if (iter < Story.end() - 1) {
					i->commandBtn(shapes, iter);
				}
			}
			else if (i->name == "add") {
				i->commandBtn(shapes, iter);
				Story.push_back(new storyR(shapes));//"add", shapes.size() - 1, shapes[shapes.size() - 1]->pos, shapes[shapes.size() - 1]->size));
				iter = Story.end();
				iter--;
			}

		}
	}
}

void Application::eventHandler(Vector2f posMouse) {
	Event event;
	Frame = false;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		HandlerUI(posMouse, event);
		for (int it = shapes.size() - 1; it >= 0; it--) {
			Figure * i = shapes[it];
			if (Keyboard::isKeyPressed(Keyboard::Delete) && i->frame) {
				shapes.erase(shapes.begin() + it);
				delete i;
				Story.push_back(new storyR(shapes));//"resize", it, i->pos, i->size));
				iter = Story.end();
				iter--;
			}
			else {
				if (event.type == Event::MouseButtonPressed && i->checkTapMarker(posMouse) && i->frame) {
					i->resizeS = true;
					Frame = true;
				}
				else if (event.type == Event::MouseButtonPressed && i->getFrame(posMouse) && i->frame) {
					i->isMove = true;
					Frame = true;
				}
				if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) {
					if (i->getRect(posMouse) && !Frame) {
						i->frame = true;
						Frame = true;
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
						Story.push_back(new storyR(shapes));//"move", it, i->pos, i->size));
						i->isMove = false;
						iter = Story.end();
						iter--;
					}
					if (i->resizeS) {
						iter++;
						while (iter != Story.end()) {
							iter = Story.erase(iter);
						}
						Story.push_back(new storyR(shapes));//"resize", it, i->pos, i->size));
						i->resizeS = false;
						iter = Story.end();
						iter--;
					}

				}
			}
		}
	}
}

void Application::drawAll() {
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

void Application::update() {
	while (window.isOpen()) {
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f posMouse = window.mapPixelToCoords(pixelPos);
		eventHandler(posMouse);
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
		drawAll();
	}
}