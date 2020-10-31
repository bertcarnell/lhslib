/**
 * @file optSeededLHS_RTest.h
 * @author Robert Carnell
 * @copyright Copyright (c) 2014, Robert Carnell
 * 
 * License <a href="http://www.gnu.org/licenses/lgpl.html">GNU Lesser General Public License (LGPL v3)</a>
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

#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "LHSCommonDefines.h"
#include "utilityLHS.h"

namespace lhsTest {
    /**
     * class to test the optSeededLHS method
     */
	class optSeededLHS_RTest : public bclib::TestClass
	{
		void Run(); /**< run the test suite */
		void testOptSeededLHS_R(); /**< Test the optSeededLHS method */
		void testStress(); /**< Test the optSeededLHS repeatedly */
	};
}