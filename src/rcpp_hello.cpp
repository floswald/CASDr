
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
//' Computes number of units within distance `cutoff` in meters from degree location measures.
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

//' cppST_Dist
//'
//' Computes distance in kilometers to a single point.
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

