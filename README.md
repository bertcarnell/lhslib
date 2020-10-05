lhslib
======

C++ Latin hypercube sampling code.  Used in the `lhs` pacakge in the statistical software package R (www.r-project.org).  
Link to the `lhs` project page [here](https://bertcarnell.github.io/lhslib/html/index.html).

|<sub>Linux & MacOS</sub>|<sub>Windows</sub>|<sub>Code Coverage</sub>|<sub>Actions</sub>|
|:---:|:---:|:---:|:---:|
|[![Build Status](https://travis-ci.org/bertcarnell/lhslib.svg?branch=master)](https://travis-ci.org/bertcarnell/lhslib)|[![Build status](https://ci.appveyor.com/api/projects/status/7xd7sohoug7c0d42?svg=true)](https://ci.appveyor.com/project/bertcarnell/lhslib)|[![codecov](https://codecov.io/gh/bertcarnell/lhslib/branch/master/graph/badge.svg)](https://codecov.io/gh/bertcarnell/lhslib)|![CMake](https://github.com/bertcarnell/lhslib/workflows/CMake/badge.svg)|

### Connections

- [oa](https://github.com/bertcarnell/oa) orthogonal array project
- [bclib](https://github.com/bertcarnell/bclib) bertcarnell template library
- [lhs](https://bertcarnell.github.io/lhslib) package
- [R project](http://www.r-project.org)
- [lhs on CRAN](https://r-forge.r-project.org/projects/lhs/)
- [doxygen](http://www.stack.nl/~dimitri/doxygen/)

## Examples

The API is primarily documented through the Doxygen documentation supplied [here](http://bertcarnell.github.io/lhslib/).  The following
code illustrates how the API is called from C++.  The `bclib::matrix<T>` class is a simple matrix class that only includes necessary operations.  More
robust matrix templates could be used in the future.  `lhslib` is the namespace of this project.

#### randomLHS Algorithm

```c
int n = 4;
int k = 3;
bool bPreserveDraw = false;
bclib::matrix<double> result = bclib::matrix<double>(n,k);

bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::randomLHS(n, k, bPreserveDraw, result, oRandom);
```

#### improvedLHS Algorithm

```c
int n = 4;
int k = 3;
int dup = 5;
bclib::matrix<int> result = bclib::matrix<int>(n,k);

bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::improvedLHS(n, k, dup, result, oRandom);
```

#### maximinLHS Algorithm

```c
int n = 4;
int k = 3;
int dup = 5;
bclib::matrix<int> result = bclib::matrix<int>(n, k);

bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::maximinLHS(n, k, dup, result, oRandom);
```

#### optimumLHS Algorithm

```c
int n = 4;
int k = 3;
int maxSweeps = 2;
double eps = 0.1;
int jLen = 7; // (4 choose 2) + 1
bclib::matrix<int> result = bclib::matrix<int>(n, k);

bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::optimumLHS(n, k, maxSweeps, eps, result, jLen, oRandom, false);
```

#### geneticLHS Algorithm

```c
int n = 10;
int k = 4;
int pop = 20;
int gen = 5;
double pMut = 0.10;
std::string crit = "S";
bool verbose = false;
bclib::matrix<double> result = bclib::matrix<double>(n, k);

bclib::CRandomStandardUniform oRandom = bclib::CRandomStandardUniform();
oRandom.setSeed(1976, 1968);
lhslib::geneticLHS(n, k, pop, gen, pMut, crit, verbose, result, oRandom);
```
