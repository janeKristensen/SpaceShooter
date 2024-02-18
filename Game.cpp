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
	
	player = new Player(Vector2f(200, 200), tex);
	
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
		
		switch (event.type) {
			
			case Event::KeyPressed:
				switch (event.key.code) {

					case Keyboard::Escape:
						mIsRunning = false;
						break;
				}
			case Event::Closed:
				mIsRunning = false;
				break;
		}
	}	
}

void Game::UpdateGame(Time& elapsedTime) {
	std::cout << elapsedTime.asMilliseconds();
	std::cout << "here";
	/*while (!(elapsedTime.asMilliseconds() >= 16))
	{
		;
	}*/
	
	float deltaTime = elapsedTime.asSeconds();

	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
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