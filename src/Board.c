#include "../include/Board.h"

Board getInitialBoard() {

    Board res;

    res.pieces[WHITE][PAWN]   = 0x000000000000FF00ULL;
    res.pieces[WHITE][KNIGHT] = 0x0000000000000042ULL;
    res.pieces[WHITE][BISHOP] = 0x0000000000000024ULL;
    res.pieces[WHITE][ROOK]   = 0x0000000000000081ULL;
    res.pieces[WHITE][QUEEN]  = 0x0000000000000008ULL;
    res.pieces[WHITE][KING]   = 0x0000000000000010ULL;

    res.pieces[BLACK][PAWN]   = res.pieces[WHITE][PAWN]   << 40;
    res.pieces[BLACK][KNIGHT] = res.pieces[WHITE][KNIGHT] << 56;
    res.pieces[BLACK][BISHOP] = res.pieces[WHITE][BISHOP] << 56;
    res.pieces[BLACK][ROOK]   = res.pieces[WHITE][ROOK]   << 56;
    res.pieces[BLACK][QUEEN]  = res.pieces[WHITE][QUEEN]  << 56;
    res.pieces[BLACK][KING]   = res.pieces[WHITE][KING]   << 56;

    res.occ[WHITE] = res.occ[BLACK] = res.occ[BOTH] = 0ULL;

    for (int p = 0; p < PIECE_COUNT; ++p) {
        res.occ[WHITE] |= res.pieces[WHITE][p];
        res.occ[BLACK] |= res.pieces[BLACK][p];
    }

    res.occ[BOTH] = res.occ[WHITE] | res.occ[BLACK];

    res.sideToMove = WHITE;
    res.castlingRight = 0b1111;
    res.enPassantSq = NONE;
    res.halfMoveClock = res.fullMoveClock = 0;

    return res;
}