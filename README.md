# mixedlang

`mixedlang` is an example of how to create an R package that utilizes C++ code that calls Fortran code (hence the name "mixedlang," short for mixed language programming).
The package was created as part of an answer to a Stack Overflow question about creating an R function that leverages both C++ and Fortran ([available here](https://stackoverflow.com/questions/31396802/integrate-fortran-c-with-r/52136973#52136973)).

The package was created with the following steps:

1. Set up the package structure from R with `RcppArmadillo::RcppArmadillo.package.skeleton("mixedlang")` (I only used RcppArmadillo rather than Rcpp since the related Stack Overflow question was -- there's nothing Armadillo specific to this example)
2. Added the C++ and Fortran code files to the `src/` folder
3. In R, run `Rcpp::compileAttributes("mixedlang/")` then `devtools::install("mixedlang/")`

The main things to take into account when calling Fortran code from C++ are:

1. Fortran arguments are passed by reference, not by value.
2. Since `MULTIPLY` is defined in another file, we need to declare it in our C++ file so the compiler knows the argument and return types.

    a. When declaring the Fortran function for our C++ file, we'll drop the case of the function name and append an underscore, since the Fortran compiler should do this by default.

    b. We have to declare the function within an `extern "C"` linkage specification; C++ compilers cannot typically use function names as unique identifiers since it allows overloading, but for calling Fortran functions, we need it to do exactly that which the `extern "C"` linkage specification accomplishes (see, for example, [this Stack Overflow answer](https://stackoverflow.com/a/1041880/8386140)).
