#include"Brick.h"

Brick::Brick() {

	texture.loadFromFile("../assets/brick.png");
	sprite.setTexture(texture);
}