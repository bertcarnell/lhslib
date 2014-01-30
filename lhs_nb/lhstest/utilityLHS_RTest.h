#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "utilityLHS.h"
#include "matrix.h"
#include "CommonDefines.h"

namespace lhsTest {
	class utilityLHSTest : public bclib::TestClass
	{
		void Run();
		void testLhsCheck();
		void testRank();
		void testRankColumns();
		void testLhsPrint();
		void testSumInvDistance();
	};
}
