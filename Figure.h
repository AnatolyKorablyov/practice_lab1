#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Figure{
protected:
	
	Color color;
	virtual void setPropert();

	
public:
	float radius = 50.0f;
	int count;
	Vector2f pos = { 300, 200 };
	Vector2f size = { 1, 1 };
	std::vector<Vector2f> pointMarker;
	bool isMove = false;
	bool frame = false;
	bool resizeS = false;
	ConvexShape shape;
	RectangleShape accentuation;
	CircleShape marker;
	Figure();
	Figure(ConvexShape shap);
	~Figure();
	virtual void move(Vector2f posMouse);
	virtual void resize(Vector2f posMouse);
	virtual bool getRect(Vector2f posMouse) = 0;
	virtual void frameSetProperties();
	virtual bool getFrame(Vector2f posMouse);
	virtual void setProper();
	virtual bool checkTapMarker(Vector2f posMouse);
};

