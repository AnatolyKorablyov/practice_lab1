#include "View.h"

ViewVisual::ViewVisual(){
}


ViewVisual::~ViewVisual(){
}


void ViewVisual::drawAll(sf::RenderWindow &window, Model *mdl) {
	window.clear();
	window.draw(mdl->canvas);
	window.draw(mdl->UIbackground);
	for (auto i : mdl->UIcomponents) {
		i->drawUI(window);
	}
	for (auto i : mdl->shapes) {
		window.draw(i->shape);
		window.draw(i->accentuation);
		for (auto j : i->pointMarker) {
			i->marker.setPosition(j.x, j.y);
			window.draw(i->marker);
		}
	}
	window.display();
}