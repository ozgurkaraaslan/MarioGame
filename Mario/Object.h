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
	FloatRect m_hitbox;
	Sprite sprite;
	//Object(RenderWindow* window);
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	void draw(RenderWindow &window);
	enum Direction {
		L,
		R,
		LI,
		RI
	};
	void boundingBox(const FloatRect& hitbox) {
		m_hitbox = hitbox;
	}
	void edgeHit();
	Direction prevDir;
	/*
	void move();
	void fall();
	void jump(bool down);
	*/
};