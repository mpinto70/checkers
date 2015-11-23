
#pragma once

#include <cxxtest/TestSuite.h>

namespace board {

class TestCBoard: public CxxTest::TestSuite {
    public:
        void testCreation();
        void testSquare();
        void testSquareInvalid();
        void testFree();
        void testSet();
        void testPossibleDestinationsFromBlack();
        void testPossibleDestinationsFromWhite();
        void testPossibleDestinationsWithCapture();
};

}
using board::TestCBoard;

