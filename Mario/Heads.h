#pragma once
#pragma once
#include "Common.h"

class Heads {
	Vector2f pos;
	Texture texture;
public:
	Sprite sprite;
	Heads();
	void draw(RenderWindow& window);
	void setPosition(Vector2f pos);

};