#pragma once
#include "Game.h"
#include <iostream>


int main(){

	Game game;
	bool success = game.Initialize();

	if (success) {
		game.Runloop();
	}

	game.ShutDown();
	return 0;
}