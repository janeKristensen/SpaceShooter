#include "Game.h"
#include <iostream>


Game::Game() {
	mIsRunning = true;
	player = nullptr;
}

bool Game::Initialize() {
	mWindow.create(VideoMode(800, 800), "SpaceShooter");
	w_size = mWindow.getSize();

	Texture tex;
	tex.loadFromFile("player.png");

	player = new Character(Vector2f(200, 200), tex);

	if (!player) {

		return false;
	}
	else return true;
}

void Game::Runloop() {

	while (mIsRunning) {
		elapsedTime = clock.restart();
		//Run game loop
		ProcessInput();
		UpdateGame(elapsedTime);
		GenerateOutput();
	}
}

void Game::ShutDown() {
	//Shutdown on key press
	mWindow.~RenderWindow();
	player = nullptr;
	delete player;
}

void Game::ProcessInput() {
	Event event;

	while (mWindow.pollEvent(event)) {

		if (event.type == Event::KeyPressed) {

			switch (event.key.code) {
			case Keyboard::Escape:
				mIsRunning = false;
				break;
			case Keyboard::A:
				player->updateVelocity(Vector2f(-1, 0));
				break;
			case Keyboard::D:
				player->updateVelocity(Vector2f(1, 0));
				break;
			case Keyboard::W:
				player->updateVelocity(Vector2f(0, -1));
				break;
			case Keyboard::S:
				player->updateVelocity(Vector2f(0, 1));
				break;
			}
		}
		else if (event.type == Event::Closed) {
			mIsRunning = false;
			break;
		}
	}
}

void Game::UpdateGame(Time& elapsedTime) {

	/*while (!(elapsedTime.asMilliseconds() >= 16))
	{
		;
	}*/

	float deltaTime = elapsedTime.asSeconds();

	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
	}

	if (player->getVelocity() != Vector2f(0, 0)) {
		Vector2u win_pos = mWindow.getSize();
		player->updatePosition(deltaTime, win_pos);

		
	}
}

void Game::GenerateOutput(){

		float w_width = w_size.x;
		float w_height = w_size.y;

		RectangleShape c_background(Vector2f(w_width, w_height));
		c_background.setFillColor(Color::Color(0, 100, 0, 100));

		mWindow.clear();
		mWindow.draw(c_background);
		player->draw(mWindow);
		mWindow.display();
}