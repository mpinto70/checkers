
#pragma once

#include "board/CBoard.h"

namespace ui {

class IUI {
    public:
        IUI();
        virtual ~IUI() = default;
        virtual void show(const board::CBoard & board) const = 0;
        virtual std::pair<int, int> askForMove() const = 0;
        virtual void showInvalidMove(std::pair<int, int> move) const = 0;
        virtual void announceWinner(board::ESquare color) const = 0;
};

}
