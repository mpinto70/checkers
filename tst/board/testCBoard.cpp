
#include "testCBoard.h"

#include "board/CBoard.h"
#include "util/CException.h"

namespace board {

void TestCBoard::testCreation() {
    TS_ASSERT_THROWS_NOTHING(CBoard b{});
}

void TestCBoard::testSquare() {
    const CBoard b{};
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

void TestCBoard::testSquareInvalid() {
    const CBoard b{};
    TS_ASSERT_THROWS_EQUALS(b.square(0),
                            util::CSquareOutOfRange & e,
                            std::string(e.what()),
                            "CBoard::square - square number [0] out of range");
    TS_ASSERT_THROWS_EQUALS(b.square(33),
                            util::CSquareOutOfRange & e,
                            std::string(e.what()),
                            "CBoard::square - square number [33] out of range");
}

void TestCBoard::testFree() {
    CBoard b{};

    for (int i = 1; i < 13; ++i) {
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::BLACK);
        TSM_ASSERT_THROWS_NOTHING(i, b.free(i));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
    }
    for (int i = 13; i < 21; ++i) {
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
        TSM_ASSERT_THROWS_NOTHING(i, b.free(i));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
    }
    for (int i = 21; i < 33; ++i) {
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::WHITE);
        TSM_ASSERT_THROWS_NOTHING(i, b.free(i));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
    }
}

void TestCBoard::testSet() {
    CBoard b{};

    for (int i = 1; i < 33; ++i) {
        b.free(i);
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);

        TSM_ASSERT_THROWS_NOTHING(i, b.set(i, ESquare::BLACK));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::BLACK);
        TSM_ASSERT_THROWS_NOTHING(i, b.set(i, ESquare::BLACK));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::BLACK);
        TSM_ASSERT_THROWS_NOTHING(i, b.set(i, ESquare::WHITE));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::WHITE);
        TSM_ASSERT_THROWS_NOTHING(i, b.set(i, ESquare::WHITE));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::WHITE);
        TSM_ASSERT_THROWS_NOTHING(i, b.set(i, ESquare::EMPTY));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
        TSM_ASSERT_THROWS_NOTHING(i, b.set(i, ESquare::EMPTY));
        TSM_ASSERT_EQUALS(i, b.square(i), ESquare::EMPTY);
    }
}

}

