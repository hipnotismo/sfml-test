#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

#define MAX_NUMBER_OF_CONTROL 5

class Menu
{
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text control[MAX_NUMBER_OF_CONTROL];
    sf::Text title;
    Texture texture;
    Sprite sprite;
public:
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

};