#include <iostream>
#include "TTTPlayer.hpp"
#include "TTTHumanPlayer.hpp"

TTTHumanPlayer::TTTHumanPlayer() {}

void TTTHumanPlayer::updateMove(int opponentBoard)
{
    int curBoard = myBoard & opponentBoard;
    int curMove;
    bool validMove = false;

    while(!validMove)
    {
        std::cout << "Input a move [0-9]: ";
        std::cin >> curMove;

        if(!((1 << curMove) & curBoard)) validMove = true;
        else
        {
            std::cout << "Invalid input.";
        }
    }
}