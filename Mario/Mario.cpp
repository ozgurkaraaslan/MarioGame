#include "Mario.h"

Mario::Mario() {

	char path[64];

	for (int i = 0; i < 7; i++)
	{
		sprintf(path, "../assets/mario%d.png", i);
		textures[i].loadFromFile(path);
	}

	state = 0;
	sprite.setTexture(textures[state]);

}

