/* 
 * File:   CommonDefines.h
 * Author: carnellr
 *
 * Created on November 22, 2013, 4:27 PM
 */

#ifndef COMMONDEFINES_H
#define	COMMONDEFINES_H

#include <cstdlib>
#include <cmath>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <cfloat>
#include <climits>
#include <cstdio>
#include "matrix.h"
#include "CRandom.h"

#ifdef RCOMPILE
#define PRINT_MACRO Rprintf
#define ERROR_MACRO Rprintf
#else // RCOMPILE
#define PRINT_MACRO printf
#define ERROR_MACRO printf
#endif // RCOMPILE

#define PRINT_RESULT 0

/* include after PRINT_MACRO is defined */
#include "utilityLHS.h"

namespace lhslib 
{
    void improvedLHS(int n, int k, int dup, std::vector<int> & result);
    //void maximinLHS_C(int* N, int* K, int* DUP, int* result);
    //void optimumLHS_C(int* N, int* K, int* MAXSWEEPS, double* EPS, int* pOld, int* JLen, int* bVerbose);
    //void optSeededLHS_C(int* N, int* K, int* MAXSWEEPS, double* EPS, double* pOld, int* JLen, int* bVerbose);

    void set_seed(unsigned int i1, unsigned int i2);
    void get_seed(unsigned int *i1, unsigned int *i2);
    double unif_rand(void);
}

#endif	/* COMMONDEFINES_H */

