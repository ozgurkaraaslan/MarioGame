#include "MainMenu.h"
#include "Common.h"



MainMenu::MainMenu() {
	bool startGame = true;
	
	if (!font.loadFromFile("../assets/font.ttf"))
	{
		cout << "Couldn't load font";
	}
	//set font for text
	title.setFont(font);
	//set name
	title.setString("MARIO");
	//set size
	title.setCharacterSize(100);
	//set color
	title.setFillColor(Color::Red);
	//set pos.
	title.setPosition(WINDOW_WIDTH * 0.35, WINDOW_HEIGHT * 0.35);

	menu.setFont(font);
	menu.setString("Press enter to start game");
	menu.setCharacterSize(30);
	menu.setFillColor(Color::White);
	menu.setPosition(WINDOW_WIDTH * 0.25, WINDOW_HEIGHT * 0.55);
	
}

void MainMenu::draw(RenderWindow &window) {

	window.draw(title);
	window.draw(menu);
	window.display();

}