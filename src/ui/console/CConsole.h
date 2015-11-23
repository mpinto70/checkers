#pragma once

#include "ui/IUI.h"

namespace ui {
namespace console {

class CConsole: public IUI {
    public:
        CConsole();
        virtual ~CConsole() = default;
        void show(const board::CBoard & board) const override;
        void showPlayer(board::ESquare color) const override;
        std::pair<int, int> askForMove() const override;
        void showInvalidMove(std::pair<int, int> move) const override;
        void announceWinner(board::ESquare color) const override;
};

}
}
