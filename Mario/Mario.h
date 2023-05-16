#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object{
	
	float vx;
	float vy;
public:
	Mario();
	void jump(bool down);
	void fall();
	enum MoveDirection {
		Up,
		Down,
		Left,
		Rigth
	};
	enum Direction {
		L,
		R
	};
	Direction curDir;
	Direction prevDir;
	void move(MoveDirection);
	void setScale(float a, float b);
};