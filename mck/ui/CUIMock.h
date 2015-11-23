#pragma once

#include "ui/IUI.h"

namespace ui {
namespace mck {

class CUIMock: public IUI {
    public:
        CUIMock();
        virtual ~CUIMock() = default;
        void show(const board::CBoard & board) const override;
        std::pair<int, int> askForMove() const override;
        void showInvalidMove(std::pair<int, int> move) const override;
        void announceWinner(board::ESquare color) const override;

        static std::vector<board::ESquare> states();
    private:
        static std::vector<board::ESquare> states_;
        static std::vector<std::pair<int, int>> moves_;
};

}
}
