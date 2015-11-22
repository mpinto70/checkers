
#include "testCException.h"

#include "util/CException.h"

#include <type_traits>

namespace util {

void TestCException::testHierarchy() {
    TS_ASSERT((std::is_base_of<std::runtime_error, CException>::value));
    TS_ASSERT((std::is_default_constructible<CException>::value) == false);
    TS_ASSERT((std::is_base_of<CException, CSquareOutOfRange>::value));
    TS_ASSERT((std::is_default_constructible<CSquareOutOfRange>::value) == false);
    TS_ASSERT((std::is_base_of<CException, CInvalidSquareState>::value));
    TS_ASSERT((std::is_default_constructible<CInvalidSquareState>::value) == false);
}

void TestCException::testCreationException() {
    CException e("message");
    TS_ASSERT_EQUALS(std::string(e.what()), "message");
}

void TestCException::testCreationSquareOutOfRange() {
    CSquareOutOfRange e("message");
    TS_ASSERT_EQUALS(std::string(e.what()), "message");
}

void TestCException::testCreationInvalidSquareState() {
    CInvalidSquareState e("message");
    TS_ASSERT_EQUALS(std::string(e.what()), "message");
}

}
