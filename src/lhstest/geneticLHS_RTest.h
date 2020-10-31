/**
 * @file geneticLHS_RTest.h
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

#ifndef GENETICLHS_RTEST_H
#define	GENETICLHS_RTEST_H

#include <cstdlib>
#include "TestClass.h"
#include "utilityLHS.h"
#include "LHSCommonDefines.h"

namespace lhsTest {
	/** Class to test the geneticLHS algorithm */
	class geneticLHS_RTest : public bclib::TestClass
	{
    public:
		/** Run the test suite */
		void Run();
		/** @test Test the geneticLHS algorithm */
		void testGeneticLHS_R();
		/** @test Test geneticLHS under many conditions */
        void testStress();
	};
}

#endif	/* GENETICLHS_RTEST_H */

