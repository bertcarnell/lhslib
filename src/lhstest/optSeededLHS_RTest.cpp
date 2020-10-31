/**
 * @file optSeededLHS_RTest.cpp
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

#include "optSeededLHS_RTest.h"

namespace lhsTest{
	void optSeededLHS_RTest::Run()
	{
		printf("\toptSeededLHS_RTest...");
		testOptSeededLHS_R();
		testStress();
		printf("passed\n");
	}

	void optSeededLHS_RTest::testOptSeededLHS_R()
	{
		// start with input since it normally goes through the augment function
		double pOld[27] = {0.17522671, 0.07879704, 0.17583135, 0.91942996, 0.60287303, 0.87979332, 0.49834531,
			0.83027432, 0.60226876, 0.64048859, 0.40853803, 0.32700602, 0.83442996, 0.90739188,
			0.96706112, 0.35671102, 0.24239675, 0.37670171, 0.23648741, 0.48285498, 0.06292809,
			0.10114126, 0.20412818, 0.49293670, 0.73194844, 0.72583449, 0.68952544};
		int n = 9;
		int k = 3;
		int maxSweeps = 2;
		double eps = 0.1;
        bclib::matrix<double> mOld = bclib::matrix<double>(n, k, pOld);
		int jLen = 9 * 8 / 2 + 1; // 9 choose 2 + 1

        lhslib::optSeededLHS(n, k, maxSweeps, eps, mOld, jLen, false);
        
        bclib::matrix<int> result = bclib::matrix<int>(n, k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                result(i, j) = static_cast<int>(std::floor(9.0*mOld(i,j)) + 1.0);
            }
        }
		int expected[27] = {7,1,3,
                            9,7,6,
                            5,8,8,
                            8,4,2,
                            6,3,9,
                            4,9,4,
                            3,5,1,
                            1,2,5,
                            2,6,7};
        bclib::matrix<int> expectedMat = bclib::matrix<int>(9, 3, expected);
        
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				bclib::Assert(expected[i*k+j] == result(i, j), "Failed 1");
			}
		}
		
		ASSERT_THROW(lhslib::optSeededLHS(-1, k, maxSweeps, eps, mOld, jLen, false));
		ASSERT_THROW(lhslib::optSeededLHS(n, -5, maxSweeps, eps, mOld, jLen, false));
		ASSERT_THROW(lhslib::optSeededLHS(n, k, 0, eps, mOld, jLen, false));
		ASSERT_THROW(lhslib::optSeededLHS(n, k, maxSweeps, 0, mOld, jLen, false));

		// trying to get the algorithm to stop when the change is less than eps
        lhslib::optSeededLHS(n, k, maxSweeps, 1.0E-6, mOld, jLen, false);
	}


/*
require(lhs)

RNGkind("Marsaglia-Multicarry")
RNGkind()
.Random.seed

optSeededLHS <- function (seed, m = 1, maxSweeps = 2, eps = 0.1) 
{
  if (is.matrix(seed) == FALSE) 
    stop("Input seed Design must be in the Matrix class\n")
  if (length(m) != 1 | length(maxSweeps) != 1 | length(eps) != 
    1) 
    stop("m, eps, and maxSweeps may not be vectors")
  if (any(is.na(c(m, maxSweeps, eps)))) 
    stop("m, eps, and maxSweeps may not be NA or NaN")
  if (any(is.infinite(c(m, eps, maxSweeps)))) 
    stop("m, eps, and maxSweeps may not be infinite")
  if (eps >= 1 | eps <= 0) 
    stop("eps must fall in the interval (0,1)\n")
  if (floor(maxSweeps) != maxSweeps | maxSweeps < 1) 
    stop("maxSweeps must be a positive integer\n")
  if (floor(m) != m | m < 1) 
    stop("m must be a positive integer\n")
  if (try(is.function(augmentLHS), silent = TRUE) != TRUE) 
    stop("The augmentLHS.R function must be sourced\n")
  if (any(is.na(seed) == TRUE)) 
    stop("Input Design cannot contain any NA entries\n")
  if (max(seed) > 1 | min(seed) < 0) 
    stop("The seed design must be uniformly distributed on [0,1]\n")
  k <- ncol(seed)
  N <- m + nrow(seed)
  Pold <- augmentLHS(seed, m)
  if (m == 1) 
    return(Pold)
  Pold <- c(t(Pold))
  jLen <- choose(N, 2) + 1
  J1 <- numeric(jLen)
  J2 <- numeric(jLen)
  J3 <- numeric(jLen)
  Pnew <- numeric(N * k)
  print(Pold)
  resultList <- .C("optSeededLHS_C", as.integer(N), as.integer(k), 
                   as.integer(maxSweeps), as.double(eps), as.double(Pold), 
                   as.double(J1), as.integer(J2), as.integer(J3), as.integer(jLen), 
                   as.double(Pnew))
  result <- resultList[[5]]
  return(matrix(result, nrow = N, ncol = k, byrow = TRUE))
}

.Random.seed <- as.integer(c(401, 1976, 1968))
.Random.seed
lhsseed <- improvedLHS(4, 3, 5)
floor((4+5)*optSeededLHS(lhsseed, 5, 2, 0.1))+1
.Random.seed
*/
	void optSeededLHS_RTest::testStress()
	{
		int n = 9;
		int k = 3;
        bclib::matrix<double> mOld = bclib::matrix<double>(n,k);
		int maxSweeps = 2;
		double eps = 0.1;
		int jLen = 9 * 8 / 2 + 1; // 9 choose 2 + 1

		for (int i = 0; i < 50; i++)
        {
            lhslib::optSeededLHS(n, k, maxSweeps, eps, mOld, jLen, false);
        }
	}
}
