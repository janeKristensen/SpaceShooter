#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
private:

	bool mIsRunning;

	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	RenderWindow* mWindow;
	

public:
	
	Game();
	bool Initialize();
	void Runloop();
	void ShutDown();

};

