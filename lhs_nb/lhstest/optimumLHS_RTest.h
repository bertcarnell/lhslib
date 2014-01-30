#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "CommonDefines.h"
#include "utilityLHS.h"

namespace lhsTest {
	class optimumLHS_RTest : public bclib::TestClass
	{
		void Run();
		void testOptimumLHS_R();
		void testStress();
	};
}