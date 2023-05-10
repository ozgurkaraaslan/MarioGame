#include"Floor.h"

Floor::Floor() {	//init. Floor constructor

	texture.loadFromFile("../assets/floor.png");
	sprite.setTexture(texture);
}