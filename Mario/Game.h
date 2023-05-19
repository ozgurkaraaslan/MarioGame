#include "Common.h"
#include "backgroundObjects/Brick.h"
#include "backgroundObjects/Pipe.h"
#include "backgroundObjects/PipeS.h"
#include "backgroundObjects/Floor.h"
#include "Mario.h"
#include "Turtle.h"
#include "MainMenu.h"

class Game {
	RenderWindow* window;
	int speed;

	Brick* bricks;
	Pipe* pipes;
	PipeS* pipeSs;
	Floor* floor;
	Mario mario;
	Turtle* turtles;
	MainMenu mainMenu;
	float elapsedTime;
	Clock clock;
	int turtleNumber = 1;
public:
	Game(int);
	void update(void);
	void drawBackground();
	bool onFLoor(Object &obj);
};
