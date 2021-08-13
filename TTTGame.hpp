#ifndef TTTGAME_HPP
#define TTTGAME_HPP

#include "TTTPlayer.hpp"
#include "TTTCompPlayer.hpp"
#include "TTTHumanPlayer.hpp"

class TTTGame
{
public:
    TTTGame();

    void selectPlayers();
    void playGame();
    bool checkPlayAgain() const;
    void resetGame();

    ~TTTGame();

private:
    enum Winner { UNFINISHED, P1, P2, TIE };

    TTTPlayer *players[4];
    int playerIndex[2];
    const int winConditions[8] = { 7, 56, 448, 73, 146, 292, 273, 84 };

    void printBoard();
    Winner checkWin();
};

#endif //TTTGAME_HPP