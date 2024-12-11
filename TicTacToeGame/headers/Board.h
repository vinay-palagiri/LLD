#pragma once

#include "Piece.h"
#include <vector>

class Board
{
public:
    Board(int size);
    ~Board();
    const Piece *getPiece(int row, int col) const;
    void setPiece(int row, int col, PieceType type);
    void displayBoard();
    bool canPlacePiece(int row, int col);
    const std::vector<std::vector<Piece *>> &getBoard() const { return m_board; }

private:
    bool isValidIndex(int row, int col) const;

private:
    int m_size;
    int m_id;
    static int id_counter;
    std::vector<std::vector<Piece *>> m_board;
};