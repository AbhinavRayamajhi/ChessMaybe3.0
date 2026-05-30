#include "../include/MaskGen.h"

int main() {

    Bitboard knightTable[64];
    generateKnightMasks(knightTable);

    for (int i = 0; i < 64; ++i) {
        printBitboard(knightTable[i]);
    }
    return 0;
}