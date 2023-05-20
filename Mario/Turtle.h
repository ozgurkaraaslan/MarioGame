#pragma once
#include "Common.h"
#include "Object.h"

class Turtle : public Object {

	float vx, vy;
	Int32 time;
	
public:
	enum MoveDirection {
		Left,
		Rigth
	};
	Direction curDir,prevDir;
	Turtle();
	void move(MoveDirection);
	void jump(bool down);
	void fall();
	void pipeTeleport();
	
	
};