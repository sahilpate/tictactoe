#include <iostream>
#include "TTTGame.hpp"

void printRefBoard();

int main()
{
    TTTGame game;

    do
    {
        game.selectPlayers();

        std::cout << std::endl << "Each number corresponds to the following positions:" << std::endl;
        printRefBoard();
        std::cout << std::endl;

        game.playGame();
        game.resetGame();
    }
    while (game.checkPlayAgain() == true);

    return 0;
}

void printRefBoard()
{
    for(int i = 1; i < 10; ++i)
    {
        std::cout << i << ' ';
        if(i % 3 == 0) std::cout << std::endl;
    }
}