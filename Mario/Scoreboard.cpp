#include "Common.h"
#include "Scoreboard.h"

Scoreboard::Scoreboard() {

	if (!font.loadFromFile("../assets/font.ttf"))
	{
		cout << "Couldn't load font";
	}
	scoreText.setFont(font);


}

void Scoreboard::scoreSetter() { // when called within game.cpp it will increment score and change it accordingly

	score += 100;
	scoreString << "0" << score; // we use stringstream here to convert score into string
	scoreText.setString(scoreString.str().c_str());
	scoreText.setPosition(10, 10);
	scoreString.str("");
	scoreString.clear();
}
void Scoreboard::draw(RenderWindow& window) {

	window.draw(scoreText);
}
