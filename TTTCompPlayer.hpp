#ifndef TTTHCOMPPLAYER_HPP
#define TTTCOMPPLAYER_HPP

class TTTCompPlayer : public TTTPlayer
{
public:
    TTTCompPlayer();
    void updateMove(int opponentBoard) override;
};

#endif //TTTCOMPPLAYER_HPP