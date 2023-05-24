#pragma once
#include "Common.h"
#include "backgroundObjects/Brick.h"
#include "backgroundObjects/Pipe.h"
#include "backgroundObjects/PipeS.h"
#include "backgroundObjects/Floor.h"
#include "Mario.h"
#include "Turtle.h"
#include "MainMenu.h"
#include "Scoreboard.h"
#include "Heads.h"

class Game {	// Game class
	RenderWindow* window;
	int speed;
	Text textOver;
	Font font;
	Brick* bricks;
	Pipe* pipes;
	PipeS* pipeSs;
	Floor* floor;
	Mario mario;
	Scoreboard scoreboard;
	Turtle* turtles;
	MainMenu mainMenu;
	Heads *heads;
	float elapsedTime;
	Clock clock;
	int turtleNumber = 1;
	bool jumpFlag = false;
	bool checkCollusionFlag = false;
	bool rebornFlag = true;
	bool turtleDeadFlag = false;
	int deadTurtleIndice = -1;
	void turtleCollusion(int);
	int collidedTurtleOne, collidedTurtleTwo;
	bool onFLoor(Object& obj);		//checks if mario is on top of floors/bricks/pipe
	bool checkCollusion(int& side);	//checks if mario hit a turtle
	bool underFloor(Mario& mario);	//checks if mario hit his head under bricks
	void gameOver(bool finishType);
public:
	Game(int);
	void update(void);
	void drawBackground();			//draws backgrounds
	
};
