#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object  {
	
	
public:
	float vx;
	float vy=0;
	Mario();
	void jump(bool down); 
	void fall();
	enum MoveDirection {
		Up,
		Left,
		Rigth,
		Idle
	};
	
	Direction curDir;
	void move(MoveDirection);
};