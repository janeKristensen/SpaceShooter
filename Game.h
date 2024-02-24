#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

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
	Character* player;
	

public:
	
	Game();
	bool Initialize();
	void Runloop();
	void ShutDown();

};

