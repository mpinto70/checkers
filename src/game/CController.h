
#pragma once

#include "player/IPlayer.h"
#include "ui/IUI.h"
#include "board/CBoard.h"

#include <map>
#include <memory>

namespace game {

class CController {
    public:
        CController(std::unique_ptr<ui::IUI> ui,
                    std::unique_ptr<player::IPlayer> whites,
                    std::unique_ptr<player::IPlayer> blacks);
        void run();
    private:
        std::unique_ptr<ui::IUI> ui_;
        std::map<board::ESquare, std::unique_ptr<player::IPlayer>> players_;
};

}
