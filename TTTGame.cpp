#include <iostream>
#include <exception>
#include "TTTGame.hpp"
#include "TTTHumanPlayer.hpp"
#include "TTTCompPlayer.hpp"

TTTGame::TTTGame()
{
	playerIndex[0] = -1;
	playerIndex[1] = -1;

    for(int i = 0; i < 2; ++i)
    {
        players[i] = new TTTHumanPlayer;
        players[i+2] = new TTTCompPlayer;
    }
}

void TTTGame::selectPlayers()
{
    int curHum = 0, curComp = 2;
    char userIn = '\0';

    for(int i = 1; i < 3; ++i)
    {
        while (userIn != 'H' && userIn != 'C')
        {
			std::cout << "Should Player " << i << " be a human or computer? [H/C]: ";
            std::cin >> userIn;
            
            if(userIn == 'H')
                playerIndex[i-1] = curHum++;
            else if(userIn == 'C')
                playerIndex[i-1] = curComp++;
            else
                std::cout << "Invalid input, please enter an 'H' or a 'C'." << std::endl << std::endl;
        }

        userIn = '\0';
    }

    return;
}

void TTTGame::playGame()
{
    Winner gameState = UNFINISHED;

    while(gameState == UNFINISHED)
    {
		std::cout << "Player 1's turn." << std::endl;
        players[playerIndex[0]]->updateMove(players[playerIndex[1]]->getBoard());
		printBoard();
		std::cout << std::endl;

		if((gameState = checkWin()) != UNFINISHED) break;

		std::cout << "Player 2's turn." << std::endl;
        players[playerIndex[1]]->updateMove(players[playerIndex[0]]->getBoard());
		printBoard();
		std::cout << std::endl;

        gameState = checkWin();
    }

    std::cout << "The winner is... ";

    switch(gameState)
    {
        case P1:
            std::cout << "Player 1!";
            break;
        case P2:
            std::cout << "Player 2!";
            break;
        case TIE:
            std::cout << "no one! The game is a tie.";
            break;
		default:
			throw std::runtime_error("Invalid case in gameState switch statement in playGame().");
    }

    std::cout << std::endl;

    return;
}

bool TTTGame::checkPlayAgain() const
{
    char userIn = '\0';

    while(userIn != 'Y' && userIn != 'N')
    {
        std::cout << "Would you like to play again? [Y/N]: ";
        std::cin >> userIn;
    }

    if(userIn == 'Y') return true;
    else return false;
}

void TTTGame::resetGame()
{
    players[playerIndex[0]]->reset();
    players[playerIndex[1]]->reset();

    playerIndex[0] = -1;
    playerIndex[1] = -1;

    return;
}

void TTTGame::printBoard()
{
	int boardP1 = players[playerIndex[0]]->getBoard();
    int boardP2 = players[playerIndex[1]]->getBoard();

	for(int i = 1; i <= 9; ++i)
	{
		if(boardP1 % 2)
			std::cout << "X ";
		else if(boardP2 % 2)
			std::cout << "O ";
		else
			std::cout << "- ";

		if(i % 3 == 0)
			std::cout << std::endl;

		boardP1 >>= 1;
		boardP2 >>= 1;
	}

	return;
}

TTTGame::Winner TTTGame::checkWin()
{
    int size = sizeof(winConditions)/sizeof(winConditions[0]);
    int boardP1 = players[playerIndex[0]]->getBoard();
    int boardP2 = players[playerIndex[1]]->getBoard();

    for(int i = 0; i < size; ++i)
    {
        if((boardP1 & winConditions[i]) == winConditions[i])
            return P1;
        else if((boardP2 & winConditions[i]) == winConditions[i])
            return P2;
    }

    if((boardP1 | boardP2) == 511) return TIE;
    return UNFINISHED;
}

TTTGame::~TTTGame()
{
	for(int i = 0; i < 4; ++i)
		delete players[i];
}