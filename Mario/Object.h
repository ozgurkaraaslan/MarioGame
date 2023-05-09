#pragma once
#include "Common.h"

class Object {
	
	Vector2f pos;
	RenderWindow* window;
	int state;
	int heading;

public:

	Object(RenderWindow* window);
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	IntRect boundingBox(void);
	void draw(RenderWindow &window);
	void move();
	void fall();
	void jump(bool down);
};