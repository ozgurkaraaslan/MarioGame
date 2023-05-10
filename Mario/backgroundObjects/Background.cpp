#include"Background.h"
//init attiributes of background objects
void Background::setPosition(Vector2f pos) {	//sets the position of sprites

	this->pos = pos;
	sprite.setPosition(pos);

}

void Background::setScale(float a, float b) {	//set the scale of sprites & can be used to flip objects

	sprite.setScale(a, b);

}

void Background::draw(RenderWindow* window) {	//draws background objects

	window->draw(sprite);


}