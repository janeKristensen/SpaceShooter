#include "Character.h"

Character::Character(Vector2f pos, Texture& tex){
	mPosition = pos;
	mVelocity = 2;
	mSprite.setTexture(tex);
	mSprite.setPosition(mPosition);
}

void Character::draw(RenderTarget& target) {
	target.draw(mSprite);
}