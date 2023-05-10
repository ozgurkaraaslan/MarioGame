#include"Brick.h"

Brick::Brick() {	//init brick constructor

	texture.loadFromFile("../assets/brick.png");
	sprite.setTexture(texture);
}