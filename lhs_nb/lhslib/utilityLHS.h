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
	bool isValidLHS(const bclib::matrix<int> & result, bool bTranspose);
	void rank(std::vector<double> & toRank, std::vector<int> & ranks);
	void rankColumns(std::vector<double> & toRank, std::vector<int> & ranks, int nrow);
    void initializeAvailableMatrix(bclib::matrix<int> & avail);

	template <class T>
	void lhsPrint(const bclib::matrix<T> & result, int bTranspose)
	{
        msize_type k = result.colsize();
        msize_type n = result.rowsize();
		if (bTranspose == 0)
		{
			for (msize_type irow = 0; irow < k; irow++)
			{
				for (msize_type jcol = 0; jcol < n; jcol++)
				{
					PRINT_MACRO("%g ", static_cast<double>(result(irow, jcol)));
				}
				PRINT_MACRO("\n");
			}
		}
		else
		{
			for (msize_type irow = 0; irow < n; irow++)
			{
				for (msize_type jcol = 0; jcol < k; jcol++)
				{
					PRINT_MACRO("%g ", static_cast<double>(result(irow, jcol)));
				}
				PRINT_MACRO("\n");
			}
		}
	}

	template <class T>
	double sumInvDistance(const bclib::matrix<T> & A)
	{ 
        msize_type nr = A.rowsize();
        msize_type nc = A.colsize();
		T oneDistance;
        T diff;
		double totalInvDistance = 0.0;
		/* iterate the row of the first point from 0 to N-2 */
		for (msize_type irow = 0; irow < nr - 1; irow++)
		{
			/* iterate the row the second point from i+1 to N-1 */
			for (msize_type jrow = (irow + 1); jrow < nr; jrow++)
			{
				oneDistance = static_cast<T>(0);
				/* iterate through the columns, summing the squared differences */
				for (msize_type kcol = 0; kcol < nc; kcol++)
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
    void copyMatrix(bclib::matrix<T> & copyTo, const bclib::matrix<T> & copyFrom)
    {
        if (copyFrom.rowsize() != copyTo.rowsize() ||
                copyFrom.colsize() != copyTo.colsize())
        {
            throw std::runtime_error("Matrices are not compatible for a copy");
        }
        for (msize_type row = 0; row < copyFrom.rowsize(); row++)
        {
            for (unsigned int col = 0; col < copyFrom.colsize(); col++)
            {
                copyTo(row, col) = copyFrom(row, col);
            }
        }
    }
} // end namespace

#endif	/* UTILITYLHS_H */

