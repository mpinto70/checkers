
#include "testCController.h"

#include "../mck/player/CPlayerMock.h"
#include "../mck/ui/CUIMock.h"

#include "game/CController.h"
#include "util/CException.h"

namespace game {

void testCController::testCreation() {
    std::unique_ptr<ui::IUI> ui(new ui::mck::CUIMock());
    std::unique_ptr<player::IPlayer> player1(new player::mck::CPlayerMock());
    std::unique_ptr<player::IPlayer> player2(new player::mck::CPlayerMock());
    CController cont{std::move(ui), std::move(player1), std::move(player2)};
    TS_ASSERT_THROWS_NOTHING(cont.run());
}

}

