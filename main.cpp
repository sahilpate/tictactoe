#include "TTTGame.hpp"

int main(int argc, char *argv[])
{
    TTTGame game;

    do
    {
        game.selectPlayers();
        game.playGame();
        game.resetGame();
    }
    while (game.checkPlayAgain() == true)

    return 0;
}