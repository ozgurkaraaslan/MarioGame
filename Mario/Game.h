#include "Common.h"
#include "backgroundObjects/Brick.h"
#include "backgroundObjects/Pipe.h"
#include "backgroundObjects/PipeS.h"
#include "backgroundObjects/Floor.h"
#include "Mario.h"
#include "Turtle.h"

class Game {
	RenderWindow* window;
	int speed;

	Brick* bricks;
	Pipe* pipes;
	PipeS* pipeSs;
	Floor* floor;
	Mario mario;
	Turtle* turtles;

public:
	Game(int);
	void update(void);
	void drawBackground();
};
