#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "defines.h"
#include "CommonDefines.h"

namespace lhsTest {
	class maximinLHS_RTest : public bclib::TestClass
	{
		void Run();
		void testMaximinLHS_R();
		void testStress();
	};
}