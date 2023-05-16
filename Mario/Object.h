#pragma once
#include "Common.h"

class Object {

protected:
	Vector2f pos;
	RenderWindow* window;

	Texture textures[7];
	

	int state;
	int heading;

public:
	Sprite sprite;
	//Object(RenderWindow* window);
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	IntRect boundingBox(void);
	void draw(RenderWindow &window);
	enum Direction {
		L,
		R,
		LI,
		RI
	};
	Direction prevDir;
	/*
	void move();
	void fall();
	void jump(bool down);
	*/
};