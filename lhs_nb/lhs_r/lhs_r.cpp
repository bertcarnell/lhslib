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

RcppExport SEXP /*double matrix*/ improvedLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ dup)
{
    try
    {
        Rcpp::RNGScope tempRNG;

        int m_n = Rcpp::as<int>(n);
        int m_k = Rcpp::as<int>(k);
        int m_dup = Rcpp::as<int>(dup);

        bclib::matrix<int> intMat = bclib::matrix<int>(m_n, m_k);
        RStandardUniform oRStandardUniform = RStandardUniform();
        lhslib::improvedLHS(m_n, m_k, m_dup, intMat, oRStandardUniform);
        Rcpp::NumericMatrix result = lhs_r::convertIntegerToNumericLhs(intMat);

        return result;
    }
    catch (Rcpp::not_compatible & nc)
    {
        std::stringstream message;
        message << nc.what() << "\n" << "Error is likely caused by an input vector where a single value is required.";
        ::Rf_error(message.str().c_str());
    }
    catch (std::exception & e)
    {
        ::forward_exception_to_r(e);
    }
    catch (...)
    {
        ::Rf_error("Unrecognized exception");
    }
    return ::R_NilValue;
}

RcppExport SEXP /*int matrix*/ maximinLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ dup)
{
    try
    {
        Rcpp::RNGScope tempRNG;

        int nlocal = Rcpp::as<int>(n);
        int klocal = Rcpp::as<int>(k);
        int duplocal = Rcpp::as<int>(dup);

        bclib::matrix<int> intMat = bclib::matrix<int>(nlocal, klocal);
        RStandardUniform oRStandardUniform = RStandardUniform();
        lhslib::maximinLHS(nlocal, klocal, duplocal, intMat, oRStandardUniform);
        Rcpp::NumericMatrix result = lhs_r::convertIntegerToNumericLhs(intMat);

        return result;
    }
    catch (Rcpp::not_compatible & nc)
    {
        std::stringstream message;
        message << nc.what() << "\n" << "Error is likely caused by an input vector where a single value is required.";
        ::Rf_error(message.str().c_str());
    }
    catch (std::exception & e)
    {
        ::forward_exception_to_r(e);
    }
    catch (...)
    {
        ::Rf_error("Unrecognized exception");
    }
    return ::R_NilValue;
}

// TODO:  add try block
RcppExport SEXP /*int matrix*/ optimumLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ maxsweeps, SEXP /*double*/ eps, SEXP /*int*/ bVerbose)
{
    // TODO:  check for na in n, k, maxsweeps, eps
    // TODO:  check for infinite n, k, maxsweeps, eps
    try
    {
        int m_n = Rcpp::as<int>(n);
        int m_k = Rcpp::as<int>(k);
        int m_maxsweeps = Rcpp::as<int>(maxsweeps);
        double m_eps = Rcpp::as<double>(eps);
        bool m_bVerbose = Rcpp::as<bool>(bVerbose);

        if (m_eps >= 1 || m_eps <= 0)
        {
            Rcpp::exception("eps must fall in the interval (0,1)\n");
        }
        if (m_n < 1 || m_k < 1 || m_maxsweeps < 1)
        {
            Rcpp::exception("n, k, and maxsweeps must be positive integers");
        }

        Rcpp::RNGScope tempRNG;
        RStandardUniform oRStandardUniform = RStandardUniform();
        int jLen = static_cast<int>(::Rf_choose(static_cast<double>(m_n), 2.0) + 1.0);
        bclib::matrix<int> intMat = bclib::matrix<int>(m_n, m_k);

        lhslib::optimumLHS(m_n, m_k, m_maxsweeps, m_eps, intMat,
                jLen, oRStandardUniform, m_bVerbose);

        Rcpp::NumericMatrix result = lhs_r::convertIntegerToNumericLhs(intMat);

        return result;
    }
    catch (Rcpp::not_compatible & nc)
    {
        std::stringstream message;
        message << nc.what() << "\n" << "Error is likely caused by an input vector where a single value is required.";
        ::Rf_error(message.str().c_str());
    }
    catch (std::exception & e)
    {
        ::forward_exception_to_r(e);
    }
    catch (...)
    {
        ::Rf_error("Unrecognized exception");
    }
    return ::R_NilValue;
}

