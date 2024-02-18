#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Character
{
private:
	
protected:
	Vector2f mPosition;
	float mVelocity;

	Sprite mSprite;

public:
	Character(Vector2f pos, Texture& tex);
	void draw(RenderTarget& target);
};

