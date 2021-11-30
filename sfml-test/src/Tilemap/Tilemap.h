#pragma once

#include <SFML/Graphics.hpp>

class Player;

#include "Blocks/Block.h"

using namespace sf;

//-----------
	//IDs:
	// 0- Blank - Walkable
	// 1- Center
	// 2- Left
	// 3- Up
	// 4- Right
	// 5- Down
	// 6- Objective
	//-----------

struct Vector2K{
	int x;
	int y;
};
	struct Tile
	{
		sf::RectangleShape rec; 
		Vector2K pos;
		int id;
		bool winSlot;
		sf::Sprite sprite;
	};

class Tilemap{
private:
	const int maxTLX = 18;
	const int maxTLY = 9;
	sf::Texture atlas[7];

public:
	Block* blocks[10];
	Tile board[9][18]; //Tilemap is x = 18, y = 9 TOTAL: 162
	Tilemap();
	~Tilemap();
	void initTile();
	void LoadAtlas();
	void LoadSprites();
	void draw(sf::RenderWindow& win);


	void clearBoard();
	void levelOne(Player* p1);
	void levelOneWincon();
	void levelTwo(Player* p1);
	void levelTwoWincon();



};
