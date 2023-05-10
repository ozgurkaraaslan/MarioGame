#pragma once
#include"../Common.h"
//defining base class for the background
class Background {
protected:
	Vector2f pos;	//all bacjground objects have a position that will be private when inherited
public:
	Texture texture;	//all bacjground objects are textures and sprites
	Sprite sprite;
	void setPosition(Vector2f);		//all bacjground objects have setPosition  & draw & setScale attiributes
	void draw(RenderWindow*);
	void setScale(float, float);
};
