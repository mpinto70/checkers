
#include "testCController.h"

#include "../mck/ui/CUIMock.h"

#include "game/CController.h"
#include "util/CException.h"

namespace game {

void testCController::testCreation() {
    std::unique_ptr<ui::IUI> mock(new ui::mck::CUIMock());
    CController cont{std::move(mock)};
    TS_ASSERT_THROWS_NOTHING(cont.run());
}

}

