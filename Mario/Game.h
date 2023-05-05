#include "Common.h"

class Game {
	RenderWindow* window;
	Texture bgTexture;
	Sprite bgSprite;
	int speed;
public:
	Game(int);
	void update(void);
};
