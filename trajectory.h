#include <iostream>
using namespace std;

class Trajectory {
  public:
    double x0;
    double xF;
    int spatialDimn;
    double T;
    
    Trajectory(double x_0, double x_f, double spatial_dimn, double period) {
        x0 = x_0;
        xF = x_f;
        spatialDimn = spatial_dimn;
        T = period;
    }

    //define funcs
    double pos(double t);
    double vel(double t);
    double accel(double t);
    double getState(double t);
};