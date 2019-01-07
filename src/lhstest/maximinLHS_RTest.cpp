/**
 * @file maximinLHS_RTest.cpp
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

#include "maximinLHS_RTest.h"

namespace lhsTest{
	void maximinLHS_RTest::Run()
	{
		printf("\tmaximinLHS_RTest...");
		testMaximinLHS_R();
		testStress();
		printf("passed\n");
	}

	void maximinLHS_RTest::testMaximinLHS_R()
	{
		int n = 4;
		int k = 3;
		int DUP = 5;
        bclib::matrix<int> result = bclib::matrix<int>(n, k);

        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);
		lhslib::maximinLHS(n, k, DUP, result, oRandom);

		int expected[12] = {4,1,3,
                            2,4,1,
                            1,3,4,
                            3,2,2};
		for (int i = 0; i < n*k; i++)
		{
            bclib::Assert(expected[i], result.getDataVector()[i], "Failed 1");
		}
		
		ASSERT_THROW(lhslib::maximinLHS(-1, k, DUP, result, oRandom));
		ASSERT_THROW(lhslib::maximinLHS(n, -1, DUP, result, oRandom));
		ASSERT_THROW(lhslib::maximinLHS(n, k, -1, result, oRandom));
		
		bclib::matrix<int> result2 = bclib::matrix<int>(2, k);
		ASSERT_THROW(lhslib::maximinLHS(n, k, DUP, result2, oRandom));
		bclib::matrix<int> result3 = bclib::matrix<int>(n, k+1);
		ASSERT_THROW(lhslib::maximinLHS(n, k, DUP, result3, oRandom));
	}

/*
require(lhs)

RNGkind("Marsaglia-Multicarry")
RNGkind()
.Random.seed

.Random.seed <- as.integer(c(401, 1976, 1968))
.Random.seed
floor(4*maximinLHS(4,3,5))+1
.Random.seed
*/

    void maximinLHS_RTest::testStress()
    {
        int n = 4;
        int k = 3;
        int DUP = 5;
        bclib::matrix<int> result = bclib::matrix<int>(n, k);

        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);
        for (int i = 0; i < 50; i++)
        {
            lhslib::maximinLHS(n, k, DUP, result, oRandom);
        }
    }
}
