#ifndef _PIECE_H
#define _PIECE_H

enum class PieceType
{
    PieceTypeX,
    PieceTypeO,
    PiceTypeNone,
};

class Piece
{
public:
    Piece(PieceType type);
    virtual char getName() const = 0;
    int getId() const { return m_id; }
    PieceType getType() const { return m_type; }

protected:
    int m_id;
    static int id_counter;
    PieceType m_type;
};

#endif