#include "Model.h"



Model::Model(){
	canvas.setSize(sf::Vector2f(800, 480));
	canvas.setFillColor(sf::Color::Color(255, 255, 255, 250));

	UIbackground.setSize(sf::Vector2f(800, 60));
	UIbackground.setFillColor(sf::Color::Color(186, 199, 212, 250));

	UIcomponents.push_back(new btnAddCircle);
	UIcomponents.push_back(new btnAddTriangle);
	UIcomponents.push_back(new btnAddRectangle);
	/*UIcomponents.push_back(new btnUndo);
	UIcomponents.push_back(new btnRedo);*/

}


Model::~Model(){

}
