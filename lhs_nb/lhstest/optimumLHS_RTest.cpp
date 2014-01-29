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

        lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
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
			int jLen = 7; // 4 choose 2 + 1

            lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
            oRandom.setSeed(1976, 1968);

            bclib::matrix<int> result = bclib::matrix<int>(n,k);
			for (int i = 0; i < 10000; i++)
            {
                lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
            }
		}
}