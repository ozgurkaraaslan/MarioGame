#pragma once
#include "Common.h"

class Object {  // Object class to inherit to the mario and turtle classes

protected:
	Vector2f pos;
	RenderWindow* window;

	Texture textures[7];
	bool dead;
	int state;
	int heading;
	enum Direction {
		L,
		R,
		LI,
		RI
	};
	Direction curDir, prevDir;
public:
	FloatRect m_hitbox;
	Sprite sprite;
	//Object(RenderWindow* window);
	void setPosition(Vector2f pos);
	void draw(RenderWindow &window);
	void boundingBox(const FloatRect& hitbox) {
		m_hitbox = hitbox;
	}
	void edgeHit();
};