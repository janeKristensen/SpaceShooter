#include "Game.h"



Game::Game() {
	mWindow = new RenderWindow(VideoMode(800, 800), "SpaceShooter");
}

void Game::Runloop() {
	while (mWindow->isOpen()) {
		//Run game loop
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ShutDown() {
	//Shutdown on key press
	mWindow->~RenderWindow();
	
}

void Game::ProcessInput() {
	Event event;

	while (mWindow->pollEvent(event)) {
		switch (event.type) {

			case Event::KeyPressed:
				switch (event.key.code) {

					case Keyboard::Escape:
						ShutDown();
				}
			case Event::Closed:
				ShutDown();
		}
	}
}

void Game::UpdateGame() {

}

void Game::GenerateOutput(){

	//Vector2u w_size = mWindow.getSize();
	float w_width = 800;
	float w_height = 800;

	RectangleShape c_background(Vector2f(w_width, w_height));
	c_background.setFillColor(Color::Color(255, 255, 255, 255));

	mWindow->clear();
	mWindow->draw(c_background);
	mWindow->display();
}