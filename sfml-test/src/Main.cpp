#include "App/App.h"

void main()
{
    App* Game = new App();
    Game->LoopApp();
    delete Game;

}
