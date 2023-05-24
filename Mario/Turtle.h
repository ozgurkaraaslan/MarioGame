#pragma once
#include "Common.h"
#include "Object.h"

class Turtle : public Object {  // Turtle class
	
	float vx, vy;
	Clock clock;
	float elapsedTime = clock.getElapsedTime().asSeconds();
	
public:
	enum MoveDirection {
		Left,
		Rigth
	};
	MoveDirection dir;
	Turtle();
	void move(MoveDirection);
	void jump(bool down);
	void fall();
	void pipeTeleport();
};