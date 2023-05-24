#include "Object.h"

void Object::setPosition(Vector2f pos) { // setPosition method

	sprite.setPosition(pos);
}

void Object::draw(RenderWindow &window) {  // draw method

	window.draw(sprite);

}
void Object::edgeHit() {	// edgeHit class to check exceeding left and right bounds of the window

	if (sprite.getPosition().x >= WINDOW_WIDTH) {
		sprite.setPosition(10,sprite.getPosition().y);
	}
	else if (sprite.getPosition().x <=0)
	{
		sprite.setPosition(WINDOW_WIDTH-10, sprite.getPosition().y);
	}
}