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
	Direction curDir = L;
	Direction prevDir = L;
	sprite.setTexture(textures[state]);

}

void Mario::move(MoveDirection dir){

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
		break;
	}


	if (curDir != prevDir) {
		if (curDir == R) {
			sprite.setScale(-1.f, 1.f);
			sprite.move(Vector2f(float(textures[state].getSize().x), 0));
		}
		else if (curDir == L) {
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
		sprite.move(Vector2f(0, -70));
		sprite.setTexture(textures[state]);
	}
}
/*
void Mario::fall() {
	
	state = 6;
	sprite.move(Vector2f(0, -50));
	sprite.setTexture(textures[state]);

	while (sprite.getPosition().x < WINDOW_HEIGHT+40) {
		sprite.move(Vector2f(0, 20));
	}
}*/
