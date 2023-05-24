#include "Heads.h"


Heads::Heads() {//set texture and sprites


	if (!texture.loadFromFile("../assets/mariohead.png"))
	{
		cout << "Couldn't load font";
	}
	sprite.setTexture(texture);

}

void Heads::draw(RenderWindow& window) {	//draws head

	window.draw(sprite);
}


void Heads::setPosition(Vector2f pos) {	//sets the position of sprites

	this->pos = pos;
	sprite.setPosition(pos);

}