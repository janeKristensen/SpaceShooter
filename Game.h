#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	RenderWindow* mWindow;
	Event mEvent;


public:
	Game();
	void Runloop();
	void ShutDown();
};

