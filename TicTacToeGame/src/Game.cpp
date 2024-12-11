#include "../headers/Game.h"
#include <iostream>

Game::Game(int size, Player *player1, Player *player2) : m_size(size), m_player1(player1), m_player2(player2)
{
    m_board = new Board(size);
}

Game::~Game()
{
    delete m_board;
}

bool Game::isWin(PieceType type)
{
    auto &board = m_board->getBoard();
    // check rows
    for (int row = 0; row < m_size; row++)
    {
        int col = 0;
        for (col = 0; col < m_size; col++)
        {
            if (!board[row][col] || board[row][col]->getType() != type)
                break;
        }
        if (col == m_size)
            return true;
    }

    // check cols
    for (int col = 0; col < m_size; col++)
    {
        int row = 0;
        for (row = 0; row < m_size; row++)
        {
            if (!board[row][col] || board[row][col]->getType() != type)
                break;
        }
        if (row == m_size)
            return true;
    }

    // check top-left to bottom-right diagnol
    int row = 0, col = 0;
    while (row < m_size && col < m_size)
    {
        if (!board[row][col] || board[row][col]->getType() != type)
            break;
        row++;
        col++;
    }

    if (row == m_size && col == m_size)
        return true;

    // check top-right to bottom-left diagnol
    row = 0;
    col = m_size - 1;
    while (row < m_size && col >= 0)
    {
        if (!board[row][col] || board[row][col]->getType() != type)
            break;
        row++;
        col--;
    }
    if (row == m_size && col < 0)
        return true;

    return false;
}

void Game::play()
{
    int maxMoves = m_size * m_size;
    int moves = 0;
    Player *playerTurn = m_player1;

    while (moves < maxMoves)
    {
        m_board->displayBoard();
        int row, col;
        std::cout << "select row and column to place the piece : row [0 to " << m_size - 1 << "], column [0 to " << m_size - 1 << "]" << std::endl;
        std::cin >> row >> col;

        if (!m_board->canPlacePiece(row, col))
        {
            std::cout << "Try to select the row and column again!!" << std::endl;
            continue;
        }

        m_board->setPiece(row, col, playerTurn->getPiece()->getType());
        moves++;

        if (isWin(playerTurn->getPiece()->getType()))
        {
            std::cout << "Winner of the game is : " << playerTurn->getName() << std::endl;
            return;
        }

        playerTurn = (playerTurn == m_player1) ? m_player2 : m_player1;
    }

    std::cout << "Game is a tie" << std::endl;
}