#pragma once
#include "Piece.h"
#include "PieceX.h"
#include "PieceO.h"

class PieceFactory
{
public:
    static Piece *createPiece(PieceType type)
    {
        if (type == PieceType::PieceTypeO)
            return new PieceO();

        if (type == PieceType::PieceTypeX)
            return new PieceX();

        return nullptr;
    }
};