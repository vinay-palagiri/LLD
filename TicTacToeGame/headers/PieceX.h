#pragma once
#include "Piece.h"

class PieceX : public Piece
{
public:
    PieceX() : Piece(PieceType::PieceTypeX) {}

    char getName() const override { return 'X'; }
};