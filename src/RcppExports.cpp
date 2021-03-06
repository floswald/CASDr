// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// rcpp_hello
List rcpp_hello();
RcppExport SEXP _CASDr_rcpp_hello() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpp_hello());
    return rcpp_result_gen;
END_RCPP
}
// geo_dist
double geo_dist(double lat1, double lon1, double lat2, double lon2);
RcppExport SEXP _CASDr_geo_dist(SEXP lat1SEXP, SEXP lon1SEXP, SEXP lat2SEXP, SEXP lon2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type lat1(lat1SEXP);
    Rcpp::traits::input_parameter< double >::type lon1(lon1SEXP);
    Rcpp::traits::input_parameter< double >::type lat2(lat2SEXP);
    Rcpp::traits::input_parameter< double >::type lon2(lon2SEXP);
    rcpp_result_gen = Rcpp::wrap(geo_dist(lat1, lon1, lat2, lon2));
    return rcpp_result_gen;
END_RCPP
}
// cppST_DWithin
arma::ivec cppST_DWithin(arma::vec lat1, arma::vec lon1, List coord2, double cut);
RcppExport SEXP _CASDr_cppST_DWithin(SEXP lat1SEXP, SEXP lon1SEXP, SEXP coord2SEXP, SEXP cutSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type lat1(lat1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type lon1(lon1SEXP);
    Rcpp::traits::input_parameter< List >::type coord2(coord2SEXP);
    Rcpp::traits::input_parameter< double >::type cut(cutSEXP);
    rcpp_result_gen = Rcpp::wrap(cppST_DWithin(lat1, lon1, coord2, cut));
    return rcpp_result_gen;
END_RCPP
}
// cppST_Dist
arma::vec cppST_Dist(arma::vec lat1, arma::vec lon1, double lat2, double lon2);
RcppExport SEXP _CASDr_cppST_Dist(SEXP lat1SEXP, SEXP lon1SEXP, SEXP lat2SEXP, SEXP lon2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type lat1(lat1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type lon1(lon1SEXP);
    Rcpp::traits::input_parameter< double >::type lat2(lat2SEXP);
    Rcpp::traits::input_parameter< double >::type lon2(lon2SEXP);
    rcpp_result_gen = Rcpp::wrap(cppST_Dist(lat1, lon1, lat2, lon2));
    return rcpp_result_gen;
END_RCPP
}
// naive_dist
double naive_dist(double lon1, double lat1, double lon2, double lat2);
RcppExport SEXP _CASDr_naive_dist(SEXP lon1SEXP, SEXP lat1SEXP, SEXP lon2SEXP, SEXP lat2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type lon1(lon1SEXP);
    Rcpp::traits::input_parameter< double >::type lat1(lat1SEXP);
    Rcpp::traits::input_parameter< double >::type lon2(lon2SEXP);
    Rcpp::traits::input_parameter< double >::type lat2(lat2SEXP);
    rcpp_result_gen = Rcpp::wrap(naive_dist(lon1, lat1, lon2, lat2));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_CASDr_rcpp_hello", (DL_FUNC) &_CASDr_rcpp_hello, 0},
    {"_CASDr_geo_dist", (DL_FUNC) &_CASDr_geo_dist, 4},
    {"_CASDr_cppST_DWithin", (DL_FUNC) &_CASDr_cppST_DWithin, 4},
    {"_CASDr_cppST_Dist", (DL_FUNC) &_CASDr_cppST_Dist, 4},
    {"_CASDr_naive_dist", (DL_FUNC) &_CASDr_naive_dist, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_CASDr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
