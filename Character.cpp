#include "Character.h"

Character::Character(Vector2f pos, Texture& tex){
	mPosition = pos;
	mVelocity = Vector2f(0, 0);
	mSprite.setTexture(tex);
	mSprite.setPosition(mPosition);
}

void Character::updatePosition(float deltaTime, Vector2u win_size) {

	float pX = mPosition.x + mSprite.getGlobalBounds().width;
	float pY = mPosition.y + mSprite.getGlobalBounds().height;

	if (pX >= win_size.x && mPosition.y <= 0) {
		mVelocity = Vector2f(-0.01, 0.01);
	}
	else if (pX >= win_size.x && pY >= win_size.y) {
		mVelocity = Vector2f(-0.01, -0.01);
	}
	else if (pY >= win_size.y && mPosition.x <= 0) {
		mVelocity = Vector2f(0.01, -0.01);
	}
	else if (mPosition.x <= 0 && mPosition.y <= 0) {
		mVelocity = Vector2f(0.01, 0.01);
	}
	else if (pX >= win_size.x && win_size.y > 0) {
		mVelocity= Vector2f(-0.01, 0.01);
	}
	else if (pX >= win_size.x && pY <= win_size.y) {
		mVelocity= Vector2f(-0.01, -0.01);
	}
	else if (pY >= win_size.y && win_size.x >= 0) {
		mVelocity = Vector2f(0.01, -0.01);
	}
	else if (mPosition.x <= 0 || mPosition.y <= 0) {
		mVelocity = Vector2f(0.01, 0.01);
	}

	mPosition.x += mVelocity.x * 500.f * deltaTime;
	mPosition.y += mVelocity.y * 500.f * deltaTime;
	mSprite.setPosition(mPosition);
}

void Character::updateVelocity(Vector2f newVel) {
	mVelocity = newVel;
}

Vector2f Character::getVelocity() {
	return mVelocity;
}

Vector2f Character::getPosition() {
	return mSprite.getPosition();
}

FloatRect Character::getGlobalBounds() {
	return mSprite.getGlobalBounds();
}

void Character::draw(RenderTarget& target) {
	target.draw(mSprite);
}