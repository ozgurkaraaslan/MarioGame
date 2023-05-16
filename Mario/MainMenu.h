#include "Common.h"
class MainMenu {
public:
	Font font;
	Text title;
	Text menu;
	MainMenu();
	void draw(RenderWindow &window);
	bool startGame = true;


};
 

