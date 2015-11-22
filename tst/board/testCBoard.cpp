
#include "testCBoard.h"

#include "board/CBoard.h"

namespace board {

void TestCBoard::testCreation() {
    TS_ASSERT_THROWS_NOTHING(CBoard b{});
}

void TestCBoard::testSquare() {
    CBoard b{};
    for (int i = 1; i < 13; ++i) {
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::BLACK);
    }
    for (int i = 13; i < 21; ++i) {
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
    }
    for (int i = 21; i < 33; ++i) {
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::WHITE);
    }
}

}

