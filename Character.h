#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Character
{
private:
	
protected:
	Vector2f mPosition;
	Vector2f mVelocity;

	Sprite mSprite;

public:
	Character(Vector2f pos, Texture& tex);
	void updatePosition(float deltaTime, Vector2u win_size);
	void updateVelocity(Vector2f newVel);
	Vector2f getVelocity();
	Vector2f getPosition();
	FloatRect getGlobalBounds();
	void draw(RenderTarget& target);
};

