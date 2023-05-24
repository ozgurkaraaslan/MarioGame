#include "Common.h"
class MainMenu {
	Font font;
	Text title;
	Text menu;
public:
	MainMenu();
	void draw(RenderWindow &window);
	bool startGame = true;
};
 

