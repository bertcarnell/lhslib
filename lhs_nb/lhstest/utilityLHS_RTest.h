/**
 * @file utilityLHS_RTest.h
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

#pragma once

#include <cstdlib>
#include "TestClass.h"
#include "utilityLHS.h"
#include "matrix.h"
#include "CommonDefines.h"

/**
 * @namespace lhsTest A collections of tests for the lhs methods
 */
namespace lhsTest {
    /**
     * A class to test the utility methods of the lhs library
     */
	class utilityLHSTest : public bclib::TestClass
	{
    public:
        /** 
         * Run the Test methods 
         */
		void Run();
        /** 
         * Test lhsCheck 
         */
		void testLhsCheck();
        /** 
         * Test rank 
         */
		void testRank();
        /** 
         * Test rankColumns 
         */
		void testRankColumns();
        /** 
         * Test lhsPrint 
         */
		void testLhsPrint();
        /** 
         * Test sumInvDistance 
         */
		void testSumInvDistance();
	};
}
