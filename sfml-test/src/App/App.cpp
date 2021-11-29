#include "app.h"

App::App()
{
    currentScreen = Screens::Menu;
    player = new Player();
    TM = new Tilemap();
    menu = new Menu(800, 450);
    credit = new credits(800, 450);
    check = true;
}

App::~App()
{

}

void App::LoopApp()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "Sokoban");
    sf::Event event;
    TM->levelOne(player);
    
  //  sf::Event event2;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    menu->MoveUp();
                    break;

                case sf::Keyboard::S:
                    menu->MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu->GetPressedItem())
                    {
                    case 0:
                        currentScreen = Screens::Gameplay;
                        break;
                    case 1:
                        currentScreen = Screens::Credits;
                        check = !check;

                        break;
                    case 2:
                        window.close();
                        break;
                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }

        }

        Input();
        Draw(window);

    }
}

void App::Draw(sf::RenderWindow &win)
{
    win.clear();
    switch (currentScreen) {
    case Screens::Menu:
       
        menu->draw(win);
        break;
    case Screens::Credits:
        credit->draw(win);
        break;
    case Screens::Gameplay:
        TM->draw(win);
        player->draw(win);
        break;
    case Screens::GameOver:
        break;
    default:
        break;
    }
    win.display();
}

void App::Input()
{
    switch (currentScreen) {
    case Screens::Menu:
     
        break;
    case Screens::Credits:
        if (menu->GetPressedItem() && check)
        {
            currentScreen = Screens::Menu;

        }
        break;
    case Screens::Gameplay:

        break;
    case Screens::GameOver:

        break;
    default:
        break;
    }
}

