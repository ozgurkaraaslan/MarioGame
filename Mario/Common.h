#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define WINDOW_WIDTH	1000
#define WINDOW_HEIGHT	1000
#define SPEED			50
#define NUM_BRICKS      76
#define MAX_TURTLE_NUMBER 5

const int brick_nums[4] = { 28, 16, 8, 24 };
const float brick_rows[4] = {250, 450, 490, 660};