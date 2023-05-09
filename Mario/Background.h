#pragma once
#include"Common.h"

class Background {
	Vector2f pos;
public:
	Texture texture;
	Sprite sprite;
	void setPosition(Vector2f);
	void draw(RenderWindow*);
	void setScale(float, float);
};
