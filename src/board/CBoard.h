
#pragma once

#include <array>
#include <iosfwd>

namespace board {

enum class ESquare {
    WHITE,
    BLACK,
    EMPTY,
    VOID
};

/** class responsible for representing the checkers board.
 * it uses a notation specified in en.wikipedia.org/wiki/English_draughts#Notation (black on top and numbering starting on top left square)
 */
class CBoard {
    public:
        CBoard();
        ESquare square(int squareNumber) const;
        void free(int squareNumber);
        void set(int squareNumber, ESquare state);
    private:
        std::array<ESquare, 64> squares;

        std::pair<int, int> normalizedColumnRow(int squareNumber) const;
        ESquare square(const std::pair<int, int> & columnRow) const;
        int index(const std::pair<int, int> & columnRow) const;
        void set(const std::string & function, int squareNumber, ESquare state);
};

}
