// Namespace2.h
#include <cxxtest/TestSuite.h>

namespace foo { namespace bar { class MyTestSuite1; } }

class foo::bar::MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void testAddition() {
            TS_ASSERT(1 + 1 > 1);
            TS_ASSERT_EQUALS(1 + 1, 2);
        }
};


namespace FOO { namespace BAR { class MyTestSuite1; } }

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void testAddition() {
            TS_ASSERT(1 + 1 > 1);
            TS_ASSERT_EQUALS(1 + 1, 2);
        }
};

