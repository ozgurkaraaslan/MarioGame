#include "Common.h"
#include "Game.h"

int main()
{
    Game game(SPEED);
    game.drawBackground();
    game.update();
    return 0;
}