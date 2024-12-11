#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "Piece.h"

class Player
{
public:
    Player(std::string name, PieceType type);
    const Piece *getPiece() const { return m_piece; }
    const std::string getName() const { return m_name; }

private:
    static int id_counter;
    int m_id;
    std::string m_name;
    Piece *m_piece;
};

#endif //_PLAYER_H