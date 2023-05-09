#include "Mario.h"

Mario::Mario() {

	char path[64];

	for (int i = 0; i < 7; i++)
	{
		sprintf(path, "../assets/mario%d.png", i+1);
		textures[i].loadFromFile(path);
	}

	vx = 0;
	vy = 0;
	state = 0;
	sprite.setTexture(textures[state]);

}
void Mario::move(){

}

