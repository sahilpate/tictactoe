#ifndef TTTGAME_HPP
#define TTTGAME_HPP

#include "TTTPlayer.hpp"

class TTTGame
{
public:
    TTTGame();

    void selectPlayers();
    void playGame();
    bool checkPlayAgain() const;
    void resetGame();

private:
    enum Winner { UNFINISHED, P1, P2, TIE };

    TTTPlayer *player[4];
    int player1, player2;

    Winner checkWin();
};

#endif //TTTGAME_HPP