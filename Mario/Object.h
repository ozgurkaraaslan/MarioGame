#pragma once
#include "Common.h"

class Object {

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
	Vector2f getPosition();
	void draw(RenderWindow &window);
	
	void boundingBox(const FloatRect& hitbox) {
		m_hitbox = hitbox;
	}
	void edgeHit();
	
	/*
	void move();
	void fall();
	void jump(bool down);
	*/
};