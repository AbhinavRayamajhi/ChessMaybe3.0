#include "../include/MaskGen.h"
#include "../include/Test.h"
#include "../include/Magic.h"
#include "../include/Board.h"

int main() {

    generateKnightMasks();
    generatePawnAttackMasks();
    generateKingMasks();
    generateRookMasks();
    generateBishopMasks();
    initMagicTables();

    /*
    printBitboard(      kingTable[E8]);
    printBitboard(    knightTable[E8]);
    printBitboard(    bishopTable[E8]);
    printBitboard(      rookTable[E8]);
    printBitboard(pawnAttackTable[E8]);
    printBitboard(pawnAttackTable[E8 + 64]);
    
    Bitboard bb = 0ULL;
    setSq(bb, A4);
    setSq(bb, E1);
    printBitboard(rookAttacksForBlockers(bb, A3));

    Bitboard bb = 0ULL;
    setSq(bb, C3);
    setSq(bb, B7);
    printBitboard(bishopAttacksForBlockers(bb, A1));

    Board board = getInitialBoard();

    printBitboard(board.pieces[BLACK][PAWN]  );
    printBitboard(board.pieces[BLACK][KNIGHT]);
    printBitboard(board.pieces[BLACK][BISHOP]);
    printBitboard(board.pieces[BLACK][ROOK]  );
    printBitboard(board.pieces[BLACK][QUEEN] );
    printBitboard(board.pieces[BLACK][KING]  );
    runAllTableTests();
    
    History h;
    Board board = getBoardFromFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Move m1 = make(D2, D4, NO_PROMOTION_PIECE, NORMAL);
    Move m2 = make(C7, C5, NO_PROMOTION_PIECE, NORMAL);
    Move m3 = make(E1, D2, NO_PROMOTION_PIECE, NORMAL);
    Move m4 = make(C5, D4, NO_PROMOTION_PIECE, NORMAL);
    makeMove(&board, &h, m1);
    makeMove(&board, &h, m2);
    makeMove(&board, &h, m3);
    makeMove(&board, &h, m4);
    int depth = 5;
    int debug = 0;
    int deeperSearch = 0;

    printf("%d\n", perft(&board, depth, depth, debug, deeperSearch));
    */

    runAllPerftTests();
    return 0;
}