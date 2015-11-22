
#pragma once

#include <cxxtest/TestSuite.h>

namespace board {

class TestCBoard: public CxxTest::TestSuite {
    public:
        void testCreation();
        void testSquare();
};

}
using board::TestCBoard;

