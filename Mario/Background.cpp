#include"Background.h"

void Background::setPosition(Vector2f pos) {

	this->pos = pos;
	sprite.setPosition(pos);

}

void Background::setScale(float a, float b) {

	sprite.setScale(a, b);

}

void Background::draw(RenderWindow* window) {

	window->draw(sprite);


}