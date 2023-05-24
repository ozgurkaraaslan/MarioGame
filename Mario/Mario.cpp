#include "Mario.h"

Mario::Mario() {	// Mario constructor

	char path[64];

	for (int i = 0; i < 7; i++)	//storing mario textures on a array
	{
		sprintf(path, "../assets/mario%d.png", i+1);
		textures[i].loadFromFile(path);
	}

	vx = 0;
	vy = 0;
	state = 0;
	curDir = LI;	//ýdle but left facing
	prevDir = LI;	//RI would be idle but right facing
}

void Mario::move(MoveDirection dir) {

	prevDir = curDir;
	vx = 8.f;

	switch (state) {
	case 0:	//mario is idle but is going to start moving
		if (dir == Left) {	//movement to the left
			state = 1;
			curDir = L;
			sprite.move(Vector2f(-vx, 0));
		}
		else if (dir == Rigth) {	//movement to the right
			state = 1;
			curDir = R;
			sprite.move(Vector2f(vx, 0));
		}
		break;
	case 1:	//first state of mario animation
		if (dir == Left) {
			state = 2;
			curDir = L;
			sprite.move(Vector2f(-vx, 0));
		}
		else if (dir == Rigth) {
			state = 2;
			curDir = R;
			sprite.move(Vector2f(vx, 0));
		}
		else if (dir == Idle) {	//movement is cancelled
			state = 0;
			if (prevDir == L || prevDir == LI)
				curDir = LI;
			else
				curDir = RI;
		}
		break;
	case 2:
		if (dir == Left) {
			state = 3;
			curDir = L;
			sprite.move(Vector2f(-vx, 0));
		}
		else if (dir == Rigth) {
			state = 3;
			curDir = R;
			sprite.move(Vector2f(vx, 0));
		}
		else if (dir == Idle) {
			state = 0;
			if (prevDir == L || prevDir == LI)
				curDir = LI;
			else
				curDir = RI;
		}
		break;
	case 3:
		if (dir == Left) {
			state = 1;
			curDir = L;
			sprite.move(Vector2f(-vx, 0));
		}
		else if (dir == Rigth) {
			state = 1;
			curDir = R;
			sprite.move(Vector2f(vx, 0));
		}
		else if (dir == Idle) {
			state = 0;
			if (prevDir == L || prevDir == LI)
				curDir = LI;
			else
				curDir = RI;
		}
		break;
	default:
		state = 0;
		if (prevDir == L || prevDir == LI)
			curDir = LI;
		else
			curDir = RI;
	}

	if (curDir != prevDir) { //checks for the direction to correct the facing of the animation
		if (curDir == R && prevDir  != RI) {
			sprite.setScale(-1.f, 1.f);
			sprite.move(Vector2f(float(textures[state].getSize().x), 0)); //moving the sprite  back because when you turn it . it moves
		}
		else if (curDir == L && prevDir != LI) {
			sprite.setScale(1.f, 1.f);
			sprite.move(Vector2f(float(-1.f * textures[state].getSize().x), 0));
		}
	}
	
	sprite.setTexture(textures[state]);
}

void Mario::jump(bool down) {

	if (down) {	//falling down edge
		if (vy < 11) {
			vy += 0.7;
		}
		
		sprite.move(Vector2f(0, vy));
		sprite.setTexture(textures[state]);
	}
	else {	//jumping
		if (vy < 11) {
			vy += 0.7;
		}

		if (prevDir == R && curDir == R)
			vx = 3.5f;
		else if (prevDir == L && curDir == L)
			vx = -3.5f;
		else
			vx = 0.f;
		state = 5;
		sprite.move(Vector2f(vx, vy));
		sprite.setTexture(textures[state]);
		
	}
}

void Mario::fall() {	// Mario fall due to dying
	
	state = 6;
	sprite.move(Vector2f(0, 10));
	sprite.setTexture(textures[state]);
}
