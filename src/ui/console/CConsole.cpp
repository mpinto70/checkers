
#include "CConsole.h"

#include <iostream>

namespace ui {
namespace console {

CConsole::CConsole()
    : IUI() {
}

const std::string WHITE = "o ";
const std::string BLACK = "x ";
const std::string OTHER = ". ";

static std::string format(board::ESquare state) {
    switch (state) {
    case board::ESquare::WHITE:
           return WHITE;
    case board::ESquare::BLACK:
            return BLACK;
    default:
        return OTHER;
    }
}
void CConsole::show(const board::CBoard& board) const {
    for (int i = 1; i <= 32; ++i) {
        if ((i - 1) % 4 == 0) {
            std::cout << std::endl;
        }
        const int row = (i - 1) / 4;
        if (row % 2 == 0)
            std::cout << OTHER << format(board.square(i));
        else
            std::cout << format(board.square(i)) << OTHER;
    }
    std::cout << std::endl;
}

std::pair<int, int> CConsole::askForMove() const {
    std::cout << "Enter the piece to move: ";
    int ini;
    std::cin >> ini;
    std::cout << "Enter the destination square: ";
    int fin;
    std::cin >> fin;
    return std::make_pair(ini, fin);
}

}
}
