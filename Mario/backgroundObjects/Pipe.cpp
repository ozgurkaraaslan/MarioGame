#include"Pipe.h"

Pipe::Pipe() { //init. pipe constructor
	texture.loadFromFile("../assets/pipe.png");
	sprite.setTexture(texture);

}