
#pragma once

#include "player/IPlayer.h"

namespace player {
namespace mck {

class CPlayerMock: public IPlayer {
    public:
        CPlayerMock();
        ~CPlayerMock() override = default;
        std::pair<int, int> play(const board::CBoard & board,
                                 const std::vector<int> & possible,
                                 ui::IUI & ui) const override;
};

}
}
