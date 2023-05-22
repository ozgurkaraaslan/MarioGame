#pragma once
#include "Common.h"
#include "Object.h"

class Turtle : public Object {
	
	float vx, vy;
	
public:
	Clock clock;
	float elapsedTime = clock.getElapsedTime().asSeconds();
	enum MoveDirection {
		Left,
		Rigth
	};
	Turtle();
	void move(MoveDirection);
	void jump(bool down);
	void fall();
	void pipeTeleport();
	
	
};