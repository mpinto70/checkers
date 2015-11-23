
#pragma once

#include "ui/IUI.h"
#include "board/CBoard.h"

#include <utility>

namespace player {

class IPlayer {
    public:
        IPlayer();
        virtual ~IPlayer() = default;
        virtual std::pair<int, int> play(const board::CBoard & board,
                                         const std::vector<int> & possible,
                                         ui::IUI & ui) const = 0;
};

}
