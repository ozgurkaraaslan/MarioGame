#include "Common.h"
#include "Brick.h"
#include "Pipe.h"
#include "PipeS.h"
#include "Floor.h"

class Game {
	RenderWindow* window;
	//Texture bgTexture;
	//Sprite bgSprite;
	int speed;

	Brick* bricks;
	Pipe* pipes;
	PipeS* pipeSs;
	Floor* floor;

public:
	Game(int);
	void update(void);
	void drawBackground();
};
