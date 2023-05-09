#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define WINDOW_WIDTH	1000
#define WINDOW_HEIGHT	1000
#define SPEED			10
#define NUM_BRICKS      76

const int brick_nums[4] = { 28, 16, 8, 24 };
const float brick_rows[4] = {250, 450, 490, 660};