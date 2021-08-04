#include <iostream>
#include "TTTPlayer.hpp"
#include "TTTCompPlayer.hpp"

TTTCompPlayer::TTTCompPlayer() {}

void TTTCompPlayer::updateMove(int opponentBoard)
{
    int curBoard = myBoard | opponentBoard;
    int newBoard = (curBoard + 1) | curBoard;
    myBoard |= (curBoard ^ newBoard);
}