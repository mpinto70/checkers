
#pragma once

#include <array>
#include <iosfwd>
#include <vector>

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
        void set(int squareNumber,
                 ESquare state);
        std::vector<int> squaresWithCapture(ESquare state) const;
        std::vector<int> squaresWithMove(ESquare state) const;
        std::vector<int> possibleDestinationsFrom(int squareNumber) const;
    private:
        std::array<ESquare, 64> squares;

        void validateSquareNumber(const std::string & function,
                                  int squareNumber) const;
        std::pair<int, int> normalizeSquareNumber(int squareNumber) const;
        int denormalizeColumnRow(const std::pair<int, int> & columnRow) const;
        ESquare square(const std::pair<int, int> & columnRow) const;
        int index(const std::pair<int, int> & columnRow) const;
        void set(const std::string & function,
                 int squareNumber,
                 ESquare state);

        template <typename T>
        std::vector<int> squaresWithOperation(T func,
                                              ESquare fromState) const;
        template <typename T>
        bool hasOperation(T func,
                          int squareNumber,
                          ESquare fromState) const;
        template <typename T>
        void addPossibles(T func,
                          std::vector<int> & possibles,
                          const std::pair<int, int> & from,
                          ESquare fromState) const;
        void addPossibleCaptures(std::vector<int> & possibles,
                                 const std::pair<int, int> & from,
                                 ESquare fromState) const;
        void addPossibleCapture(std::vector<int> & possibles,
                                const std::pair<int, int> & from,
                                ESquare fromState,
                                int dir_h,
                                int dir_v) const;
        void addPossibleMoves(std::vector<int> & possibles,
                              const std::pair<int, int> & from,
                              ESquare fromState) const;
        void addPossibleMove(std::vector<int> & possibles,
                             const std::pair<int, int> & from,
                             ESquare fromState,
                             int dir_h,
                             int dir_v) const;
        bool hasCapture(const std::pair<int, int> & from,
                        ESquare fromState,
                        int dir_h,
                        int dir_v) const;
        bool hasMove(const std::pair<int, int> & from,
                     ESquare fromState,
                     int dir_h,
                     int dir_v) const;
};

}