RcppExport SEXP /*int matrix*/ optSeededLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, 
        SEXP /*int*/ maxsweeps, SEXP /*double*/ eps, SEXP /*int**/ inlhs,
        SEXP /*int*/ bVerbose)
{
    // TODO:  check for na in n, k, maxsweeps, eps
    // TODO:  check for infinite n, k, maxsweeps, eps
    try
    {
        int m_n = Rcpp::as<int>(n);
        int m_k = Rcpp::as<int>(k);
        int m_maxsweeps = Rcpp::as<int>(maxsweeps);
        double m_eps = Rcpp::as<double>(eps);
        bool m_bVerbose = Rcpp::as<bool>(bVerbose);

        if (m_eps >= 1 || m_eps <= 0)
        {
            Rcpp::exception("eps must fall in the interval (0,1)\n");
        }
        if (m_n < 1 || m_k < 1 || m_maxsweeps < 1)
        {
            Rcpp::exception("n, k, and maxsweeps must be positive integers");
        }

        int jLen = static_cast<int>(::Rf_choose(static_cast<double>(m_n), 2.0) + 1.0);
        Rcpp::NumericMatrix m_inlhs(inlhs);
        std::vector<double> mv_inlhs = Rcpp::as<std::vector<double> >(m_inlhs);
        bclib::matrix<double> mm_inlhs = bclib::matrix<double>(m_n, m_k, mv_inlhs);

        lhslib::optSeededLHS(m_n, m_k, m_maxsweeps, m_eps, mm_inlhs,
                jLen, m_bVerbose);

        Rcpp::NumericMatrix result = lhs_r::convertMatrixToNumericLhs(mm_inlhs);

        return result;
    }
    catch (Rcpp::not_compatible & nc)
    {
        std::stringstream message;
        message << nc.what() << "\n" << "Error is likely caused by an input vector where a single value is required.";
        ::Rf_error(message.str().c_str());
    }
    catch (std::exception & e)
    {
        ::forward_exception_to_r(e);
    }
    catch (...)
    {
        ::Rf_error("Unrecognized exception");
    }
    return ::R_NilValue;
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
    try
    {
        Rcpp::RNGScope tempRNG;
        
        int nlocal = Rcpp::as<int>(n);
        int klocal = Rcpp::as<int>(k);
        bool bPreserveDraw = Rcpp::as<bool>(preserveDraw);

        Rcpp::NumericMatrix result(nlocal, klocal);
        Rcpp::NumericVector randomunif1(nlocal);
        Rcpp::NumericVector randomunif2(nlocal);
        Rcpp::IntegerVector orderVector(n);

        if (bPreserveDraw)
        {
            for (int jcol = 0; jcol < klocal; jcol++)
            {
                randomunif1 = Rcpp::runif(nlocal);
                randomunif2 = Rcpp::runif(nlocal);
                lhs_r::findorder_zero(randomunif1, orderVector);
                for (int irow = 0; irow < nlocal; irow++)
                {
                    result(irow,jcol) = orderVector[irow] + randomunif2[irow];
                    result(irow,jcol) /= static_cast<double>(nlocal);
                }
            }
        }
        else
        {
            for (int jcol = 0; jcol < klocal; jcol++)
            {
                randomunif1 = Rcpp::runif(nlocal);
                lhs_r::findorder_zero(randomunif1, orderVector);
                for (int irow = 0; irow < nlocal; irow++)
                {
                    result(irow,jcol) = orderVector[irow];
                }
            }
            randomunif2 = Rcpp::runif(nlocal*klocal);
            Rcpp::NumericMatrix randomMatrix(nlocal, klocal, randomunif2.begin());
            for (int jcol = 0; jcol < klocal; jcol++)
            {
                for (int irow = 0; irow < nlocal; irow++)
                {
                    result(irow,jcol) += randomMatrix(irow,jcol);
                    result(irow,jcol) /= static_cast<double>(nlocal);
                }
            }
        }
        return result;
    }
    catch (Rcpp::not_compatible & nc)
    {
        std::stringstream message;
        message << nc.what() << "\n" << "Error is likely caused by an input vector where a single value is required.";
        ::Rf_error(message.str().c_str());
    }
    catch (std::exception & e)
    {
        ::forward_exception_to_r(e);
    }
    catch (...)
    {
        ::Rf_error("Unrecognized exception");
    }
    return ::R_NilValue;
}

