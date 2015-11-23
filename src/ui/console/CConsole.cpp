
#include "CConsole.h"

#include <iostream>

namespace ui {
namespace console {

CConsole::CConsole()
    : IUI() {
}

const std::string WHITE = "[o]";
const std::string BLACK = "[x]";
const std::string OTHER = "[ ]";
const std::string VOID  = "     ";

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

static std::string format(int i, const board::CBoard & board) {
    const auto mark = format(board.square(i));
    const auto num = std::to_string(i) + ((i < 10) ? " " : "");
    return mark + num;
}

void CConsole::show(const board::CBoard& board) const {
    for (int i = 1; i <= 32; ++i) {
        if ((i - 1) % 4 == 0) {
            std::cout << std::endl << std::endl;
        }
        const int row = (i - 1) / 4;
        if (row % 2 == 0)
            std::cout << VOID << format(i, board);
        else
            std::cout << format(i, board) << VOID;
    }
    std::cout << std::endl << std::endl;
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

void ui::console::CConsole::showInvalidMove(std::pair<int, int> move) const {
    std::cout << "You entered an invalid move: " << move.first << " --> " << move.second << std::endl;
}
