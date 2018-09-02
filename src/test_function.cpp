#include "RcppArmadillo.h"

// [[Rcpp::depends(RcppArmadillo)]]

extern "C" {
    double multiply_(double *x, double *y);
}

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

