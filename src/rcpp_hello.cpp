
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*  Copyright notice for functions deg2rad, rad2deg and geo_dist                                  */
/*                                                                                                */
/*                                                                                                */
/* Latitude/longitude spherical geodesy tools                         (c) Chris Veness 2002-2019  */
/*                                                                                   MIT Licence  */
/* www.movable-type.co.uk/scripts/latlong.html                                                    */
/* www.movable-type.co.uk/scripts/geodesy-library.html#latlon-spherical                           */
/*                                                                                                */
/* source code at https://github.com/chrisveness/geodesy                                          */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */


#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]



using namespace Rcpp;

// This is a simple function using Rcpp that creates an R list
// containing a character vector and a numeric vector.
//
// Learn more about how to use Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//
// and browse examples of code using Rcpp at:
//
//   http://gallery.rcpp.org/
//

//' hello function
//' @export
// [[Rcpp::export]]
List rcpp_hello() {
    CharacterVector x = CharacterVector::create("foo", "bar","zap");
    NumericVector y   = NumericVector::create(0.0, 1.0);
    List z            = List::create(x, y);
    return z;
}

double deg2rad(double deg) {
    return (deg * arma::datum::pi / 180);
}


double rad2deg(double rad) {
    return (rad * 180 / arma::datum::pi);
}


//' geo dist
//'
//' compute straight line distance in WGS84 CRS (lat,long) in km.
//' Uses the sperical law of cosines https://en.wikipedia.org/wiki/Spherical_law_of_cosines
//' as used here https://www.movable-type.co.uk/scripts/latlong.html
//'
//' @author Chris Veness
//'
//' @references https://github.com/chrisveness/geodesy www.movable-type.co.uk/scripts/latlong.html
//'
//' @export
// [[Rcpp::export]]
double geo_dist(double lat1, double lon1, double lat2, double lon2) {
    double theta, dist;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
    dist = dist * 1.609344;
    return (dist);
}

//' ST_Dwithin: Geographic Distance
//'
//' Computes number of units within distance `cutoff` in meters from lat-long measures.
//' Efficient implementation using C++ library Armadillo.
//'
//' @export
// [[Rcpp::export]]
arma::ivec cppST_DWithin(arma::vec lat1, arma::vec lon1, List coord2, double cut){

    arma::wall_clock timer;
    double nt;
    timer.tic();

    arma::vec lon2 = as<arma::vec>( coord2["longitude"] );
    arma::vec lat2 = as<arma::vec>( coord2["latitude"]  );

    int n = lat1.n_elem;
    int m = lat2.n_elem;
    int s = 0;
    double dist;
    arma::ivec close(n);

    // progress bar setup
    float progress = 0.0;
    int pos = 0;
    int barWidth = 70;

    for(int i = 0; i < n; i++){
        progress = i/n;
        s = 0;
        for (int j=0; j<m; j++){
            dist = geo_dist(lat1[i],lon1[i],lat2[j],lon2[j]) ;
            // printf("dist = %f\n",dist);
            if (dist < cut){
                s += 1;
            }
        }
        close[i] = s;

        // print progress bar
        std::cout << "[";
        pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();
    }
    std::cout << std::endl;

    nt = timer.toc();
    arma::ivec nnz(nonzeros(close));
    printf("        This computation took %f seconds.\n",nt);
    printf("        found %d units with ABB close by.\n",nnz.n_elem);

    return close;
}

//' cppST_Dist: RcppArmadillo Fast Distances
//'
//' Computes distance in kilometers to a single point.
//'
//' This function is for efficient use of geodesic distance calculations
//' inside a grouped data.table. In particular, for two sets of locations,
//' for instance `start_commute` and `end_commute`, each given by a coordinate pair
//' and a string identifier, this function can be called `by` each value of `end_commute`
//' in order to compute all commuting distances from all `start_commute` locations to the
//' particular `end_commute` location.
//'
//' @export
// [[Rcpp::export]]
arma::vec cppST_Dist(arma::vec lat1, arma::vec lon1, double lat2, double lon2){

    arma::wall_clock timer;
    double nt;
    timer.tic();


    int n = lat1.n_elem;
    arma::vec dist(n);

    for(int i = 0; i < n; i++){
        dist[i] = geo_dist(lat1[i],lon1[i],lat2,lon2) ;
    }

    nt = timer.toc();
    printf("        This computation took %f seconds.\n",nt);

    return dist;
}



//' Distance calculator
//'
//' low level c++ function
//' @export
// [[Rcpp::export]]
double naive_dist(double lon1, double lat1, double lon2, double lat2){
    double x,y;
    x = (lon2 - lon1);
    y = lat2 - lat1;
    return sqrt(x*x + y*y);
}

