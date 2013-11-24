/* 
 * File:   utilityLHS.h
 * Author: carnellr
 *
 * Created on November 22, 2013, 4:32 PM
 */

#ifndef UTILITYLHS_H
#define	UTILITYLHS_H

#include "CommonDefines.h"

namespace lhslib
{
	int lhsCheck(int n, int k, oacpp::matrix<int> & result, int bTranspose);
	void rank(std::vector<double> & toRank, std::vector<int> & ranks);
	void rankColumns(std::vector<double> & toRank, std::vector<int> & ranks, int nrow);

	template <class T>
	void lhsPrint(int n, int k, const oacpp::matrix<T> & result, int bTranspose)
	{
		if (bTranspose == 0)
		{
			for (size_t irow = 0; irow < static_cast<size_t>(k); irow++)
			{
				for (size_t jcol = 0; jcol < static_cast<size_t>(n); jcol++)
				{
					PRINT_MACRO("%g ", static_cast<double>(result(irow, jcol)));
				}
				PRINT_MACRO("\n");
			}
		}
		else
		{
			for (size_t irow = 0; irow < static_cast<size_t>(n); irow++)
			{
				for (size_t jcol = 0; jcol < static_cast<size_t>(k); jcol++)
				{
					PRINT_MACRO("%d ", result(irow, jcol));
				}
				PRINT_MACRO("\n");
			}
		}
	}

	template <class T>
	double sumInvDistance(const oacpp::matrix<T> & A)
	{ 
        size_t nr = A.rowsize();
        size_t nc = A.colsize();
		T oneDistance;
        T diff;
		double totalInvDistance = 0.0;
		/* iterate the row of the first point from 0 to N-2 */
		for (size_t irow = 0; irow < nr - 1; irow++)
		{
			/* iterate the row the second point from i+1 to N-1 */
			for (size_t jrow = (irow + 1); jrow < nr; jrow++)
			{
				oneDistance = static_cast<T>(0);
				/* iterate through the columns, summing the squared differences */
				for (size_t kcol = 0; kcol < nc; kcol++)
				{
					/* calculate the square of the difference in one dimension between the
					* points */
                    diff = A(irow,kcol) - A(jrow,kcol);
					oneDistance += diff * diff;
				}
				/* sum the inverse distances */
				totalInvDistance += (1.0 / std::sqrt(static_cast<double>(oneDistance)));
			}
		}
		return totalInvDistance;
	}

	template <class T>
	double sumInvDistance(const std::vector<T> & B, size_t nr, size_t nc)
	{
        oacpp::matrix<T> A(nr, nc, B);
        return sumInvDistance(A);
	}
} // end namespace


#endif	/* UTILITYLHS_H */

