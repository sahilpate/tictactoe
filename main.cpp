#include "TTTGame.hpp"

int main()
{
    TTTGame game;

    do
    {
        game.selectPlayers();
        game.playGame();
        game.resetGame();
    }
    while (game.checkPlayAgain() == true);

    return 0;
}