
#include "IUI.h"

namespace ui {

IUI::IUI() {
}

}

void ui::IUI::show(const board::CBoard& board,
                   board::ESquare color) const {
    show(board);
    showPlayer(color);
}
