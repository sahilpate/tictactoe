#ifndef TTTPLAYER_HPP
#define TTTPLAYER_HPP

#include <vector>

class TTTPlayer
{
public:
    TTTPlayer();

    int getBoard() const;
    virtual void updateMove(int opponentBoard) = 0;
    void reset();
    
protected:
    int myBoard;
};

#endif //TTTPLAYER_HPP