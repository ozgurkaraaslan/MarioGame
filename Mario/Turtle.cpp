#include "Turtle.h"

Turtle::Turtle() {

	char path[64];

	for (int i = 0; i < 5; i++)
	{
		sprintf(path, "../assets/turtle%d.png", i + 1);
		textures[i].loadFromFile(path);
	}

	vx = 0;
	vy = 0;
	state = 0;
	sprite.setTexture(textures[state]);

}
void Turtle::move() {

}

