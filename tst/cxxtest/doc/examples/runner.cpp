/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite2_init = false;
#include "/home/marcelo/projetos/cxxtest/doc/examples/MyTestSuite2.h"

static MyTestSuite2 suite_MyTestSuite2;

static CxxTest::List Tests_MyTestSuite2 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite2( "MyTestSuite2.h", 4, "MyTestSuite2", suite_MyTestSuite2, Tests_MyTestSuite2 );

static class TestDescription_suite_MyTestSuite2_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite2_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite2, suiteDescription_MyTestSuite2, 6, "testAddition" ) {}
 void runTest() { suite_MyTestSuite2.testAddition(); }
} testDescription_suite_MyTestSuite2_testAddition;

static class TestDescription_suite_MyTestSuite2_testMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite2_testMultiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite2, suiteDescription_MyTestSuite2, 11, "testMultiplication" ) {}
 void runTest() { suite_MyTestSuite2.testMultiplication(); }
} testDescription_suite_MyTestSuite2_testMultiplication;

static MyTestSuite2b suite_MyTestSuite2b;

static CxxTest::List Tests_MyTestSuite2b = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite2b( "MyTestSuite2.h", 18, "MyTestSuite2b", suite_MyTestSuite2b, Tests_MyTestSuite2b );

static class TestDescription_suite_MyTestSuite2b_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite2b_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite2b, suiteDescription_MyTestSuite2b, 20, "testAddition" ) {}
 void runTest() { suite_MyTestSuite2b.testAddition(); }
} testDescription_suite_MyTestSuite2b_testAddition;

static class TestDescription_suite_MyTestSuite2b_testMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite2b_testMultiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite2b, suiteDescription_MyTestSuite2b, 25, "testMultiplication" ) {}
 void runTest() { suite_MyTestSuite2b.testMultiplication(); }
} testDescription_suite_MyTestSuite2b_testMultiplication;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
