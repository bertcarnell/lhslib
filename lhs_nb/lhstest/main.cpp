/**
 * @file main.cpp
 * @author Robert Carnell
 * @copyright Copyright (c) 2014, Robert Carnell
 * 
 * @license <a href="http://www.gnu.org/licenses/lgpl.html">GNU Lesser General Public License (LGPL v3)</a>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
