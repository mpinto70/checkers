
#include "CHuman.h"

namespace player {

CHuman::CHuman()
    : IPlayer() {
}

std::pair<int, int> CHuman::play(const board::CBoard & board,
                                 const std::vector<int> & possible,
                                 ui::IUI & ui) const {
    return ui.askForMove();
}

}
