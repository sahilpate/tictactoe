#ifndef TTTPLAYER_HPP
#define TTTPLAYER_HPP

#include <vector>

class TTTPlayer
{
public:
    int getBoard() const;
    virtual int getMove(int opponentBoard, std::vector<int> &boardPositions, int &availableMoves) = 0;
    void reset();

private:
    int myBoard;
};

#endif //TTTPLAYER_HPP