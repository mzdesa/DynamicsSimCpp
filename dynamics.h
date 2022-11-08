#include <iostream>
#include <NumCpp.hpp>

using namespace std;

class Dynamics {       // The class
  public:             // Access specifier
    //system parameters
    int stateDimn;
    int inputDimn;
    int relDegree;

    //current state and input
    nc::NdArray<double> _x;
    nc::NdArray<double> _u;
    Dynamics(nc::NdArray<double> x0, int stateDim, int inputDim, int relDeg) {     // Constructor
      /*
      Initializes a dynamics object
      */
      stateDimn = stateDim;
      inputDimn = inputDim;
      relDegree = relDeg;

      //store the state and input
      _x = x0;
      _u = nc::zeros<double>(stateDimn, 1);
    }
        
    //Declare dynamics functions
    nc::NdArray<double> get_state();
    nc::NdArray<double> deriv(nc::NdArray<double> x, nc::NdArray<double> u, double t);
    nc::NdArray<double> integrate(nc::NdArray<double> u, double t, double dt);
    void get_plots(nc::NdArray<double> xHist, nc::NdArray<double> uHist, nc::NdArray<double> tHist);
    void show_animation(nc::NdArray<double> xHist, nc::NdArray<double> uHist, nc::NdArray<double> tHist); 
};