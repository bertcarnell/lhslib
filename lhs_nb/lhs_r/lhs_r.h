/**
 * @file lhs_r.h
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

#ifndef LHS_R_H
#define	LHS_R_H

#include <Rcpp.h>
#include "CommonDefines.h"
#include "matrix.h"
#include "CRandom.h"

RcppExport SEXP /*int matrix*/ improvedLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ dup);
RcppExport SEXP /*int matrix*/ maximinLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ dup);
RcppExport SEXP /*int matrix*/ optimumLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ maxsweeps, SEXP /*double*/ eps, SEXP /*int**/ pOld,
        SEXP /*int*/ jLen, SEXP /*int*/ bVerbose);
RcppExport SEXP /*int matrix*/ optSeededLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ maxsweeps, SEXP /*double*/ eps, SEXP /*int**/ pOld,
        SEXP /*int*/ jLen, SEXP /*int*/ bVerbose);

/**
 * Comparison operator to use in the findranks method
 * @param first the first pair of arguments (value, rank)
 * @param second the second pair of arguments (value, rank)
 * @return true if the value in the first argument is less than the value in the second argument
 */
template <class T>
bool findranksCompare(const std::pair<T, int> first, const std::pair<T, int> second)
{
    return (first.first < second.first);
}

/**
 * Find the order of each vector element (zero based)
 * @tparam T numeric argument that can be ordered
 * @param v the vector to be ranked
 * @param indx the ranks of the elements
 */
template <class T>
void findorder_zero(const std::vector<T> & v, std::vector<int> & order)
{
    // create a vector of pairs to hold the value and the integer rank
    std::vector<std::pair<T, int> > p(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        p[i] = std::pair<T, int>(v[i], static_cast<int>(i));
    }

    // if the rank vector is not the right size, resize it (the original values may be lost)
    if (order.size() != v.size())
    {
        order.resize(v.size());
    }

    // sort the pairs of values
    std::sort(p.begin(), p.end(), findranksCompare<double>);

    // take the ranks from the pairs and put them in the rank vector
    for (size_t i = 0; i < v.size(); i++)
    {
        order[i] = p[i].second;
    }
}

void findorder_zero(const Rcpp::NumericVector & v, Rcpp::IntegerVector & order)
{
    std::vector<double> vlocal = Rcpp::as<std::vector<double> >(v);
    std::vector<int> orderlocal(v.size());
    findorder_zero(vlocal, orderlocal);
    order = Rcpp::IntegerVector::import(orderlocal.begin(), orderlocal.end());
    // TODO: could we have done orderlocal = Rcpp::as<std::vector<int> >(order); ??
}

Rcpp::NumericMatrix convertIntegerToNumericLhs(const bclib::matrix<int> & intMat)
{
    bclib::matrix<int>::size_type n = intMat.rowsize();
    bclib::matrix<int>::size_type k = intMat.colsize();
    Rcpp::NumericMatrix result(n, k);
    Rcpp::NumericVector eps = Rcpp::runif(static_cast<int>(n*k));
    unsigned int counter = 0;
    // I think this is right (iterate over rows within columns
    for (bclib::matrix<int>::size_type col = 0; col < k; col++)
    {
        for (bclib::matrix<int>::size_type row = 0; row < n; row++)
        {
            result(row, col) = static_cast<double>(intMat(row, col) - 1) + eps[counter];
            result(row, col) /= static_cast<double>(n);
            counter++;
        }
    }
    
    return result;
}

class RStandardUniform : public lhslib::CRandom<double>
{
public:
    double getNextRandom() {return Rcpp::as<double>(Rcpp::runif(1));};
};

#endif	/* LHS_R_H */
