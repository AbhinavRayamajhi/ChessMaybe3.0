#include "../include/MoveGen.h"

Bitboard getRookAttacks(Bitboard occ, int sq) {
    Bitboard rookMask = rookTable[sq];
    uint64_t index = ((rookMask & occ) * ROOK_MAGICS[sq]) >> (64 - popCount(rookMask));
    return rookAttackTable[sq][index];
}

Bitboard getBishopAttacks(Bitboard occ, int sq) {
    Bitboard bishopMask = bishopTable[sq];
    uint64_t index = ((bishopMask & occ) * BISHOP_MAGICS[sq]) >> (64 - popCount(bishopMask));
    return bishopAttackTable[sq][index];
}