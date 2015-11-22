
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
};

}
using board::TestCBoard;

