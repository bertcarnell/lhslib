#include "improvedLHS_RTest.h"

namespace lhsTest{
	void improvedLHS_RTest::Run()
	{
		printf("\timprovedLHS_RTest...");
        testImprovedLHS_R(); // TODO: Not passing
		testStress(); // TODO:  Not passing
		printf("passed\n");
	}

	void improvedLHS_RTest::testImprovedLHS_R()
	{
		int n = 4;
		int k = 3;
		int dup = 5;
        bclib::matrix<int> result = bclib::matrix<int>(n,k);

        lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);
        lhslib::improvedLHS(n, k, dup, result, oRandom);
		
		//int expected[12] = {1,4,2,3,
        //                    3,1,4,2,
        //                    3,4,1,2};
		int expected[12] = {1,3,3,
                            4,1,4,
                            2,4,1,
                            3,2,2};
		for (size_t i = 0; i < static_cast<size_t>(n*k); i++)
		{
            bclib::Assert(expected[i], result.getDataVector()[i], "Failed 1");
		}

        unsigned int a, b;
        oRandom.setSeed(1976, 1968);
        double temp = oRandom.getNextRandom();
        oRandom.getSeed(&a, &b);
		bclib::AssertEqualsLRE(temp, 0.66590160146958687903, 12, "failed RNG test");
		bclib::Assert(a == 73050744 && b == 35424000, "failed RNG test2");
        
        oRandom.setSeed(1976, 1968);
        lhslib::improvedLHS(n, k, dup, result, oRandom);
        oRandom.getSeed(&a, &b);
		bclib::Assert(a == 1399152289 && b == 766747565, "failed RNG test3");
	}

/*
require(lhs)

RNGkind("Marsaglia-Multicarry")
RNGkind()
.Random.seed

.Random.seed <- as.integer(c(401, 1976, 1968))
.Random.seed
floor(4*improvedLHS(4,3,5))+1
.Random.seed

.Random.seed <- as.integer(c(401, 1976, 1968))
.Random.seed
print(runif(1), 20)
.Random.seed
*/

	void improvedLHS_RTest::testStress()
	{
		int n = 4;
		int k = 3;
		int DUP = 5;
        bclib::matrix<int> result = bclib::matrix<int>(n, k);

        lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
        oRandom.setSeed(1976, 1968);
		for (int i = 0; i < 10000; i++)
        {
			lhslib::improvedLHS(n, k, DUP, result, oRandom);
        }
	}
}