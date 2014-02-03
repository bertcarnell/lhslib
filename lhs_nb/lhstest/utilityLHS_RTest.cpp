/**
 * @file utilityLHS_RTest.cpp
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

#include "utilityLHS_RTest.h"

namespace lhsTest{
	void utilityLHSTest::Run()
	{
		printf("\tutilityLHS_RTest...");
		testLhsCheck();
		testRank();
		testRankColumns();
		testLhsPrint();
		testSumInvDistance();
		printf("passed\n");
	}

	void utilityLHSTest::testLhsCheck()
	{
		int a[10] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
        bclib::matrix<int> A = bclib::matrix<int>(5, 2, a);
		bclib::Assert(lhslib::isValidLHS(A), "Failed 1");

		int b[10] = {0, 2, 3, 4, 5, 5, 4, 3, 2, 1};
        bclib::matrix<int> B = bclib::matrix<int>(5, 2, b);
		bclib::Assert(!lhslib::isValidLHS(B), "Failed 2");

		int d[10] = {1, 2, 3, 6, 5, 5, 4, 3, 2, 1};
        bclib::matrix<int> D = bclib::matrix<int>(5, 2, d);
		bclib::Assert(!lhslib::isValidLHS(D), "Failed 3");
	}

	void utilityLHSTest::testRank()
	{
		std::vector<double> a = std::vector<double>(5);
		double b[5] = {.1, .4, .2, .3, .5};
		for (int i = 0; i < 5; i++)
        {
			a[i] = b[i];
        }

		std::vector<int> d = std::vector<int>(5);
        lhslib::rank(a, d);

		int expected[5] = {4, 1, 3, 2, 0};
		for (int i = 0; i < 5; i++)
        {
			bclib::Assert(d[i] == expected[i], "failed 4");
        }

		std::vector<double> e = std::vector<double>(5);
		double f[5] = {.1, .4, .4, .3, .5};
		for (int i = 0; i < 5; i++)
        {
			e[i] = f[i];
        }

		lhslib::rank(e, d);

		int expected2[5] = {4, 1, 1, 3, 0};
		for (int i = 0; i < 5; i++)
        {
			bclib::Assert(d[i] == expected2[i], "failed 5");
        }
	}

	void utilityLHSTest::testRankColumns()
	{
		std::vector<double> a = std::vector<double>(10);
		double b[10] = {.1, .4, .2, .3, .5, .11, .12, .15, .14, .13};
		for (int i = 0; i < 10; i++)
        {
			a[i] = b[i];
        }

		std::vector<int> d = std::vector<int>(10);
        lhslib::rankColumns(a, d, 5);

		int expected[10] = {0, 2, 3, 1, 4, 0, 1, 4, 3, 2};
		for (int i = 0; i < 10; i++)
        {
			bclib::Assert(d[i] == expected[i], "failed 6");
        }
	}

	void utilityLHSTest::testLhsPrint()
	{
	}

	void utilityLHSTest::testSumInvDistance()
	{
        double a[9] = {1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 4.0, 4.0, 4.0};
        bclib::matrix<double> A = bclib::matrix<double>(3, 3, a);
        double expectedSum = 1.0/sqrt(3.0)+1.0/sqrt(12.0)+1.0/sqrt(27.0);
        
        double test = lhslib::sumInvDistance(A);
        bclib::AssertEqualsLRE(expectedSum, test, 6, "failed in testSumInvDistance");
	}
}
