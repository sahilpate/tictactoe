#ifndef TTTCOMPPLAYER_HPP
#define TTTCOMPPLAYER_HPP

#include "TTTPlayer.hpp"

class TTTCompPlayer : public TTTPlayer
{
public:
    TTTCompPlayer();
    void updateMove(int opponentBoard) override;
};

#endif //TTTCOMPPLAYER_HPP