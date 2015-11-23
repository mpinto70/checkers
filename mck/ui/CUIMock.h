#pragma once

#include "ui/IUI.h"

namespace ui {
namespace mck {

class CUIMock: public IUI {
    public:
        CUIMock();
        virtual ~CUIMock() = default;
        void show(const board::CBoard & board) const override;
        static std::vector<board::ESquare> states();
    private:
        static std::vector<board::ESquare> states_;
};

}
}
