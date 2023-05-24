#pragma once
#include "Common.h"
class Scoreboard {
	
	std::stringstream scoreString;
public:
	Scoreboard();
	Text scoreText;
	Font font;

	int score = 0;
	void scoreSetter();
	void draw(RenderWindow& window);


};