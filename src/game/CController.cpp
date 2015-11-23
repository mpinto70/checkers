
#include "CController.h"

#include <algorithm>

namespace game {

CController::CController(std::unique_ptr<ui::IUI> ui,
                         std::unique_ptr<player::IPlayer> whites,
                         std::unique_ptr<player::IPlayer> blacks)
    : ui_(std::move(ui)) {
    if (not ui_) {
        throw std::invalid_argument("CController - null UI");
    }

    if (not whites) {
        throw std::invalid_argument("CController - no WHITES player");
    }

    if (not blacks) {
        throw std::invalid_argument("CController - no BLACKS player");
    }

    players_.insert(std::make_pair(board::ESquare::WHITE, std::move(whites)));
    players_.insert(std::make_pair(board::ESquare::BLACK, std::move(blacks)));
}

static board::ESquare switchColor(const board::ESquare currentColor) {
    if (currentColor == board::ESquare::WHITE) {
        return board::ESquare::BLACK;
    } else {
        return board::ESquare::WHITE;
    }

}

void CController::run() {
    board::CBoard board;
    auto currentColor = board::ESquare::WHITE;
    std::vector<int> captures;
    std::vector<int> moves;
    while (not(captures = board.squaresWithCapture(currentColor)).empty()
            || not(moves = board.squaresWithMove(currentColor)).empty()) {
        ui_->show(board);
        auto * currentPlayer = players_.find(currentColor)->second.get();

        const std::vector<int> possible = captures.empty() ? moves : captures;
        const auto move = currentPlayer->play(board, possible, *ui_);

        if (move == std::pair<int, int>(0, 0))
            break;

        if (not board.isValid(move.first) || not board.isValid(move.second)) {
            ui_->showInvalidMove(move);
            continue;
        }

        const auto dests = board.possibleDestinationsFrom(move.first);
        if (std::find(dests.begin(), dests.end(), move.second) == dests.end()) {
            ui_->showInvalidMove(move);
            continue;
        }

        if (not captures.empty()) {
            if (std::find(captures.begin(), captures.end(), move.first) == captures.end()) {
                ui_->showInvalidMove(move);
                continue;
            }
            // erase captured
        } else {
            if (std::find(moves.begin(), moves.end(), move.first) == moves.end()) {
                ui_->showInvalidMove(move);
                continue;
            }
        }
        board.free(move.first);
        board.set(move.second, currentColor);

        currentColor = switchColor(currentColor);
    }

    currentColor = switchColor(currentColor);

    ui_->announceWinner(currentColor);

}

}
