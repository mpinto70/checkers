
#pragma once

#include "player/IPlayer.h"

namespace player {

class CRandom: public IPlayer {
    public:
        CRandom();
        ~CRandom() override = default;
        std::pair<int, int> play(const board::CBoard & board,
                                 const std::vector<int> & possible,
                                 ui::IUI & ui) const override;
};

}
