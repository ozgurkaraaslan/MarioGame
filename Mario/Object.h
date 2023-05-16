#pragma once
#include "Common.h"

class Object {

protected:
	Vector2f pos;
	RenderWindow* window;

	Texture textures[7];
	Sprite sprite;

	int state;
	int heading;

public:
	//Object(RenderWindow* window);
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	IntRect boundingBox(void);
	void draw(RenderWindow &window);
	
	/*
	void move();
	void fall();
	void jump(bool down);*/
};