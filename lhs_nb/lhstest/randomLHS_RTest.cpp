/**
 * @file randomLHS_RTest.cpp
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

#include "randomLHS_RTest.h"

namespace lhsTest{
	void randomLHS_RTest::Run()
	{
		printf("\trandomLHS_RTest...");
        testRandomLHS_R();
		printf("passed\n");
	}

	void randomLHS_RTest::testRandomLHS_R()
	{
		int n = 4;
		int k = 3;
		bool bPreserveDraw = false;
        bclib::matrix<double> result = bclib::matrix<double>(n,k);
        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);
        
        lhslib::randomLHS(n, k, bPreserveDraw, result, oRandom);
        bclib::Assert(k, result.colsize());
        bclib::Assert(n, result.rowsize());

        int counterPerColumn;
        for (int jcol = 0; jcol < k; jcol++)
        {
            for (int counter = 0; counter < n; counter++)
            {
                counterPerColumn = 0;
                for (int irow = 0; irow < n; irow++)
                {
                    double temp = result(irow, jcol);
                    if (temp >= static_cast<double>(counter) / static_cast<double>(n) &&
                            temp < static_cast<double>(counter+1) / static_cast<double>(n))
                    {
                        bclib::Assert(0, counterPerColumn);
                        counterPerColumn++;
                    }
                }
            }
        }
        
        result.clear();
        result = bclib::matrix<double>(n,k);
        lhslib::randomLHS(n, k, true, result, oRandom);
        bclib::Assert(k, result.colsize());
        bclib::Assert(n, result.rowsize());

        for (int jcol = 0; jcol < k; jcol++)
        {
            for (int counter = 0; counter < n; counter++)
            {
                counterPerColumn = 0;
                for (int irow = 0; irow < n; irow++)
                {
                    double temp = result(irow, jcol);
                    if (temp >= static_cast<double>(counter) / static_cast<double>(n) &&
                            temp < static_cast<double>(counter+1) / static_cast<double>(n))
                    {
                        bclib::Assert(0, counterPerColumn);
                        counterPerColumn++;
                    }
                }
            }
        }
		
		result = bclib::matrix<double>(n,k);
		ASSERT_THROW(lhslib::randomLHS(-1, k, false, result, oRandom));
		ASSERT_THROW(lhslib::randomLHS(n, -3, false, result, oRandom));
		result = bclib::matrix<double>(n+1,k);
		ASSERT_THROW(lhslib::randomLHS(n, k, false, result, oRandom));
		result = bclib::matrix<double>(n, k+2);
		ASSERT_THROW(lhslib::randomLHS(n, k, false, result, oRandom));
    }
}


