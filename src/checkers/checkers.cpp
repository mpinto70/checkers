
#include "game/CController.h"
#include "util/CException.h"

#include <iostream>
#include <memory>

int main() {
    try {
        game::CController controller{};
        controller.run();
        return 0;
    } catch (const util::CException & e) {
        std::cout << "An ERROR occurred" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "Code: " << e.code() << std::endl;
        return 1;
    }
}

