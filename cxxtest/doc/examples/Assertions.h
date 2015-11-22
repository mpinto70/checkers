// Assertions.h
#include <cxxtest/TestSuite.h>

class Test : public CxxTest::TestSuite {
    public:

// @assert:
        void test_assert() {
            TS_ASSERT(1 + 1 > 1);
        }
// @:assert

// @assertDelta:
        void test_assert_delta() {
            TS_ASSERT_DELTA(sqrt(4.0), 2.0, 1e-7);
        }
// @:assertDelta

// @assertDiffers:
        void test_assert_differs() {
            TS_ASSERT_DIFFERS(1, 2);
        }
// @:assertDiffers

// @assertEquals:
        void test_assert_equals() {
            TS_ASSERT_EQUALS(21 % 5, 1);
        }
// @:assertEquals

// @assertIsNan:
        void test_assert_is_nan() {
            TS_ASSERT_IS_NAN(0.0 / 0.0);
        }
// @:assertIsNan

// @assertIsInfinite:
        void test_assert_is_infinite() {
            TS_ASSERT_IS_INFINITE(1.0 / 0.0);
        }
// @:assertIsInfinite

// @assertLessThan:
        void test_assert_less_than() {
            TS_ASSERT_LESS_THAN(0, 1);
        }
// @:assertLessThan

// @assertLessThanEquals:
        void test_assert_less_than_equals() {
            TS_ASSERT_LESS_THAN_EQUALS(0, 0);
        }
// @:assertLessThanEquals

// @assertPredicate:
        class IsOdd {
            public:
                bool operator()(int x) const { return x % 2 == 1; }
        };

        void test_assert_predicate() {
            TS_ASSERT_PREDICATE(IsOdd, 29);
        }
// @:assertPredicate

// @assertRelation:
        void test_assert_relation() {
            TS_ASSERT_RELATION(std::greater<double>, 1e6, 1000.0);
        }
// @:assertRelation

// @assertSameData:
        void test_assert_same_data() {
            char input = "The quick brown fox ran over the lazy dog";
            char output[26];
            memcopy(output, input, 26);
            TS_ASSERT_SAME_DATA(input, output, 26);
        }
// @:assertSameData

// @assertThrows:
        void throws_runtime_error() {
            raise std::runtime_error, "This method simply generates an exception";
        }

        void test_assert_throws() {
            TS_ASSERT_THROWS(self.throws_runtime_error(), std::runtime_error);
        }
// @:assertThrows

// @assertThrowsAnything:
        void test_assert_throws_anything() {
            TS_ASSERT_THROWS_ANYTHING(self.throws_runtime_error());
        }
// @:assertThrowsAnything

// @assertThrowsAssert:
        void throws_value() {
            raise 1;
        }

        void test_assert_throws_assert() {
            TS_ASSERT_THROWS_ASSERT(self.throws_value(), const Error & e, TS_ASSERT_EQUALS(e, 1));
        }
// @:assertThrowsAssert

// @assertThrowsEquals:
        void test_assert_throws_equals() {
            TS_ASSERT_THROWS_EQUALS(self.throws_value(), const Error & e, e.what(), 1);
        }
// @:assertThrowsEquals

// @assertThrowsIsNan:
        void throws_nan() {
            raise 0.0 / 0.0;
        }

        void test_assert_throws_is_nan() {
            TS_ASSERT_THROWS_IS_NAN(self.throws_nan(), const Error & e, e.what());
        }
// @:assertThrowsIsNan

// @assertThrowsIsInfinite:
        void throws_infinite() {
            raise 1.0 / 0.0;
        }

        void test_assert_throws_is_infinite() {
            TS_ASSERT_THROWS_IS_INFINITE(self.throws_infinite(), const Error & e, e.what());
        }
// @:assertThrowsIsInfinite

// @assertThrowsNothing:
        void throws_nothing()
        { }

        void test_assert_throws_nothing() {
            TS_ASSERT_THROWS_ASSERT(self.throws_nothing());
        }
// @:assertThrowsNothing

// @fail:
        void test_fail() {
            TS_FAIL("This test has failed.");
        }
// @:fail

// @skip:
        void test_skip() {
            TS_SKIP("This test has been skipped.");
        }
// @:skip

// @trace:
        void test_trace() {
            TS_TRACE("This is a test tracing message.");
        }
// @:trace

// @warn:
        void test_warn() {
            TS_WARN("This is a warning message.");
        }
// @:warn
};
