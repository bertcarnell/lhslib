#include <cstdlib>
#include <cstdio>
#include <vector>
#include "TestClass.h"
#include "improvedLHS_RTest.h"
#include "maximinLHS_RTest.h"
#include "optimumLHS_RTest.h"
#include "optSeededLHS_RTest.h"
#include "utilityLHS_RTest.h"

using namespace lhsTest;

int main(int argc, const char* argv[] )
{
    START_TESTS("Starting Simple Tests...\n");
	CREATE_TEST(improvedLHS_RTest);
	CREATE_TEST(maximinLHS_RTest);
	CREATE_TEST(optimumLHS_RTest);
	CREATE_TEST(optSeededLHS_RTest);
	CREATE_TEST(utilityLHSTest);
    EXECUTE_TESTS();
}
