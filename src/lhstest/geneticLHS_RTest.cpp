/**
 * @file geneticLHS_RTest.cpp
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

#include "geneticLHS_RTest.h"

namespace lhsTest{
	void geneticLHS_RTest::Run()
	{
		printf("\tgeneticLHS_RTest...");
        testGeneticLHS_R();
        testStress();
		printf("passed\n");
	}

	void geneticLHS_RTest::testGeneticLHS_R()
	{
        int n = 10;
        int k = 4;
        int pop = 20;
        int gen = 5;
        double pMut = 0.10;
        std::string crit = "S";
        bool verbose = false;
        bclib::matrix<double> result = bclib::matrix<double>(n, k);
        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);
        
        lhslib::geneticLHS(n, k, pop, gen, pMut, crit, verbose, result, oRandom);
        bclib::Assert(lhslib::isValidLHS(result), "geneticLHS validity S");
        
        lhslib::geneticLHS(n, k, pop, gen, pMut, "Maximin", verbose, result, oRandom);
        bclib::Assert(lhslib::isValidLHS(result), "geneticLHS validity maximin");

        int neg = -1;
        ASSERT_THROW(lhslib::geneticLHS(neg, k, pop, gen, pMut, crit, verbose, result, oRandom));
        ASSERT_THROW(lhslib::geneticLHS(n, neg, pop, gen, pMut, crit, verbose, result, oRandom));
        bclib::matrix<double> temp = bclib::matrix<double>(1,1);
        ASSERT_THROW(lhslib::geneticLHS(n, k, pop, gen, pMut, crit, verbose, temp, oRandom));
        ASSERT_THROW(lhslib::geneticLHS(n, k, neg, gen, pMut, crit, verbose, result, oRandom));
        ASSERT_THROW(lhslib::geneticLHS(n, k, pop, neg, pMut, crit, verbose, result, oRandom));
        ASSERT_THROW(lhslib::geneticLHS(n, k, 3, gen, pMut, crit, verbose, result, oRandom));
        double dneg = -0.1;
        double high = 1.2;
        ASSERT_THROW(lhslib::geneticLHS(n, k, pop, gen, dneg, crit, verbose, result, oRandom));
        ASSERT_THROW(lhslib::geneticLHS(n, k, pop, gen, high, crit, verbose, result, oRandom));
        ASSERT_THROW(lhslib::geneticLHS(n, k, pop, gen, pMut, "wrong", verbose, result, oRandom));
         
    }
    
    void geneticLHS_RTest::testStress()
    {
        int n = 5;
        int k = 3;
        int pop = 10;
        int gen = 5;
        double pMut = 0.05;
        bclib::matrix<double> result = bclib::matrix<double>(n, k);
        bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);

        bool test;
        for (int i = 0; i < 50; i++)
        {
            lhslib::geneticLHS(n, k, pop, gen, pMut, "S", false, result, oRandom);
            
            test = lhslib::isValidLHS(result);
            if (!test)
            {
                std::cout << "\n" << result.toString() << "\n";
            }
            bclib::Assert(test, "geneticLHS validity S");

            lhslib::geneticLHS(n, k, pop, gen, pMut, "Maximin", false, result, oRandom);
            test = lhslib::isValidLHS(result);
            if (!test)
            {
                std::cout << "\n" << result.toString() << "\n";
            }
            bclib::Assert(test, "geneticLHS validity maximin");
        }
    }
} // end namespace
