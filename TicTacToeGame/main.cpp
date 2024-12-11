#include <iostream>
#include "./headers/Game.h"
#include "./headers/Player.h"

int main()
{
    Player *player1 = new Player("player1", PieceType::PieceTypeO);
    Player *player2 = new Player("player2", PieceType::PieceTypeX);
    Game *game = new Game(3, player1, player2);
    game->play();

    delete game;
    delete player1;
    delete player2;
}