#include "RcppArmadillo.h"

// [[Rcpp::depends(RcppArmadillo)]]

extern "C" {
    double multiply_(double *x, double *y);
}

//' Test of calling a Fortran Function
//'
//' @param x A numeric vectir
//' @return A transformed numeric vector
//' @examples
//' test_function(0:9)
// [[Rcpp::export]]
Rcpp::NumericVector test_function(Rcpp::NumericVector x) {
    int n = x.size();
    Rcpp::NumericVector result(n);
    for ( int i = 0; i < n; ++i ) {
        double starting_value = x[i], multiplier = (double)i;
        result[i] = multiply_(&starting_value, &multiplier);
    }
    return result;
}

