lhslib
======

Latin hypercube sampling code for the lhs pacakge in the statistical software package R (www.r-project.org)

Link to the lhs project page here:  https://bertcarnell.github.io/lhslib/html/index.html

|<sub>Linux & MacOS</sub>|<sub>Windows</sub>|<sub>Code Coverage</sub>|
|:---:|:---:|:---:|
|[![Build Status](https://travis-ci.org/bertcarnell/lhslib.svg?branch=master)](https://travis-ci.org/bertcarnell/lhslib)|[![Build status](https://ci.appveyor.com/api/projects/status/7xd7sohoug7c0d42?svg=true)](https://ci.appveyor.com/project/bertcarnell/lhslib)|[![codecov](https://codecov.io/gh/bertcarnell/lhslib/branch/master/graph/badge.svg)](https://codecov.io/gh/bertcarnell/lhslib)|

### Process

The code is transfered from the github project to the R project by copying the code from the github checkout to the SVN checkout location and then committing to the R-Forge project.  The R-Forge project is maintained because of the continuous build environment that it offers using the latest R tool chain.  The R-Forge library contains all the R code and help files while the github library is focused only on the C++ library.

The code is transferred using the `src\deploylhs.bat` batch script in Windows.

### Connections

- [oa](https://github.com/bertcarnell/oa) orthogonal array project
- [bclib](https://github.com/bertcarnell/bclib) bertcarnell template library
- [R project](http://www.r-project.org)
- [lhs on CRAN](https://r-forge.r-project.org/projects/lhs/)
- [doxygen](http://www.stack.nl/~dimitri/doxygen/)

## Examples

The API is primarily documented through the Doxygen documentation supplied [here](http://bertcarnell.github.io/lhslib/).  The following
code illustrates how the API is called from C++.  The Rcpp API is also illustrated, although it is intended to be
called from within R.  Notes: `bclib` is a namespace from another related github project with common code for bertcarnell's
libraries.  The `bclib::matrix<T>` class is a simple matrix class that only includes necessary operations.  More
robust matrix templates could be used in the future.  `lhslib` is the namespace of this project.

#### improvedLHS Algorithm

```
int n = 4;
int k = 3;
int dup = 5;
bclib::matrix<int> result = bclib::matrix<int>(n,k);

lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::improvedLHS(n, k, dup, result, oRandom);
```

#### maximinLHS Algorithm

```
int n = 4;
int k = 3;
int dup = 5;
bclib::matrix<int> result = bclib::matrix<int>(n, k);

lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::maximinLHS(n, k, dup, result, oRandom);
```

#### optimumLHS Algorithm

```
int n = 4;
int k = 3;
int maxSweeps = 2;
double eps = 0.1;
int jLen = 7; // (4 choose 2) + 1
bclib::matrix<int> result = bclib::matrix<int>(n, k);

lhslib::CRandomStandardUniform oRandom = lhslib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
```
