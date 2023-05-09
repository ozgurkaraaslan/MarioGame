#include"Brick.h"

Brick::Brick() {
	texture.loadFromFile("../assets/brick.png");
	sprite.setTexture(texture);

}

void Brick::setPosition(Vector2f pos) {

	this->pos = pos;
	sprite.setPosition(pos);

}

void Brick::draw(RenderWindow *window) {

	window->draw(sprite);


}