
#include "testCController.h"

#include "game/CController.h"
#include "util/CException.h"

namespace game {

void testCController::testCreation() {
    CController cont{};
    TS_ASSERT_THROWS_NOTHING(cont.run());
}

}

