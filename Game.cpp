#include "Game.h"



Game::Game() {
	mWindow = new RenderWindow(VideoMode::getDesktopMode(), "SpaceShooter");
}

void Game::Runloop() {
	while (mWindow->isOpen()) {
		//Run game loop
		ProcessInput();
	}
}

void Game::ShutDown() {
	//Shutdown on key press
	mWindow->~RenderWindow();
	
}

void Game::ProcessInput() {
	while (mWindow->pollEvent(mEvent)) {
		if (mEvent.type == Event::KeyPressed)
		{
			if (mEvent.key.code == Keyboard::Escape) {
				ShutDown();
			}
		}
	}
}
void Game::UpdateGame() {

}

void Game::GenerateOutput(){
}