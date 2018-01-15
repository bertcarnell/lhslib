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
		testLhsPrint();
		testSumInvDistance();
        testCalculateDistance();
        testCalculateSOptimal();
        testInitializeAvailableMatrix();
        testCopyMatrix();
        testRunif_std();
        testRunifint();
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
		double b[5] = {.1, .4, .2, .3, .5};
		int sizeofb = sizeof(b) / sizeof(b[0]);
		int notsizeofb = 20;
		std::vector<double> a(b, b + sizeofb);

		std::vector<int> d = std::vector<int>(sizeofb);
		lhslib::rank<double>(a, d);

		bclib::Assert(d.size() == a.size(), "Initialize vector error");
		int expected[5] = {4, 1, 3, 2, 0};
		int sizeofexpected = sizeof(expected) / sizeof(expected[0]);
		bclib::Assert(static_cast<int>(d.size()) == sizeofexpected, "Initialize vector error");
		for (int i = 0; i < sizeofexpected; i++)
		{
			bclib::Assert(d[i] == expected[i], "failed 4");
		}
		
		std::vector<int> d2 = std::vector<int>(notsizeofb);
		lhslib::rank<double>(a, d2);
		
		bclib::Assert(d2.size() == a.size(), "Resizing error");
		bclib::Assert(static_cast<int>(d2.size()) == sizeofexpected, "Resizing error2");
		for (int i = 0; i < sizeofexpected; i++)
		{
			bclib::Assert(d2[i] == expected[i], "failed 4");
		}

		double f[5] = {.1, .4, .4, .3, .5};
		int sizeoff = sizeof(f) / sizeof(f[0]);
		std::vector<double> e(f, f+sizeoff);

		lhslib::rank<double>(e, d);

		int expected2[5] = {4, 1, 1, 3, 0};
		int sizeofexpected2 = sizeof(expected2) / sizeof(expected2[0]);
		bclib::Assert(static_cast<int>(d.size()) == sizeofexpected2, "Resizing error");
		for (int i = 0; i < static_cast<int>(sizeof(expected2)); i++)
        {
			bclib::Assert(d[i] == expected2[i], "failed 5");
        }
	}

	void utilityLHSTest::testLhsPrint()
	{
	}
    
    void utilityLHSTest::testInitializeAvailableMatrix()
    {
        bclib::matrix<int> A = bclib::matrix<int>(4,5);
        lhslib::initializeAvailableMatrix(A);
        
        std::vector<int> col;
        for (bclib::matrix<int>::size_type jcol = 0; jcol < A.colsize(); jcol++)
        {
            for (bclib::matrix<int>::size_type irow = 0; irow < A.rowsize(); irow++)
            {
                bclib::Assert(jcol+1, A(irow, jcol));
            }
        }
    }

	void utilityLHSTest::testSumInvDistance()
	{
        double a[9] = {1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 4.0, 4.0, 4.0};
        bclib::matrix<double> A = bclib::matrix<double>(3, 3, a);
        double expectedSum = 1.0/sqrt(3.0)+1.0/sqrt(12.0)+1.0/sqrt(27.0);
        
        double test = lhslib::sumInvDistance<double>(A);
        bclib::AssertEqualsLRE(expectedSum, test, 12, "failed in testSumInvDistance");
        test = lhslib::sumInvDistance_deprecated<double>(A);
        bclib::AssertEqualsLRE(expectedSum, test, 12, "failed in testSumInvDistance");

        int b[9] = {1, 1, 1, 2, 2, 2, 4, 4, 4};
        bclib::matrix<int> B = bclib::matrix<int>(3, 3, b);
        expectedSum = 1.0/sqrt(3.0)+1.0/sqrt(12.0)+1.0/sqrt(27.0);
        
        test = lhslib::sumInvDistance<int>(B);
        bclib::AssertEqualsLRE(expectedSum, test, 12, "failed in testSumInvDistance");
        test = lhslib::sumInvDistance_deprecated<int>(B);
        bclib::AssertEqualsLRE(expectedSum, test, 12, "failed in testSumInvDistance");

        std::vector<int> A1 = {1,2,3,4,5,6,7,8,9};
        bclib::matrix<int> B1 = bclib::matrix<int>(3, 3, A1);
        bclib::matrix<double> B1dist = bclib::matrix<double>(3,3);
        lhslib::calculateDistance<int>(B1, B1dist);
        double expected = 1.0 / sqrt(3*3+3*3+3*3) + 1.0 / sqrt(6*6+6*6+6*6) + 1.0 / sqrt(3*3+3*3+3*3);
        double actual = lhslib::sumInvDistance<int>(B1);
        double actual2 = lhslib::sumInvDistance<int>(B1);
        bclib::AssertEqualsLRE(expected, actual, 12);
        bclib::AssertEqualsLRE(expected, actual2, 12);
        bclib::AssertEqualsLRE(actual, actual2, 12);
	}
    
    void utilityLHSTest::testCalculateDistance()
    {
        // two vectors
        std::vector<int> A = {1, 2, 3, 4, 5, 6};
        std::vector<int> H = {10, 10, 10, 10, 10, 10};
        int dist = lhslib::calculateDistanceSquared<int>(A, H);
        bclib::Assert(81+64+49+36+25+16, dist);
        
        std::vector<int> G = {1, 2, 3};
        ASSERT_THROW(lhslib::calculateDistanceSquared<int>(A, G));
        
        // a matrix
        std::vector<int> Bin = {1,2,3,4,5,6,7,8,9};
        bclib::matrix<int> B = bclib::matrix<int>(3, 3, Bin);
        bclib::matrix<double> Bdist = bclib::matrix<double>(3,3);
        lhslib::calculateDistance<int>(B, Bdist);
        bclib::Assert(0.0, Bdist(0,0), 1E-12);
        bclib::Assert(0.0, Bdist(1,1), 1E-12);
        bclib::Assert(0.0, Bdist(2,2), 1E-12);
        bclib::AssertEqualsLRE(sqrt(3*3+3*3+3*3), Bdist(0,1), 12);
        bclib::AssertEqualsLRE(sqrt(6*6+6*6+6*6), Bdist(0,2), 12);
        bclib::AssertEqualsLRE(sqrt(3*3+3*3+3*3), Bdist(1,2), 12);
		
		// a matrix with resizing
        Bdist = bclib::matrix<double>(20, 6);
        lhslib::calculateDistance<int>(B, Bdist);
		bclib::Assert(Bdist.colsize() == B.colsize());
		bclib::Assert(Bdist.rowsize() == B.rowsize());
        bclib::Assert(0.0, Bdist(0,0), 1E-12);
        bclib::Assert(0.0, Bdist(1,1), 1E-12);
        bclib::Assert(0.0, Bdist(2,2), 1E-12);
        bclib::AssertEqualsLRE(sqrt(3*3+3*3+3*3), Bdist(0,1), 12);
        bclib::AssertEqualsLRE(sqrt(6*6+6*6+6*6), Bdist(0,2), 12);
        bclib::AssertEqualsLRE(sqrt(3*3+3*3+3*3), Bdist(1,2), 12);
    }
    
    void utilityLHSTest::testCalculateSOptimal()
    {
        std::vector<int> A = {1,2,3,4,5,6,7,8,9};
        bclib::matrix<int> B = bclib::matrix<int>(3, 3, A);
        bclib::matrix<double> Bdist = bclib::matrix<double>(3,3);
        lhslib::calculateDistance<int>(B, Bdist);
        double expected = 1.0/(1.0 / sqrt(3*3+3*3+3*3) + 1.0 / sqrt(6*6+6*6+6*6) + 1.0 / sqrt(3*3+3*3+3*3));
        double actual = lhslib::calculateSOptimal<int>(B);
        bclib::AssertEqualsLRE(expected, actual, 12);
    }
    
    void utilityLHSTest::testCopyMatrix()
    {
        std::vector<int> A = {1,2,3,4,5,6,7,8,9,10};
        bclib::matrix<int> B = bclib::matrix<int>(2, 5, A);
        std::vector<int> E = {11,11,11,11,11,11,11,11,11,11};
        bclib::matrix<int> F = bclib::matrix<int>(2, 5, E);
        lhslib::copyMatrix<int>(F, B);
		
		bclib::matrix<int> G = bclib::matrix<int>(8, 8);
		ASSERT_THROW(lhslib::copyMatrix<int>(G, B));
    }
    
    void utilityLHSTest::testRunif_std()
    {
        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1000,2000);
        
        std::vector<double> A = std::vector<double>(10u);
        lhslib::runif_std(10u, A, oRandom);
        
        std::vector<double>::iterator it = std::max_element(A.begin(), A.end());
        bclib::Assert(*it < 1.0);
        it = std::min_element(A.begin(), A.end());
        bclib::Assert(*it > 0.0);
	
	// resizing
	std::vector<double> B = std::vector<double>(100u);
	lhslib::runif_std(500u, B, oRandom);
    }
    
    void utilityLHSTest::testRunifint()
    {
        std::vector<int> A = std::vector<int>(1000u);
        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1100,2100);
        lhslib::runifint<int>(1000u, 3, 9, A, oRandom);
        std::vector<int>::iterator it = std::min_element(A.begin(), A.end());
        bclib::Assert(*it, 3);
        it = std::max_element(A.begin(), A.end());
        bclib::Assert(*it, 9);
        
        lhslib::runifint<int>(1000u, 0, 1, A, oRandom);
        it = std::min_element(A.begin(), A.end());
        bclib::Assert(*it, 0);
        it = std::max_element(A.begin(), A.end());
        bclib::Assert(*it, 1);

        lhslib::runifint<int>(1000u, -10, 10, A, oRandom);
        it = std::min_element(A.begin(), A.end());
        bclib::Assert(*it, -10);
        it = std::max_element(A.begin(), A.end());
        bclib::Assert(*it, 10);
        
        int temp = 0;
        for (int i = 0; i < 100; i++)
        {
            lhslib::runifint<int>(3, 9, &temp, oRandom);
            bclib::Assert(temp >= 3 && temp <= 9);
        }

		// resizing
		std::vector<int> AA = std::vector<int>(10u);
		unsigned int desiredsize = 100u;
        lhslib::runifint<int>(desiredsize, 3, 9, AA, oRandom);
		bclib::Assert(AA.size() == desiredsize);
    }
}
