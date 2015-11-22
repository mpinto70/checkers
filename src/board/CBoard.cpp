
#include "CBoard.h"

#include "util/CException.h"
#include <string>

namespace board {

CBoard::CBoard()
    : squares( {
    ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK,
            ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,
            ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK, ESquare::VOID,  ESquare::BLACK,
            ESquare::EMPTY, ESquare::VOID,  ESquare::EMPTY, ESquare::VOID,  ESquare::EMPTY, ESquare::VOID,  ESquare::EMPTY, ESquare::VOID,
            ESquare::VOID,  ESquare::EMPTY, ESquare::VOID,  ESquare::EMPTY, ESquare::VOID,  ESquare::EMPTY, ESquare::VOID,  ESquare::EMPTY,
            ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,
            ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE,
            ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID,  ESquare::WHITE, ESquare::VOID
}) {
}

ESquare CBoard::square(int squareNumber) const {
    if (squareNumber < 1 || squareNumber > 32) {
        throw util::CSquareOutOfRange("CBoard::square - square number [" + std::to_string(squareNumber) + "] out of range");
    }

    const auto columnRow = normalizedColumnRow(squareNumber);

    return square(columnRow);
}

void CBoard::free(int squareNumber) {
    set("free", squareNumber, ESquare::EMPTY);
}

void CBoard::set(int squareNumber, ESquare state) {
    set("set", squareNumber, state);
}

std::pair<int, int> CBoard::normalizedColumnRow(int squareNumber) const {
    const int normalizedSquareNumber = squareNumber - 1;
    const int row = normalizedSquareNumber / 4;
    const int column = (normalizedSquareNumber % 4) * 2 + ((row % 2 == 0) ? 1 : 0);
    return std::make_pair(column, row);
}

ESquare CBoard::square(const std::pair<int, int> & columnRow) const {
    const int column = columnRow.first;
    const int row = columnRow.second;
    if (column < 0 || column > 7
            || row < 0 || row > 7)
        return ESquare::VOID;
    const int idx = index(columnRow);
    return squares[idx];
}

int CBoard::index(const std::pair<int, int> & columnRow) const {
    return columnRow.second * 8 + columnRow.first;
}

void CBoard::set(const std::string & function, int squareNumber, ESquare state) {
    if (state == ESquare::VOID) {
        throw util::CInvalidSquareState("CBoard::" + function + " - invalid state to square");
    }
    const auto columnRow = normalizedColumnRow(squareNumber);
    const auto oldState = square(columnRow);
    if (oldState == ESquare::VOID) {
        throw util::CSquareOutOfRange("CBoard::" + function + " - square number [" + std::to_string(squareNumber) + "] out of range");
    }

    const auto idx = index(columnRow);
    squares[idx] = state;
}


}
