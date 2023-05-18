#pragma once
#include"../Common.h"
//defining base class for the background
class Background : public sf::Sprite {
protected:
	Vector2f pos;	//all bacjground objects have a position that will be private when inherited
	sf::FloatRect m_hitbox;
public:
	Texture texture;	//all bacjground objects are textures and sprites
	Sprite sprite;
	void setPosition(Vector2f);		//all bacjground objects have setPosition  & draw & setScale attiributes
	void draw(RenderWindow*);
	void setScale(float, float);

	void setHitbox(const sf::FloatRect& hitbox) {
		m_hitbox = hitbox;
	}
	/// gets the hitbox (use this instead of getGlobalBounds())
	sf::FloatRect getGlobalHitbox() const {
		return getTransform().transformRect(m_hitbox);
	}
};
