#pragma once
#include "Player.h"
#include "Board.h"

class Game
{
public:
    Game(int size, Player *player1, Player *player2);
    ~Game();
    void play();
    bool isWin(PieceType type);

private:
    int m_size;
    Board *m_board;
    Player *m_player1, *m_player2;
};