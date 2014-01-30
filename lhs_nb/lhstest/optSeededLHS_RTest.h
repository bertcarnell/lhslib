#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "CommonDefines.h"
#include "utilityLHS.h"

namespace lhsTest {
	class optSeededLHS_RTest : public bclib::TestClass
	{
		void Run();
		void testOptSeededLHS_R();
		void testStress();
	};
}