
#include "CBoard.h"

#include "util/CException.h"
#include <string>
#include <cstdlib>

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

bool CBoard::isValid(int squareNumber) const {
    return squareNumber >= 1 && squareNumber <= 32;
}

ESquare CBoard::square(int squareNumber) const {
    validateSquareNumber("square", squareNumber);

    const auto columnRow = normalizeSquareNumber(squareNumber);

    return square(columnRow);
}

void CBoard::free(int squareNumber) {
    set("free", squareNumber, ESquare::EMPTY);
}

void CBoard::set(int squareNumber,
                 ESquare state) {
    set("set", squareNumber, state);
}

std::vector<int> CBoard::squaresWithCapture(ESquare state) const {
    return squaresWithOperation(&CBoard::hasCapture, state);
}

std::vector<int> CBoard::squaresWithMove(ESquare state) const {
    return squaresWithOperation(&CBoard::hasMove, state);
}

std::vector<int> CBoard::possibleDestinationsFrom(int squareNumber) const {
    validateSquareNumber("possibleDestinationsFrom", squareNumber);
    const auto from = normalizeSquareNumber(squareNumber);
    const auto fromState = square(from);
    if (fromState == ESquare::EMPTY)
        return std::vector<int>();
    std::vector<int> res;
    addPossibleCaptures(res, from, fromState);
    if (res.empty()) {
        addPossibleMoves(res, from, fromState);
    }
    return res;
}

void CBoard::executeMove(int from, int to) {
    validateSquareNumber("executeMove(from)", from);
    validateSquareNumber("executeMove(to)", to);

    const auto fromCR = normalizeSquareNumber(from);
    const auto toCR = normalizeSquareNumber(to);

    const auto fromState = square(fromCR);
    const auto toState = square(toCR);
    if (fromState != ESquare::BLACK && fromState != ESquare::WHITE)
        throw util::CInvalidMove("CBoard::executeMove - invalid origin");
    if (toState != ESquare::EMPTY)
        throw util::CInvalidMove("CBoard::executeMove - invalid destination");

    const int distH = toCR.first - fromCR.first;
    const int distV = toCR.second - fromCR.second;

    if (std::abs(distH) != std::abs(distV))
        throw util::CInvalidMove("CBoard::executeMove - invalid move");

    if (std::abs(distH) > 2)
        throw util::CInvalidMove("CBoard::executeMove - move is too long");

    if (std::abs(distH) == 2) { // capture
        const auto captured = std::make_pair(fromCR.first + distH / 2, fromCR.second + distV / 2);
        const auto capturedState = square(captured);
        if (capturedState != ESquare::BLACK && capturedState != ESquare::WHITE)
            throw util::CInvalidMove("CBoard::executeMove - invalid captured");
        if (capturedState == fromState)
            throw util::CInvalidMove("CBoard::executeMove - captured is the same as capturer");
        set(captured, ESquare::EMPTY);
    }
    set(fromCR, ESquare::EMPTY);
    set(toCR, fromState);
}


void CBoard::validateSquareNumber(const std::string & function,
                                  int squareNumber) const {
    if (not isValid(squareNumber)) {
        throw util::CSquareOutOfRange("CBoard::" + function + " - square number [" + std::to_string(squareNumber) + "] out of range");
    }
}

std::pair<int, int> CBoard::normalizeSquareNumber(int squareNumber) const {
    const int normalizedSquareNumber = squareNumber - 1;
    const int row = normalizedSquareNumber / 4;
    const int column = (normalizedSquareNumber % 4) * 2 + ((row % 2 == 0) ? 1 : 0);
    return std::make_pair(column, row);
}

