#include "Turtle.h"

Turtle::Turtle() {

	char path[64];

	for (int i = 0; i < 5; i++)
	{
		sprintf(path, "../assets/turtle%d.png", i + 1);
		textures[i].loadFromFile(path);
	}

	vx = 6; //set initial speed in spawn
	vy = 0;
	state = 0;
	sprite.setTexture(textures[state]);

	Direction curDir = R;
	Direction prevDir = R;

}
void Turtle::move(MoveDirection dir) {

	prevDir = curDir;

	switch (state)
	{
	case 0:
		if (dir == Rigth) {
			sprite.move(float(vx), 0);
			state=1;
			curDir = R;
		}
		else if (dir == Left)
		{
			sprite.move(float(-vx), 0);
			state = 1;
			curDir = L;
		}
		break;
	case 1:
		if (dir == Rigth) {
			sprite.move(float(vx), 0);
			state = 2;
			curDir = R;
		}
		else if (dir == Left)
		{
			sprite.move(float(-vx), 0);
			state = 2;
			curDir = L;
		}
		break;
	case 2:
		if (dir == Rigth) {
			sprite.move(float(vx), 0);
			state = 0;
			curDir = R;
		}
		else if (dir == Left)
		{
			sprite.move(float(-vx), 0);
			state = 0;
			curDir = L;
		}
		break;
	
	}

	if (prevDir != curDir) {
		if (curDir == L) {
			sprite.setScale(-1.f, 1.f);
			sprite.move(Vector2f(float(textures[state].getSize().x), 0));
		}
		else if (curDir == R) {
			sprite.setScale(1.f, 1.f);
			sprite.move(Vector2f(float(-1.f * textures[state].getSize().x), 0));
		}
	}

	sprite.setTexture(textures[state]);
	
}
void Turtle::jump(bool down) { // turtle falls down edge
	if (down) {
		sprite.move(Vector2f(0, 10));
		sprite.setTexture(textures[state]);
	}
}



void Turtle::fall() {


}