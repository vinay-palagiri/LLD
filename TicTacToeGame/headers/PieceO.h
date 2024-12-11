#pragma once
#include "Piece.h"

class PieceO : public Piece
{
public:
    PieceO() : Piece(PieceType::PieceTypeO) {}

    char getName() const override { return 'O'; }
};