RcppExport SEXP geneticLHS_cpp(SEXP /*int*/ n, SEXP /*int*/ k, SEXP /*int*/ pop,
        SEXP /*int*/ gen, SEXP /*double*/ pMut, SEXP criterium,
        SEXP /*bool*/ bVerbose)
{
    try
    {
        Rcpp::RNGScope tempRNG;

        int m_n = Rcpp::as<int>(n);
        int m_k = Rcpp::as<int>(k);
        int m_pop = Rcpp::as<int>(pop);
        int m_gen = Rcpp::as<int>(gen);
        double m_pMut = Rcpp::as<double>(pMut);
        std::string m_criterium = Rcpp::as<std::string>(criterium);
        bool m_bVerbose = Rcpp::as<bool>(bVerbose);

        // lengths should be 1 because of the cast
        // TODO:  are NA's stopped?
        // TODO:  are infitities stopped?
        if (m_n < 1 || m_k < 1 || m_pop < 1 || m_gen < 1)
        {
            throw Rcpp::exception("n, k, pop, and gen should be integers greater than 0");
        }
        if (m_pMut <= 0 || m_pMut >= 1)
        {
            throw Rcpp::exception("pMut should be between 0 and 1");
        }
        if (m_pop % 2 != 0)
        {
            throw Rcpp::exception("pop should be an even number");
        }
        if (m_n == 1)
        {
            if (m_bVerbose)
            {
                Rprintf("Design is already optimal");
            }
            Rcpp::NumericMatrix Z(m_n, m_k);
            std::fill(Z.begin(), Z.end(), 1.0);
            return Z;
        }

        std::vector<Rcpp::IntegerMatrix> A = std::vector<Rcpp::IntegerMatrix>(m_pop);
        for (unsigned int i = 0; i < static_cast<unsigned int>(m_pop); i++)
        {
            // Auto fills with zeros
            A[i] = Rcpp::IntegerMatrix(m_n, m_k);
        }

        for (int i = 0; i < m_pop; i++)
        {
            for (int j = 0; j < m_k; j++)
            {
                Rcpp::NumericVector temp = Rcpp::runif(m_n);
                Rcpp::IntegerVector tempord;
                lhs_r::findorder_zero(temp, tempord);
                for (int x = 0; x < m_n; x++)
                {
                    A[i](x, j) = tempord[x];
                }
            }
        }
        Rcpp::NumericVector B;
        std::vector<Rcpp::IntegerMatrix> J;
        for (int v = 0; v < m_gen; v++)
        {
            B <- Rcpp::NumericVector(m_pop);
            for (int i = 0; i < m_pop; i++)
            {
                if (m_criterium == "S")
                {
                    B[i] = lhs_r::calculateSOptimal<INTSXP>(A[i]);
                }
                else if (m_criterium == "Maximin")
                {
                    //B[i] <- min(dist(A[, , i]))
                    Rcpp::NumericMatrix dist = lhs_r::calculateDistance<INTSXP>(A[i]);
                    Rcpp::NumericMatrix::iterator it = std::min_element(dist.begin(), dist.end());
                    B[i] = *it;
                } 
                else 
                {
                    throw Rcpp::exception("Criterium not recognized");
                }
            }
            Rcpp::IntegerVector H(B.size());
            lhs_r::findorder_zero(B, H);
            int posit = std::max_element(B.begin(), B.end()) - B.begin();

            J = std::vector<Rcpp::IntegerMatrix>(m_pop);
            for (std::vector<Rcpp::IntegerMatrix>::iterator i = J.begin(); i != J.end(); ++i)
            {
                *i = Rcpp::IntegerMatrix(m_n, m_k);
            }

            for (unsigned int i = 0; i < static_cast<unsigned int>(m_pop / 2); i++)
            {
                J[i] = A[posit];
            }
            if (m_pop / 2 == 1)
            {
                break;
            }
            for (unsigned int i = 0; i < static_cast<unsigned int>(m_pop / 2); i++)
            {
                J[i + m_pop / 2] = A[H[i]];
            }
        /*for(i in 2:(pop/2)) {
          J[ , runifint(1, 1, k), i] <- J[ , runifint(1, 1, k), (i + pop/2)]
        }*/
            for (unsigned int i = 1; i < static_cast<unsigned int>(m_pop / 2); i++)
            {
                Rcpp::IntegerVector temp1 = lhs_r::runifint(1,0,m_k-1);
                Rcpp::IntegerVector temp2 = lhs_r::runifint(1,0,m_k-1);
                for (unsigned int irow = 0; irow < static_cast<unsigned int>(m_n); irow++)
                {
                    J[i](irow, temp1[0]) = J[i + m_pop / 2](irow,temp2[0]);
                }
            }
        /*for(i in (pop/2+1):pop) {
          J[ , runifint(1, 1, k), i] <- A[ , runifint(1, 1, k), posit]
        }*/
            for (unsigned int i = m_pop / 2; i < static_cast<unsigned int>(m_pop); i++)
            {
                Rcpp::IntegerVector temp1 = lhs_r::runifint(1,0,m_k-1);
                Rcpp::IntegerVector temp2 = lhs_r::runifint(1,0,m_k-1);
                for (unsigned int irow = 0; irow < static_cast<unsigned int>(m_n); irow++)
                {
                    J[i](irow, temp1[0]) = A[posit](irow,temp2[0]);
                }
            }
        /*for(i in 2:pop) {
          y <- runif(k)
          for(j in 1:k) {
            if(y[j] <= pMut) {
              z <- runifint(2, 1, n)
              a <- J[z[1], j, i]
              b <- J[z[2], j, i]
              J[z[1], j, i] <- b
              J[z[2], j, i] <- a
            }
          }
        }*/
            for (unsigned int i = 1; i < static_cast<unsigned int>(m_pop); i++)
            {
                Rcpp::NumericVector y = Rcpp::runif(m_k);
                for (unsigned int j = 0; j < static_cast<unsigned int>(m_k); j++)
                {
                    if (y[j] <= m_pMut)
                    {
                        Rcpp::IntegerVector z = lhs_r::runifint(2, 0, m_n - 1);
                        int a = J[i](z[0], j);
                        int b = J[i](z[1], j);
                        J[i](z[0], j) = b;
                        J[i](z[1], j) = a;
                    }
                }
            }
            A = J;
            if (v != m_gen && m_bVerbose)
            {
                Rprintf("Generation %d completed", v);
            }
        }

        if (m_bVerbose)
        {
            Rprintf("Last generation completed");
        }

        Rcpp::NumericVector eps  = Rcpp::runif(m_n*m_k);
        Rcpp::NumericMatrix result(m_n, m_k);
        unsigned int count = 0;
        for (unsigned int j = 0; j < static_cast<unsigned int>(m_k); j++)
        {
            for (unsigned int i = 0; i < static_cast<unsigned int>(m_n); i++)
            {
                result(i,j) += (J[0](i,j) - 1.0 + eps[count]) / static_cast<double>(m_n);
                count++;
            }
        }

        return result;
    }
    catch (Rcpp::not_compatible & nc)
    {
        std::stringstream message;
        message << nc.what() << "\n" << "Error is likely caused by an input vector where a single value is required.";
        ::Rf_error(message.str().c_str());
    }
    catch (std::exception & e)
    {
        ::forward_exception_to_r(e);
    }
    catch (...)
    {
        ::Rf_error("Unrecognized exception");
    }
    return ::R_NilValue;
}
