
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

static void setEntireBoard(CBoard & board, ESquare state) {
    for (int i = 1; i <= 32; ++i) {
        board.set(i, state);
    }
}

static void clean(CBoard & board) {
    setEntireBoard(board, ESquare::EMPTY);
}

static void verifyPossibleDestinations(ESquare state,
                                       int from,
                                       const std::vector<int> & destinations) {
    CBoard b{};
    clean(b);

    TSM_ASSERT_EQUALS(from, b.possibleDestinationsFrom(from), std::vector<int>());
    b.set(from, state);
    TSM_ASSERT_EQUALS(from, b.possibleDestinationsFrom(from), destinations);

    setEntireBoard(b, state);
    TSM_ASSERT_EQUALS(from, b.possibleDestinationsFrom(from), std::vector<int>());
}

void TestCBoard::testPossibleDestinationsFromBlack() {
    verifyPossibleDestinations(ESquare::BLACK,  1, {6, 5});
    verifyPossibleDestinations(ESquare::BLACK,  2, {7, 6});
    verifyPossibleDestinations(ESquare::BLACK,  3, {8, 7});
    verifyPossibleDestinations(ESquare::BLACK,  4, {8});
    verifyPossibleDestinations(ESquare::BLACK,  5, {9});
    verifyPossibleDestinations(ESquare::BLACK,  6, {10, 9});
    verifyPossibleDestinations(ESquare::BLACK,  7, {11, 10});
    verifyPossibleDestinations(ESquare::BLACK,  8, {12, 11});
    verifyPossibleDestinations(ESquare::BLACK,  9, {14, 13});
    verifyPossibleDestinations(ESquare::BLACK, 10, {15, 14});
    verifyPossibleDestinations(ESquare::BLACK, 11, {16, 15});
    verifyPossibleDestinations(ESquare::BLACK, 12, {16});
    verifyPossibleDestinations(ESquare::BLACK, 13, {17});
    verifyPossibleDestinations(ESquare::BLACK, 14, {18, 17});
    verifyPossibleDestinations(ESquare::BLACK, 15, {19, 18});
    verifyPossibleDestinations(ESquare::BLACK, 16, {20, 19});
    verifyPossibleDestinations(ESquare::BLACK, 17, {22, 21});
    verifyPossibleDestinations(ESquare::BLACK, 18, {23, 22});
    verifyPossibleDestinations(ESquare::BLACK, 19, {24, 23});
    verifyPossibleDestinations(ESquare::BLACK, 20, {24});
    verifyPossibleDestinations(ESquare::BLACK, 21, {25});
    verifyPossibleDestinations(ESquare::BLACK, 22, {26, 25});
    verifyPossibleDestinations(ESquare::BLACK, 23, {27, 26});
    verifyPossibleDestinations(ESquare::BLACK, 24, {28, 27});
    verifyPossibleDestinations(ESquare::BLACK, 25, {30, 29});
    verifyPossibleDestinations(ESquare::BLACK, 26, {31, 30});
    verifyPossibleDestinations(ESquare::BLACK, 27, {32, 31});
    verifyPossibleDestinations(ESquare::BLACK, 28, {32});
    verifyPossibleDestinations(ESquare::BLACK, 29, {});
    verifyPossibleDestinations(ESquare::BLACK, 30, {});
    verifyPossibleDestinations(ESquare::BLACK, 31, {});
    verifyPossibleDestinations(ESquare::BLACK, 32, {});
}

void TestCBoard::testPossibleDestinationsFromWhite() {
    verifyPossibleDestinations(ESquare::WHITE,  1, {});
    verifyPossibleDestinations(ESquare::WHITE,  2, {});
    verifyPossibleDestinations(ESquare::WHITE,  3, {});
    verifyPossibleDestinations(ESquare::WHITE,  4, {});
    verifyPossibleDestinations(ESquare::WHITE,  5, {1});
    verifyPossibleDestinations(ESquare::WHITE,  6, {1, 2});
    verifyPossibleDestinations(ESquare::WHITE,  7, {2, 3});
    verifyPossibleDestinations(ESquare::WHITE,  8, {3, 4});
    verifyPossibleDestinations(ESquare::WHITE,  9, {5, 6});
    verifyPossibleDestinations(ESquare::WHITE, 10, {6, 7});
    verifyPossibleDestinations(ESquare::WHITE, 11, {7, 8});
    verifyPossibleDestinations(ESquare::WHITE, 12, {8});
    verifyPossibleDestinations(ESquare::WHITE, 13, {9});
    verifyPossibleDestinations(ESquare::WHITE, 14, {9, 10});
    verifyPossibleDestinations(ESquare::WHITE, 15, {10, 11});
    verifyPossibleDestinations(ESquare::WHITE, 16, {11, 12});
    verifyPossibleDestinations(ESquare::WHITE, 17, {13, 14});
    verifyPossibleDestinations(ESquare::WHITE, 18, {14, 15});
    verifyPossibleDestinations(ESquare::WHITE, 19, {15, 16});
    verifyPossibleDestinations(ESquare::WHITE, 20, {16});
    verifyPossibleDestinations(ESquare::WHITE, 21, {17});
    verifyPossibleDestinations(ESquare::WHITE, 22, {17, 18});
    verifyPossibleDestinations(ESquare::WHITE, 23, {18, 19});
    verifyPossibleDestinations(ESquare::WHITE, 24, {19, 20});
    verifyPossibleDestinations(ESquare::WHITE, 25, {21, 22});
    verifyPossibleDestinations(ESquare::WHITE, 26, {22, 23});
    verifyPossibleDestinations(ESquare::WHITE, 27, {23, 24});
    verifyPossibleDestinations(ESquare::WHITE, 28, {24});
    verifyPossibleDestinations(ESquare::WHITE, 29, {25});
    verifyPossibleDestinations(ESquare::WHITE, 30, {25, 26});
    verifyPossibleDestinations(ESquare::WHITE, 31, {26, 27});
    verifyPossibleDestinations(ESquare::WHITE, 32, {27, 28});
}

static void verifyCaptures(ESquare stateSquare,
                ESquare stateOthers,
                int square,
                const std::vector<int> & others,
                const std::vector<int> & destinations) {
    CBoard b;
    clean(b);
    b.set(square, stateSquare);
    for (auto i : others) {
        b.set(i, stateOthers);
    }

    TSM_ASSERT_EQUALS(square, b.possibleDestinationsFrom(square), destinations);
}

static void verifyCaptures(int square,
                const std::vector<int> & others,
                const std::vector<int> & destinations) {
    verifyCaptures(ESquare::BLACK, ESquare::WHITE, square, others, destinations);
    verifyCaptures(ESquare::WHITE, ESquare::BLACK, square, others, destinations);
}

void TestCBoard::testPossibleDestinationsWithCapture() {
    CBoard b;
    clean(b);

    verifyCaptures(10, {14}, {17});

    verifyCaptures(10, {14, 15, 6, 7}, {1, 3, 19, 17});

    verifyCaptures(6, {1, 2, 9, 10}, {15, 13});
}

}

