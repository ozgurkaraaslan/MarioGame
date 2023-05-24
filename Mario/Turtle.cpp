#include "Turtle.h"

Turtle::Turtle() {  // Turtle constructor

	char path[64];

	for (int i = 0; i < 5; i++)	//storing textures on a array
	{
		sprintf(path, "../assets/turtle%d.png", i + 1);
		textures[i].loadFromFile(path);
	}

	vx = 1.5; //set initial speed in spawn
	vy = 0;
	state = 0;
	sprite.setTexture(textures[state]);

	curDir = R;
	prevDir = R;

}
void Turtle::move(MoveDirection direction) {  // Turtle move method

	dir = direction;
	prevDir = curDir;
	if (clock.getElapsedTime().asSeconds() - elapsedTime > 6) {
		vx += 0.2;
		elapsedTime = clock.getElapsedTime().asSeconds();
	}
	switch (state)	
	{
	case 0:		//depending on spawn position turtle will continue on same direction also there is no idle animation
		if (dir == Rigth) {
			sprite.move(float(vx), 0);
			state=1;
			curDir = R;
		}
		else if (dir == Left)
		{
			sprite.move(float(-vx), 0);
			state = 1;
			curDir = L;
		}
		break;
	case 1:
		if (dir == Rigth) {
			sprite.move(float(vx), 0);
			state = 2;
			curDir = R;
		}
		else if (dir == Left)
		{
			sprite.move(float(-vx), 0);
			state = 2;
			curDir = L;
		}
		break;
	case 2:
		if (dir == Rigth) {
			sprite.move(float(vx), 0);
			state = 0;
			curDir = R;
		}
		else if (dir == Left)
		{
			sprite.move(float(-vx), 0);
			state = 0;
			curDir = L;
		}
		break;
	}

	if (prevDir != curDir) {
		if (curDir == L) {
			sprite.setScale(-1.f, 1.f);
			sprite.move(Vector2f(float(textures[state].getSize().x), 0));
		}
		else if (curDir == R) {
			sprite.setScale(1.f, 1.f);
			sprite.move(Vector2f(float(-1.f * textures[state].getSize().x), 0));
		}
	}

	sprite.setTexture(textures[state]);
}
void Turtle::jump(bool down) {  // turtle falls down edge
	if (down) {
		sprite.move(Vector2f(0, 8));
		sprite.setTexture(textures[state]);
	}
}

void Turtle::pipeTeleport() {  // method for teleporting between pipes

	if (sprite.getPosition().x <= 138.f && sprite.getPosition().y>=700) { //checks if turtles are inside the floor pipes to teleport them 
		sprite.setPosition(Vector2f(862.f, 105.f));

	}
	else if (sprite.getPosition().x >= 862.f && sprite.getPosition().y >= 700) {
		sprite.setPosition(Vector2f(138.f, 105.f));

	}
}

void Turtle::fall() {	// turtle fall due to dying

	state = 4;
	sprite.move(Vector2f(0, 10));
	sprite.setTexture(textures[state]);
}


