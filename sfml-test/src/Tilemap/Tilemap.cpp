#include "tilemap.h"
#include "Player/Player.h"

Tilemap::Tilemap()
{
	for (int i = 0; i < 10; i++)
	{
		blocks[i] = new Block();
	}
	level = 1;

	initTile();
	LoadAtlas();
	LoadSprites();
}

void Tilemap::initTile()
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			board[i][j].pos.x = j;
			board[i][j].pos.y = i;
			board[i][j].rec.setSize(sf::Vector2f(40.0f, 40.0f));
			board[i][j].rec.setPosition(40 + 40 * j, 25 + 40 * i);
			board[i][j].sprite.setPosition(Vector2f(board[i][j].rec.getPosition()));
			board[i][j].id = 10; //10 is well outside any of the IDs used for the game.
		}
	}

}
void Tilemap::LoadAtlas()
{
	atlas[0].loadFromFile("res/Blank.png");
	atlas[1].loadFromFile("res/Center.png");
	atlas[2].loadFromFile("res/Left.png");
	atlas[3].loadFromFile("res/Up.png");
	atlas[4].loadFromFile("res/Right.png");
	atlas[5].loadFromFile("res/Down.png");
	atlas[6].loadFromFile("res/WinSlot.png");

}

void Tilemap::LoadSprites()
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			switch (board[i][j].id) {
			case 0:
				board[i][j].sprite.setTexture(atlas[0]); //Blank
				break;
			case 1:
				board[i][j].sprite.setTexture(atlas[1]); //Center
				break;
			case 2:
				board[i][j].sprite.setTexture(atlas[2]); //left
				break;
			case 3:
				board[i][j].sprite.setTexture(atlas[3]); //up 
				break;
			case 4:
				board[i][j].sprite.setTexture(atlas[4]); //right
				break;
			case 5:
				board[i][j].sprite.setTexture(atlas[5]); //down
				break;
			default:
				board[i][j].sprite.setTexture(atlas[0]);
				break;
			}

			if (board[i][j].winSlot)
			{
				board[i][j].sprite.setTexture(atlas[6]);
			}
		}
	}

}

void Tilemap::draw(sf::RenderWindow& win)
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			win.draw(board[i][j].sprite);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (blocks[i]->getActive())
		{
			blocks[i]->draw(win);
		}
	}

}

void Tilemap::input(Player* p1)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		switch (level)
		{
		case 1:
			levelOne(p1);
			break;
		case 2:
			levelTwo(p1);
			break;
		case 3:
			levelThree(p1);
			break;
		default:
			break;
		}
	}
}

bool Tilemap::levelController(Player* p1)
{
	switch (level)
	{
	case 1:
		levelOne(p1);
		break;
	case 2:
		levelTwo(p1);
		break;
	case 3:
		levelThree(p1);
		break;
	case 4:
		return false;;
	default:
		break;
	}
}

int Tilemap::getLevel()
{
	return level;
}

void Tilemap::setLevel(int x)
{	
	level = x;
}

