lhslib
======

Latin hypercube sampling code for the lhs pacakge in the statistical software package R (www.r-project.org)

Link to the lhs project page here:  http://bertcarnell.github.io/lhslib/

[![Build Status](https://travis-ci.org/bertcarnell/lhslib.svg?branch=master)](https://travis-ci.org/bertcarnell/lhslib)
[![codecov](https://codecov.io/gh/bertcarnell/lhslib/branch/master/graph/badge.svg)](https://codecov.io/gh/bertcarnell/lhslib)

### Process

The code is transfered from the github project to the R project by copying the code from the github checkout to the SVN checkout location and then committing to the R-Forge project.  The R-Forge project is maintained because of the continuous build environment that it offers using the latest R tool chain.  The R-Forge library contains all the R code and help files while the github library is focused only on the C++ library.

The code is transferred using the `src\deploylhs.bat` batch script in Windows.

### Connections

The project is also connected to the oa (orthogonal array) project.  https://github.com/bertcarnell/oa
