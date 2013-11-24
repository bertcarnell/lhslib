/*
 *
 * utilityLHS_R.cpp: A C++ routine of utilities used in the LHS package
 * Copyright (C) 2012  Robert Carnell
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include "CommonDefines.h"
#include "utilityLHS.h"

namespace lhslib
{
    // TODO:  bTranspose should be a bool
    int lhsCheck(int n, int k, const oacpp::matrix<int> & result, int bTranspose)
    {
        int total = 0;
        /*
        * verify that the result is a latin hypercube.  One easy check is to ensure
        * that the sum of the rows is the sum of the 1st N integers.  This check can
        * be fooled in one unlikely way...
        * if a column should be 1 2 3 4 6 8 5 7 9 10
        * the sum would be 10*11/2 = 55
        * the same sum could come from 5 5 5 5 5 5 5 5 5 10
        * but this is unlikely
        */
        if (bTranspose == 0)
        {
            for (int irow = 0; irow < k; irow++)
            {
                total = 0;
                for (int jcol = 0; jcol < n; jcol++)
                {
                    total += result(irow, jcol);
                }
                if (total != n * (n + 1) / 2)
                {
                    return 0;
                }
            }
        }
        else
        {
            for (int jcol = 0; jcol < k; jcol++)
            {
                total = 0;
                for (int irow = 0; irow < n; irow++)
                {
                    total += result(irow, jcol);
                }
                if (total != n * (n + 1) / 2)
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    void rank(std::vector<double> & toRank, std::vector<int> & ranks)
    {
        size_t len = toRank.size();
        if (toRank.size() != ranks.size())
        {
            ranks.resize(len, 0);
        }
        for (size_t i = 0; i < len; i++)
        {
            ranks[i] = 0;
            for (size_t j = 0; j < len; j++)
            {
                if (toRank[i] < toRank[j])
                {
                    ranks[i]++;
                }
            }
        }
    }

    void rankColumns(std::vector<double> & toRank, std::vector<int> & ranks, int nrow)
    {
        size_t n = static_cast<size_t>(nrow);
        std::vector<double> column = std::vector<double>(n);
        size_t len = toRank.size();
        int offset;
        if (toRank.size() != ranks.size())
        {
            ranks.resize(len, 0);
        }
        for (size_t i = 0; i < len; i+=n)
        {
            // copy the first nrow
            for (size_t j = 0; j < n; j++)
            {
                column[j] = toRank[i+j];
            }
            // sort
            std::sort(column.begin(), column.end(), std::less<double>());
            // find the sorted number that is the same as the number to rank
            for (size_t j = 0; j < n; j++)
            {
                offset = static_cast<int>(i);
                ranks[i+j] = std::find(toRank.begin()+offset, toRank.begin()+offset+nrow, column[j]) - (toRank.begin()+offset);
            }
        }
    }

} // end namespace
