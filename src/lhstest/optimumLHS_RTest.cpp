/**
 * @file optimumLHS_RTest.cpp
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

#include "optimumLHS_RTest.h"

namespace lhsTest{
	void optimumLHS_RTest::Run()
	{
		printf("\toptimumLHS_RTest...");
		testOptimumLHS_R();
		testStress();
		printf("passed\n");
	}

	void optimumLHS_RTest::testOptimumLHS_R()
	{
		int n = 4;
		int k = 3;
		int maxSweeps = 2;
		double eps = 0.1;
		int jLen = 7; // 4 choose 2 + 1

        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);

        bclib::matrix<int> result = bclib::matrix<int>(n, k);
        lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
		int expected[12] = {1,2,3,
                            2,4,1,
                            3,3,4,
                            4,1,2};
        
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
                bclib::Assert(expected[i*k+j] == result(i, j), "Failed optimumLHS_RTest");
			}
		}
		
		ASSERT_THROW(lhslib::optimumLHS(-1, k, maxSweeps, eps, result, jLen, oRandom, false));
		ASSERT_THROW(lhslib::optimumLHS(n, -5, maxSweeps, eps, result, jLen, oRandom, false));
		ASSERT_THROW(lhslib::optimumLHS(n, k, 0, eps, result, jLen, oRandom, false));
		ASSERT_THROW(lhslib::optimumLHS(n, k, maxSweeps, -6, result, jLen, oRandom, false));
		
		//resize
		result = bclib::matrix<int>(1,1);
        lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
		bclib::Assert(n, static_cast<int>(result.rowsize()), "resize error");
		bclib::Assert(k, static_cast<int>(result.colsize()), "resize error2");
	}


/*
require(lhs)

RNGkind("Marsaglia-Multicarry")
RNGkind()
.Random.seed

.Random.seed <- as.integer(c(401, 1976, 1968))
.Random.seed
floor(4*optimumLHS(4,3,2,0.1))+1
.Random.seed
*/

		void optimumLHS_RTest::testStress()
		{
			int n = 4;
			int k = 3;
			int maxSweeps = 2;
			double eps = 0.1;
			int jLen = n * (n - 1) / 2 + 1; // n choose 2 + 1

            bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
            oRandom.setSeed(1976, 1968);

            bclib::matrix<int> result = bclib::matrix<int>(n,k);
			for (int i = 0; i < 50; i++)
            {
                lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
            }

			for (n = 2; n < 8; n++)
            {
				jLen = n * (n - 1) / 2 + 1;
				for (k = 2; k < 8; k++)
				{
					for (maxSweeps = 1; maxSweeps < 4; maxSweeps++)
					{
						lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
					}
				}
            }

		}
}
