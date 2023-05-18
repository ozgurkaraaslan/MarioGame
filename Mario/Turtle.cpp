#include "Turtle.h"

Turtle::Turtle() {

	char path[64];

	for (int i = 0; i < 5; i++)
	{
		sprintf(path, "../assets/turtle%d.png", i + 1);
		textures[i].loadFromFile(path);
	}

	vx = 10; //set initial speed in spawn
	vy = 0;
	state = 0;
	sprite.setTexture(textures[state]);
	dir = R;

}
void Turtle::move() {
	switch (state)
	{
	case 0:
		if (dir == R) {
			sprite.move(float(vx), 0);
			state=1;
			}
		else if (dir==L)
		{
			sprite.move(float(-vx), 0);
			state = 1;
		}
		break;
	case 1:
		if (dir == R) {
			sprite.move(float(vx), 0);
			state = 2;
		}
		else if (dir == L)
		{
			sprite.move(float(-vx), 0);
			state = 2;
		}
		break;
	case 2:
		if (dir == R) {
			sprite.move(float(vx), 0);
			state = 0;
		}
		else if (dir == L)
		{
			sprite.move(float(-vx), 0);
			state =0;
		}
		break;
	
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