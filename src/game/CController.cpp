
#include "CController.h"

namespace game {

CController::CController(std::unique_ptr<ui::IUI> ui)
    : ui_(std::move(ui)) {
    if (not ui_) {
        throw std::invalid_argument("CController - null UI");
    }
}

void CController::run() {
    board::CBoard board;
    ui_->show(board);
}

}
