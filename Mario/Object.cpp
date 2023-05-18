#include "Object.h"

void Object::setPosition(Vector2f pos) {

	sprite.setPosition(pos);
}

void Object::draw(RenderWindow &window) {

	window.draw(sprite);

}
void Object::edgeHit() {
	if (sprite.getPosition().x >= WINDOW_WIDTH) {
		sprite.setPosition(10,sprite.getPosition().y);
	}
	else if (sprite.getPosition().x <=0)
	{
		sprite.setPosition(WINDOW_WIDTH-10, sprite.getPosition().y);
	}


}