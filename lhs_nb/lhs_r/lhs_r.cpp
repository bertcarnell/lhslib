/**
 * @file lhs_r.cpp
 * @author Robert Carnell
 * @copyright Copyright (c) 2013, Robert Carnell
 * 
 * @license <a href="http://www.gnu.org/licenses/gpl.html">GNU General Public License (GPL v3)</a>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "lhs_r.h"

RcppExport SEXP /*int matrix*/ improvedLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ dup)
{
    int nlocal = Rcpp::as<int>(n);
    int klocal = Rcpp::as<int>(k);
    int duplocal = Rcpp::as<int>(dup);
    
    Rcpp::IntegerVector result(nlocal*duplocal,klocal*duplocal);
    return result;
}
RcppExport SEXP /*int matrix*/ maximinLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ dup)
{
    Rcpp::IntegerVector result(10,20);
    return result;
    
}
RcppExport SEXP /*int matrix*/ optimumLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ maxsweeps, SEXP /*double*/ eps, SEXP /*int**/ pOld,
        SEXP /*int*/ jLen, SEXP /*int*/ bVerbose)
{
    Rcpp::IntegerVector result(10,20);
    return result;
   
}
RcppExport SEXP /*int matrix*/ optSeededLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ maxsweeps, SEXP /*double*/ eps, SEXP /*int**/ pOld,
        SEXP /*int*/ jLen, SEXP /*int*/ bVerbose)
{
    Rcpp::IntegerVector result(10,20);
    return result;
    
}

/**
 * @todo make sure that if n or k are passed as vectors or as doubles that an error is thrown
 * @todo what if n or k are na or nan or infinite?
 * @todo what if preserveDraw is not true or false?
 * @todo what if n or k are negative?
 * @todo check that the random numbers are the same as R for the R tests
 * @param n
 * @param k
 * @param preserveDraw
 * @return 
 */
RcppExport SEXP randomLHS_cpp(SEXP n, SEXP k, SEXP preserveDraw)
{
    // note: there doesn't seem to be a Rcpp::as<size_t>
    size_t nlocal = static_cast<size_t>(Rcpp::as<int>(n));
    size_t klocal = static_cast<size_t>(Rcpp::as<int>(k));
    bool bPreserveDraw = Rcpp::as<bool>(preserveDraw);
    
    Rcpp::NumericMatrix result(nlocal, klocal);
    Rcpp::NumericVector randomunif1;
    Rcpp::NumericVector randomunif2;
    Rcpp::IntegerVector orderVector(n);
    
    if (bPreserveDraw)
    {
        for (size_t jcol = 0; jcol < klocal; jcol++)
        {
            randomunif1 = Rcpp::runif(static_cast<int>(nlocal));
            randomunif2 = Rcpp::runif(static_cast<int>(nlocal));
            findorder_zero(randomunif1, orderVector);
            for (size_t irow = 0; irow < nlocal; irow++)
            {
                result(irow,jcol) = orderVector[irow] + randomunif2[irow];
                result(irow,jcol) /= static_cast<double>(nlocal);
            }
        }
    }
    else
    {
        for (size_t jcol = 0; jcol < klocal; jcol++)
        {
            randomunif1 = Rcpp::runif(static_cast<int>(nlocal));
            findorder_zero(randomunif1, orderVector);
            for (size_t irow = 0; irow < nlocal; irow++)
            {
                result(irow,jcol) = orderVector[irow];
            }
        }
        randomunif2 = Rcpp::runif(nlocal*klocal);
        Rcpp::NumericMatrix randomMatrix(nlocal, klocal, randomunif2.begin());
        for (size_t jcol = 0; jcol < klocal; jcol++)
        {
            for (size_t irow = 0; irow < nlocal; irow++)
            {
                result(irow,jcol) += randomMatrix(irow,jcol);
                result(irow,jcol) /= static_cast<double>(nlocal);
            }
        }
    }
    return result;
}

