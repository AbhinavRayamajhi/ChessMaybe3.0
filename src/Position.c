#include "../include/Position.h"

void makeMove(Board* board, History* history, Move move) {

    Square start = getStartSq(move);
    Square target = getTargetSq(move);

    history->prevMove = move;
    history->captured = NO_PIECE;
    history->prevEnPassantSq = board->enPassantSq;
    history->prevCastlingRights = board->castlingRight;
    history->prevHalfMoveClock = board->halfMoveClock;

    // reset board enPassant sq
    board->enPassantSq = NONE;
    
    // increment half move clock, will set back to 0 if pawn move or capture later
    board->halfMoveClock++;

    for (Piece piece = PAWN; piece < PIECE_COUNT; ++piece) {

        if (getSq(board->pieces[board->sideToMove][piece], start)) {

            history->moved = piece;

            // move piece
            board->pieces[board->sideToMove][piece] ^= (1ULL << start) | (1ULL << target);

            if (piece == PAWN) {
                // set en passant sq if double push
                if (start + 16 == target) board->enPassantSq = start + 8;
                if (start - 16 == target) board->enPassantSq = start - 8;
                // reset half move clock since pawn move
                board->halfMoveClock = 0;
            }

            // king move cancels all castling
            if (piece == KING) board->castlingRight = NO_CASTLING;
        }
        if (getSq(board->pieces[!board->sideToMove][piece], target)) {

            history->captured = piece;
            // reset half move clock since capture
            board->halfMoveClock = 0;
            // delete captured piece
            board->pieces[!board->sideToMove][piece] ^= (1ULL << target);
        }
    }

    if (getMoveType(move) == PROMOTION) {

        // remove moved pawn
        popSq(board->pieces[board->sideToMove][PAWN], target);
        setSq(board->pieces[board->sideToMove][getPromotionPiece(move)], target);
    }
    else if (getMoveType(move) == EN_PASSANT) {

        board->pieces[!board->sideToMove][PAWN] ^= (1ULL << (target + (board->sideToMove ? -8 : 8)));
    }
    else if (getMoveType(move) == CASTLING) {

        Square rookFrom, rookTo;
        if (target == G1) {
            rookFrom = H1;
            rookTo = F1;
            board->castlingRight &= ~WHITE_KINGSIDE;
        }
        else if (target == G8) {
            rookFrom = H8;
            rookTo = F8;
            board->castlingRight &= ~BLACK_KINGSIDE;
        }
        else if (target == C1) {
            rookFrom = A1;
            rookTo = D1;
            board->castlingRight &= ~WHITE_QUEENSIDE;
        }
        else {
            rookFrom = A8;
            rookTo = D8;
            board->castlingRight &= ~BLACK_QUEENSIDE;
        }

        board->pieces[board->sideToMove][ROOK] ^= (1ULL << rookFrom) | (1ULL << rookTo);
    }

    // if anything moves from h1, h8, a1, a8, castling rights is revoked, checking if moved piece is rook could be faster, Need to check
    if (start == H1) {
        board->castlingRight &= ~WHITE_KINGSIDE;
    }
    else if (start == H8) {
        board->castlingRight &= ~BLACK_KINGSIDE;
    }
    else if (start == A1) {
        board->castlingRight &= ~WHITE_QUEENSIDE;
    }
    else if (start == A8) {
        board->castlingRight &= ~BLACK_QUEENSIDE;
    }

    board->sideToMove ^= 1;
    updateOcc(board);
}

void unmakeMove(Board* board, History* history) {

}