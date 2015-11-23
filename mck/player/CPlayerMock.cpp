
#include "CPlayerMock.h"

namespace player {
namespace mck {

CPlayerMock::CPlayerMock()
    : IPlayer() {
}

std::pair<int, int> CPlayerMock::play(const board::CBoard & board,
                                      const std::vector<int> & possible,
                                      ui::IUI & ui) const {
    return ui.askForMove();
}

}
}
