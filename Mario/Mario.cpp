#include "Mario.h"

Mario::Mario() {

	char path[64];

	for (int i = 0; i < 7; i++)
	{
		sprintf(path, "../assets/mario%d.png", i+1);
		textures[i].loadFromFile(path);
	}

	vx = 10;
	vy = 0;
	state = 0;
	Direction curDir = LI;
	Direction prevDir = LI;
}

void Mario::move(MoveDirection dir) {

	prevDir = curDir;

	switch (state) {
	case 0:
		if (dir == Left) {
			state = 1;
			curDir = L;
			sprite.move(Vector2f(float(-vx), 0));
		}
		else if (dir == Rigth) {
			state = 1;
			curDir = R;
			sprite.move(Vector2f(float(vx), 0));
		}
		break;
	case 1:
		if (dir == Left) {
			state = 2;
			curDir = L;
			sprite.move(Vector2f(-float(vx), 0));
		}
		else if (dir == Rigth) {
			state = 2;
			curDir = R;
			sprite.move(Vector2f(float(vx), 0));
		}
		else if (dir == Idle) {
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
			sprite.move(Vector2f(-float(vx), 0));
		}
		else if (dir == Rigth) {
			state = 3;
			curDir = R;
			sprite.move(Vector2f(float(vx), 0));
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
			sprite.move(Vector2f(-float(vx), 0));
		}
		else if (dir == Rigth) {
			state = 1;
			curDir = R;
			sprite.move(Vector2f(float(vx), 0));
		}
		else if (dir == Idle) {
			state = 0;
			if (prevDir == L || prevDir == LI)
				curDir = LI;
			else
				curDir = RI;
		}
		break;
	}

	if (curDir != prevDir) {
		if (curDir == R && prevDir  != RI) {
			sprite.setScale(-1.f, 1.f);
			sprite.move(Vector2f(float(textures[state].getSize().x), 0));
		}
		else if (curDir == L && prevDir != LI) {
			sprite.setScale(1.f, 1.f);
			sprite.move(Vector2f(float(-1.f * textures[state].getSize().x), 0));
		}
	}
	
	sprite.setTexture(textures[state]);
}

void Mario::jump(bool down) {

	if (down) {
		sprite.move(Vector2f(0, 10));
		sprite.setTexture(textures[state]);
	}
	else {
		vy += 0.000002;
		sprite.move(Vector2f(0, vy));
		sprite.setTexture(textures[state]);
	}
}

void Mario::fall() {
	
	state = 6;
	sprite.setTexture(textures[state]);
	sprite.move(Vector2f(0, 20));
}
