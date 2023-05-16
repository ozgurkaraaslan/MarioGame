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
	
	Direction curDir;
	
	void move(MoveDirection);
};