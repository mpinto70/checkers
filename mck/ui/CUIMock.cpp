
#include "CUIMock.h"

#include <iostream>

namespace ui {
namespace mck {

std::vector<board::ESquare> CUIMock::states_;
std::vector<std::pair<int, int>> CUIMock::moves_;

CUIMock::CUIMock()
    : IUI() {
}

void CUIMock::show(const board::CBoard& board) const {
    std::vector<board::ESquare> st;
    st.reserve(24);
    for (int i = 1; i <= 32; ++i) {
        const int row = (i - 1) / 4;
        if (row % 2 == 0) {
            st.push_back(board::ESquare::VOID);
            st.push_back(board.square(i));
        } else {
            st.push_back(board.square(i));
            st.push_back(board::ESquare::VOID);
        }
    }
    states_.swap(st);
}

std::vector<board::ESquare> CUIMock::states() {
    return states_;
}

std::pair<int, int> CUIMock::askForMove() const {
    if (moves_.empty())
        return std::make_pair(0, 0);
    auto res = moves_[0];
    moves_.erase(moves_.begin());
    return res;
}


}
}
