/**
 * @file randomLHS_RTest.h
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

#ifndef RANDOMLHS_RTEST_H
#define	RANDOMLHS_RTEST_H

#include <cstdlib>
#include "TestClass.h"
#include "utilityLHS.h"
#include "LHSCommonDefines.h"

namespace lhsTest {
    /**
     * class to test the randomLHS method
     */
	class randomLHS_RTest : public bclib::TestClass
	{
    public:
		void Run(); /**< Run the test suite */
		void testRandomLHS_R(); /**< Test randomLHS */
		void testStress(); /**< Test Stress */
	};
}

#endif	/* RANDOMLHS_RTEST_H */

