#pragma once

#include <cstdlib>
#include <vector>
#include <exception>
#include <string>

namespace lhsTest
{
	class TestClass
	{
	public:
		virtual void Run(){};
		void Assert(bool test, std::string msg);
	};
}
