#pragma once
#include "Common.h"
#include "Object.h"

class Turtle : public Object {

	float vx, vy;

public:
	Turtle();
	void move();
	void jump();
	void fall();
};