#ifndef MOVE_GEN_H
#define MOVE_GEN_H

#include <stdlib.h>
#include "Magic.h"
#include "MaskGen.h"

Bitboard getRookAttacks(Bitboard occ, int sq);
Bitboard getBishopAttacks(Bitboard occ, int sq);

#endif