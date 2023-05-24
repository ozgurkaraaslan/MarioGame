#pragma once
#include "Common.h"
class Scoreboard {  // Scoreboard class

	Text scoreText;
	Font font;
	std::stringstream scoreString;
public:
	Scoreboard();
	int score = 0;
	void scoreSetter();
	void draw(RenderWindow& window);
};