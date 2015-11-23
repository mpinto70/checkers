
#include "ui/console/CConsole.h"
#include "ui/IUI.h"
#include "player/players/CHuman.h"
#include "player/players/CRandom.h"
#include "player/IPlayer.h"
#include "game/CController.h"
#include "util/CException.h"

#include <iostream>
#include <memory>

int main() {
    try {
        std::unique_ptr<ui::IUI> console(new ui::console::CConsole());
        std::unique_ptr<player::IPlayer> player1(new player::CHuman());
        std::unique_ptr<player::IPlayer> player2(new player::CRandom());
        game::CController controller{std::move(console), std::move(player1), std::move(player2)};
        controller.run();
        return 0;
    } catch (const util::CException & e) {
        std::cout << "An ERROR occurred" << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }
}

