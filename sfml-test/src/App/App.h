#pragma once

#include <SFML/Graphics.hpp>

#include "Player/player.h"
#include "Tilemap/tilemap.h"
#include "Menu/menu.h"
#include "Timer/theomer.h"

using namespace sf;

class App {
private:
	sf::RenderWindow window;
	enum class Screens
	{
		Menu = 0, Gameplay, GameOver, Credits
	};
	Screens currentScreen;
	Player* player;
	Tilemap* TM;
	Menu* menu;
	Theomer clock; //TheoLeyenda:tm: gracias guapo <3
	//vector<int> test;
	
	
public:
	App();
	~App();
	void LoopApp();

	void Draw(sf::RenderWindow &win);
	void Input(RenderWindow& win);
};
