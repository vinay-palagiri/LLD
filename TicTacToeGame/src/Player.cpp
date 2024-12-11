#include "../headers/Player.h"
#include "../headers/PieceFactory.h"
#include "../headers/Piece.h"
#include <iostream>

int Player::id_counter = 0;

Player::Player(std::string name, PieceType type) : m_name(name)
{
    m_piece = PieceFactory::createPiece(type);
    m_id = ++id_counter;
}