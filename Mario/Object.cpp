#include "Object.h"

void Object::setPosition(Vector2f pos) {

	sprite.setPosition(pos);
}

void Object::draw(RenderWindow& window) {

	window.draw(sprite);

}