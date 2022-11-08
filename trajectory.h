#include <iostream>
using namespace std;
#include <NumCpp.hpp>


class Trajectory {
  public:
    nc::NdArray<double> x0;
    nc::NdArray<double> xF;
    int spatialDimn;
    double T;
    
    Trajectory(nc::NdArray<double> x_0, nc::NdArray<double> x_f, double spatial_dimn, double period) {
        x0 = x_0;
        xF = x_f;
        spatialDimn = spatial_dimn;
        T = period;
    }

    //define funcs
    nc::NdArray<double> pos(double t);
    nc::NdArray<double> vel(double t);
    nc::NdArray<double> accel(double t);
    nc::NdArray<double> getState(double t);
};