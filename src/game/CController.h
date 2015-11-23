
#pragma once

#include "ui/IUI.h"

#include <memory>

namespace game {

class CController {
    public:
        CController(std::unique_ptr<ui::IUI> ui);
        void run();
    private:
        std::unique_ptr<ui::IUI> ui_;
};

}
