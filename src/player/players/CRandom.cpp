
#include "CRandom.h"
#include <random>

namespace player {

CRandom::CRandom()
    : IPlayer() {
}

std::pair<int, int> CRandom::play(const board::CBoard & board,
                                  const std::vector<int> & possible,
                                  ui::IUI & ui) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distPossible(0, possible.size() - 1);

    const int from = possible.at(distPossible(gen));

    const auto destinations = board.possibleDestinationsFrom(from);
    std::uniform_int_distribution<> distDestinations(0, destinations.size() - 1);

    const int to = destinations.at(distDestinations(gen));

    return std::make_pair(from, to);
}

}
