#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object{
	
	
public:
	float vx;
	float vy;
	Mario();
	void jump(bool down);
	void fall();
	enum MoveDirection {
		Up,
		Left,
		Rigth
	};
	
	Direction curDir;
	
	void move(MoveDirection);
};