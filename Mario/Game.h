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
	bool jumpFlag = false;
	bool checkCollusionFlag = false;
	bool rebornFlag = true;
public:
	Game(int);
	void update(void);
	void drawBackground();			//draws backgrounds
	bool onFLoor(Object &obj);		//checks if mario is on top of floors/bricks/pipe
	bool checkCollusion(int& side);	//checks if mario hit a turtle
	bool underFloor(Mario& mario);	//checks if mario hit his head under bricks
};
