#pragma once
#pragma once
#include "Common.h"

class Heads {

public:
	Texture texture;
	Sprite sprite;
	Heads();
	void draw(RenderWindow& window);
	void setPosition(Vector2f pos);
	Vector2f pos;

};