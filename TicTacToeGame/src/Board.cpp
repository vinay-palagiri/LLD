#include "../headers/Board.h"
#include <stdexcept>
#include "../headers/Piece.h"
#include "../headers/PieceFactory.h"
#include <iostream>

Board::Board(int size) : m_size(size), m_board(size, std::vector<Piece *>(size, nullptr))
{
}

Board::~Board()
{
    for (int row = 0; row < m_size; row++)
    {
        for (int col = 0; col < m_size; col++)
        {
            if (m_board[row][col])
                delete m_board[row][col];
        }
    }
}

bool Board::isValidIndex(int row, int col) const
{
    if (row < 0 || row >= m_size || col < 0 || col >= m_size)
        return false;

    return true;
}

void Board::setPiece(int row, int col, PieceType type)
{
    if (!canPlacePiece(row, col))
        return;

    m_board[row][col] = PieceFactory::createPiece(type);
}

bool Board::canPlacePiece(int row, int col)
{
    if (!isValidIndex(row, col))
    {
        std::cout << "Given row and column are not in the range of 0 to " << m_size - 1 << std::endl;
        return false;
    }

    if (m_board[row][col] != nullptr)
    {
        std::cout << "Given row and column has the piece." << std::endl;
        return false;
    }

    return true;
}

const Piece *Board::getPiece(int row, int col) const
{
    return m_board[row][col];
}

void Board::displayBoard()
{
    for (int row = 0; row < m_size; row++)
    {
        for (int col = 0; col < m_size; col++)
        {
            char ch = (m_board[row][col] == nullptr) ? ' ' : m_board[row][col]->getName();
            std::cout << "| " << ch << " ";
        }
        std::cout << "|" << std::endl;
    }
}