void Tilemap::clearBoard()
{
	for (int i = 0; i < maxTLY; i++) {
		for (int j = 0; j < maxTLX; j++) {
			board[i][j].id = 10;
			board[i][j].winSlot = false;
			LoadSprites();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		blocks[i]->reset();

	}
}

void Tilemap::levelOne(Player* p1)
{

	clearBoard();
	{
		board[1][12].id = 5;
		board[2][5].id = 5;
		board[2][6].id = 5;
		board[2][7].id = 5;
		board[2][8].id = 5;
		board[2][9].id = 5;
		board[2][10].id = 5;
		board[2][11].id = 5;
		board[2][13].id = 2;
		board[3][4].id = 4;
		board[3][13].id = 2;
		board[4][5].id = 3;
		board[4][6].id = 3;
		board[4][7].id = 3;
		board[4][8].id = 1;
		board[4][10].id = 1;
		board[4][11].id = 1;
		board[4][13].id = 2;
		board[5][8].id = 3;
		board[5][13].id = 2;
		board[6][9].id = 3;
		board[6][10].id = 3;
		board[6][11].id = 3;
		board[6][12].id = 3;

		board[2][12].id = 0; //WINSLOT
		board[2][12].winSlot = true;

		board[3][5].id = 0;
		board[3][6].id = 0;
		board[3][7].id = 0;
		board[3][8].id = 0;
		board[3][9].id = 0;
		board[3][10].id = 0;
		board[3][11].id = 0;
		board[3][12].id = 0;
		board[4][9].id = 0;
		board[4][12].id = 0;
		board[5][9].id = 0;
		board[5][12].id = 0;
		board[5][10].id = 0;
		board[5][11].id = 0;
		board[5][12].id = 0;
	} //ID SETTINGS
	LoadSprites();


	p1->setPosition(board[3][5].pos.x, board[3][5].pos.y);

	blocks[0]->setPosition(board[3][9].pos.x, board[3][9].pos.y);
	blocks[0]->setActive(true);
}
void Tilemap::levelOneWincon(Player* p1)
{
	if (board[2][12].pos.x == blocks[0]->getPositionX()&& board[2][12].pos.y == blocks[0]->getPositionY())
	{
		cout << "Win!" << endl;
		level = 2;
		levelController(p1);
	}
}

void Tilemap::levelTwo(Player* p1)
{
	clearBoard();
	{
		board[2][4].id = 1;
		board[2][5].id = 5;
		board[2][6].id = 5;
		board[2][7].id = 5;
		board[2][8].id = 1;

		board[3][4].id = 4;
		board[3][8].id = 1;
		board[3][9].id = 5;
		board[3][10].id = 5;
		board[3][11].id = 1;

		board[4][4].id = 4;
		board[4][11].id = 2;

		board[5][4].id = 1;
		board[5][5].id = 3;
		board[5][6].id = 3;
		board[5][7].id = 3;
		board[5][8].id = 3;
		board[5][9].id = 3;
		board[5][10].id = 3;
		board[5][11].id = 1;


		board[3][5].id = 0;
		board[3][6].id = 0;
		board[3][7].id = 0;
		board[4][5].id = 0;
		board[4][6].id = 0;
		board[4][7].id = 0;
		board[4][8].id = 0;
		board[4][8].id = 0;
		board[4][9].id = 0;

		board[4][10].id = 0;
		board[4][10].winSlot = true;
	}
	LoadSprites();

	p1->setPosition(board[4][9].pos.x, board[4][9].pos.y);

	blocks[0]->setPosition(board[4][7].pos.x, board[4][7].pos.y);
	blocks[0]->setActive(true);

}
void Tilemap::levelTwoWincon(Player* p1)
{
	if (board[4][10].pos.x == blocks[0]->getPositionX() && board[4][10].pos.y == blocks[0]->getPositionY())
	{
		cout << "Win!" << endl;
		level = 3;
		levelController(p1);
	}
}

void Tilemap::levelThree(Player* p1)
{
	clearBoard();
	{
		board[0][10].id = 5;
		board[0][11].id = 5;
		board[0][12].id = 5;
		board[1][7].id = 1;
		board[1][8].id = 5;
		board[1][9].id = 1;
		board[1][13].id = 2;
		board[2][7].id = 4;
		board[2][13].id = 2;
		board[3][5].id = 5;
		board[3][6].id = 5;
		board[3][7].id = 1;
		board[3][10].id = 1;
		board[3][13].id = 2;
		board[4][4].id = 4;
		board[4][11].id = 1;
		board[4][12].id = 3;
		board[5][5].id = 3;
		board[5][6].id = 1;
		board[5][7].id = 1;
		board[5][11].id = 2;
		board[6][6].id = 4;
		board[6][11].id = 2;
		board[7][6].id = 4;
		board[7][10].id = 1;
		board[8][7].id = 3;
		board[8][8].id = 3;
		board[8][9].id = 3;

		board[1][10].id = 0;
		board[1][11].id = 0;
		board[1][12].id = 0;
		board[2][8].id = 0;
		board[2][9].id = 0;
		board[2][10].id = 0;
		board[2][11].id = 0;
		board[2][12].id = 0;
		board[3][8].id = 0;
		board[3][9].id = 0;
		board[3][11].id = 0;
		board[3][12].id = 0;
		board[4][5].id = 0;
		board[4][6].id = 0;
		board[4][7].id = 0;
		board[4][8].id = 0;
		board[4][9].id = 0;
		board[4][10].id = 0;
		board[5][8].id = 0;
		board[5][9].id = 0;
		board[5][10].id = 0;
		board[6][7].id = 0;
		board[6][8].id = 0;
		board[6][9].id = 0;
		board[6][10].id = 0;
		board[7][7].id = 0;
		board[7][8].id = 0;
		board[7][9].id = 0;

		board[1][12].winSlot = true;
		board[2][12].winSlot = true;
	}
	LoadSprites();

	p1->setPosition(board[4][5].pos.x, board[4][5].pos.y);

	blocks[0]->setPosition(board[5][9].pos.x, board[5][9].pos.y);
	blocks[0]->setActive(true);

	blocks[1]->setPosition(board[6][9].pos.x, board[6][9].pos.y);
	blocks[1]->setActive(true);
}
void Tilemap::levelThreeWincon(Player* p1)
{
	bool win1 = false;
	bool win2 = false;

	if (board[1][12].pos.x == blocks[0]->getPositionX() && board[1][12].pos.y == blocks[0]->getPositionY() || board[2][12].pos.x == blocks[0]->getPositionX() && board[2][12].pos.y == blocks[0]->getPositionY()) {
		win1 = true;
	}
	if (board[1][12].pos.x == blocks[1]->getPositionX() && board[1][12].pos.y == blocks[1]->getPositionY() || board[2][12].pos.x == blocks[1]->getPositionX() && board[2][12].pos.y == blocks[1]->getPositionY()) {
		win2 = true;
	}

	if (win1&&win2)
	{
		cout << "Win!" << endl;
		level = 4;
		levelController(p1);
	}

}
