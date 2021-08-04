#ifndef TTTHUMANPLAYER_HPP
#define TTTHUMANPLAYER_HPP

class TTTHumanPlayer : public TTTPlayer
{
public:
    TTTHumanPlayer();
    void updateMove(int opponentBoard) override;
};

#endif //TTTHUMANPLAYER_HPP