int CBoard::denormalizeColumnRow(const std::pair<int, int>& columnRow) const {
    const int column = columnRow.first;
    const int row = columnRow.second;
    if (column < 0 || column > 7
            || row < 0 || row > 7)
        throw std::logic_error("CBoard::denormalizedColumnRow - columnRow (" + std::to_string(column) + "," + std::to_string(row) + ") out of range");
    if ((row % 2 == 0) && (column % 2 == 0))
        throw std::logic_error("CBoard::denormalizedColumnRow - columnRow (" + std::to_string(column) + "," + std::to_string(row) + ") invalid square");
    if ((row % 2 != 0) && (column % 2 != 0))
        throw std::logic_error("CBoard::denormalizedColumnRow - columnRow (" + std::to_string(column) + "," + std::to_string(row) + ") invalid square");
    return row * 4 + column / 2 + 1;
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

void CBoard::set(const std::string & function,
                 int squareNumber,
                 ESquare state) {
    validateSquareNumber(function, squareNumber);

    if (state == ESquare::VOID) {
        throw util::CInvalidSquareState("CBoard::" + function + " - invalid state to square");
    }

    const auto columnRow = normalizeSquareNumber(squareNumber);

    set(columnRow, state);
}

void CBoard::set(const std::pair<int, int> & columnRow,
                 ESquare state) {
    const auto idx = index(columnRow);
    squares[idx] = state;
}

template <typename T>
std::vector<int> CBoard::squaresWithOperation(T func,
                                              ESquare state) const {
    if (state != ESquare::WHITE && state != ESquare::BLACK) {
        return std::vector<int> {};
    }
    std::vector<int> res;
    for (int i = 1; i <= 32; ++i) {
        if (square(i) == state
                && hasOperation<T>(func, i, state)) {
            res.push_back(i);
        }
    }
    return res;
}

template <typename T>
bool CBoard::hasOperation(T func,
                          int squareNumber,
                          ESquare fromState) const {
    const auto from = normalizeSquareNumber(squareNumber);
    return (this->*func)(from, fromState, -1, -1)
           || (this->*func)(from, fromState, +1, -1)
           || (this->*func)(from, fromState, +1, +1)
           || (this->*func)(from, fromState, -1, +1);
}

template <typename T>
void CBoard::addPossibles(T func,
                          std::vector<int> & possibles,
                          const std::pair<int, int> & from,
                          ESquare fromState) const {
    (this->*func)(possibles, from, fromState, -1, -1); // up left
    (this->*func)(possibles, from, fromState, +1, -1); // up right
    (this->*func)(possibles, from, fromState, +1, +1); // down right
    (this->*func)(possibles, from, fromState, -1, +1); // down left
}

void CBoard::addPossibleCaptures(std::vector<int> & possibles,
                                 const std::pair<int, int> & from,
                                 ESquare fromState) const {
    addPossibles<>(&CBoard::addPossibleCapture, possibles, from, fromState);
}

void CBoard::addPossibleMoves(std::vector<int> & possibles,
                              const std::pair<int, int> & from,
                              ESquare fromState) const {
    addPossibles<>(&CBoard::addPossibleMove, possibles, from, fromState);
}


void CBoard::addPossibleCapture(std::vector<int> & possibles,
                                const std::pair<int, int> & from,
                                ESquare fromState,
                                int dir_h,
                                int dir_v) const {
    if (hasCapture(from, fromState, dir_h, dir_v)) {
        const auto to = std::make_pair(from.first + 2 * dir_h, from.second + 2 * dir_v);
        possibles.push_back(denormalizeColumnRow(to));
    }
}

void CBoard::addPossibleMove(std::vector<int> & possibles,
                             const std::pair<int, int> & from,
                             ESquare fromState,
                             int dir_h,
                             int dir_v) const {
    if (hasMove(from, fromState, dir_h, dir_v)) {
        const auto to = std::make_pair(from.first + dir_h, from.second + dir_v);
        possibles.push_back(denormalizeColumnRow(to));
    }
}

bool CBoard::hasCapture(const std::pair<int, int> & from,
                        ESquare fromState,
                        int dir_h,
                        int dir_v) const {
    const auto to = std::make_pair(from.first + dir_h, from.second + dir_v);
    const auto toState = square(to);
    if (toState == fromState || toState == ESquare::EMPTY || toState == ESquare::VOID) {
        return false;
    }
    // at this point the square is occupied by the opponent
    const auto to_2 = std::make_pair(to.first + dir_h, to.second + dir_v);
    return square(to_2) == ESquare::EMPTY;
}

bool CBoard::hasMove(const std::pair<int, int> & from,
                     ESquare fromState,
                     int dir_h,
                     int dir_v) const {
    if (fromState == ESquare::WHITE and dir_v == 1) {
        return false;
    }
    if (fromState == ESquare::BLACK and dir_v == -1) {
        return false;
    }
    const auto to = std::make_pair(from.first + dir_h, from.second + dir_v);
    const auto toState = square(to);
    return toState == ESquare::EMPTY;
}

}
