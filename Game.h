#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Game
{
private:

	bool mIsRunning;
	Vector2u w_size;

	void ProcessInput();
	void UpdateGame(Time& elapsedTime);
	void GenerateOutput();

	RenderWindow mWindow;
	Time elapsedTime;
	Clock clock;
	Player* player;
	

public:
	
	Game();
	bool Initialize();
	void Runloop();
	void ShutDown();

};

