#include "../headers/Piece.h"

int Piece::id_counter = 0;

Piece::Piece(PieceType type)
{
    m_type = type;
    m_id = ++id_counter;
}