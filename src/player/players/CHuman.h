
#pragma once

#include "player/IPlayer.h"

namespace player {

class CHuman: public IPlayer {
    public:
        CHuman();
        ~CHuman() override = default;
        std::pair<int, int> play(const board::CBoard & board,
                                 const std::vector<int> & possible,
                                 ui::IUI & ui) const override;
};

}
