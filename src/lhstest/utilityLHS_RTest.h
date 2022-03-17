/**
 * @file utilityLHS_RTest.h
 * @author Robert Carnell
 * @copyright Copyright (c) 2022, Robert Carnell
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
#include "utilityLHS.h"
#include "matrix.h"
#include "LHSCommonDefines.h"

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
         * @test Test lhsCheck 
         */
		void testLhsCheck();
        /** 
         * @test Test rank 
         */
		void testRank();
        /** 
         * @test Test lhsPrint 
         */
		void testLhsPrint();
        /** 
         * @test Test sumInvDistance 
         */
		void testSumInvDistance();
		/** @test test the algorithm to calculate the distance between points */
        void testCalculateDistance();
		/** @test Test the calculation of S optimality */
        void testCalculateSOptimal();
		/** @test Test the initialization of the available points matrix */
        void testInitializeAvailableMatrix();
		/** @test copying matrices*/
        void testCopyMatrix();
		/** @test test the operation of the Runif method */
        void testRunif_std();
		/** @test Test the operation of the random sample on the integers */
        void testRunifint();
		/** @test Test the square difference function */
		void testSquareDifference();
		/** @test test the inverse function */
		void testInverse();
	};
}
