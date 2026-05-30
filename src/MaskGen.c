#include "../include/MaskGen.h"

void generateKnightMasks(Bitboard* knightTable) {    

    for (int sq = 0; sq < 64; sq++) {

        Bitboard mask = 0ULL;
        Bitboard cur = 0ULL;
        setSq(cur, sq);

        mask |= (cur & ~FILE_H )<< 17;
        mask |= (cur & ~FILE_A) << 15;
        mask |= (cur & ~FILE_G & ~FILE_H) << 10;
        mask |= (cur & ~FILE_A & ~FILE_B) <<  6;
        mask |= (cur & ~FILE_A) >> 17;
        mask |= (cur & ~FILE_H) >> 15;
        mask |= (cur & ~FILE_A & ~FILE_B) >> 10;
        mask |= (cur & ~FILE_G & ~FILE_H) >>  6;

        *knightTable++ = mask;
    }
}