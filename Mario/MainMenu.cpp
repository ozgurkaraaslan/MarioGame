#include "MainMenu.h"



MainMenu::MainMenu() {
	if (!font.loadFromFile("../assets/font.ttf"))
	{
		cout << "Couldn't load font";
	}
	//set font for text
	text.setFont(font);
	//set name
	text.setString("MARIO");
	//set size
	text.setCharacterSize(100);
	//set color
	text.setFillColor(Color::Red);
}
void MainMenu::checkEntry() {



}
void MainMenu::draw(RenderWindow* window) {

	window->draw(text);


}