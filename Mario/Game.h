#include "Common.h"

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
public:
	Game(int);
	void update(void);
	void drawBackground();
};
