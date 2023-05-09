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

	Texture floorTexture;
	Sprite floorSprite;

	Texture pipeLeftTexture;
	Sprite pipeLeftSprite;

	Texture pipeRightTexture;
	Sprite pipeRightSprite;

	Texture pipeSRightTexture;
	Sprite pipeSRightSprite;

	Texture pipeSLeftTexture;
	Sprite pipeSLeftSprite;

	Brick* bricks;
	Pipe* pipes;
	PipeS* pipeSs;
	Floor* floor;

public:
	Game(int);
	void update(void);
	void drawBackground();
};
