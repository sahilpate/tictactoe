#include "TTTPlayer.hpp"

TTTPlayer::TTTPlayer() : myBoard(0) {}

int TTTPlayer::getBoard() const { return myBoard; }
void TTTPlayer::reset() { myBoard = 0; }

TTTPlayer::~TTTPlayer() {}