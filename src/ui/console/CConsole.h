#pragma once

#include "ui/IUI.h"

namespace ui {
namespace console {

class CConsole: public IUI {
    public:
        CConsole();
        virtual ~CConsole() = default;
        void show(const board::CBoard & board) const override;

};

}
}
