#pragma once
#include"Common.h"

class Brick {
	Vector2f pos;
public:
	Texture texture;
	Sprite sprite;
	Brick();
	void setPosition(Vector2f);
	void draw(RenderWindow*);
};
