
#include "ui/console/CConsole.h"
#include "ui/IUI.h"
#include "game/CController.h"
#include "util/CException.h"

#include <iostream>
#include <memory>

int main() {
    try {
        std::unique_ptr<ui::IUI> console(new ui::console::CConsole());
        game::CController controller{std::move(console)};
        controller.run();
        return 0;
    } catch (const util::CException & e) {
        std::cout << "An ERROR occurred" << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }
}

