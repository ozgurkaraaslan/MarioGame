#pragma once
#include "Common.h"
#include "Object.h"

class Turtle : public Object {

	float vx, vy;
	Int32 time;
	Direction dir;

public:
	Turtle();
	void move();
	void jump(bool down);
	void fall();
	
	
};