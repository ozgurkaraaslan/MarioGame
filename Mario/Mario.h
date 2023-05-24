#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object  {  // Mario class
	
public:
	int remainingLives = 3;
	float vx,vy=0;
	Mario();
	void jump(bool down); 
	void fall();
	enum MoveDirection {
		Up,
		Left,
		Rigth,
		Idle
	};
	
	void move(MoveDirection);
};