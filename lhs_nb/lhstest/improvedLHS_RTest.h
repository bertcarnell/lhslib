#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "utilityLHS.h"
#include "CommonDefines.h"

namespace lhsTest {
	class improvedLHS_RTest : public bclib::TestClass
	{
		void Run();
		void testImprovedLHS_R();
		void testStress();
	};
}