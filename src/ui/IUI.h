
#pragma once

#include "board/CBoard.h"

namespace ui {

class IUI {
    public:
        IUI();
        virtual ~IUI() = default;
        virtual void show(const board::CBoard & board) const = 0;
};

}
