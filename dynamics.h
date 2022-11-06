#include <iostream>
using namespace std;

class Dynamics {       // The class
  public:             // Access specifier
    //system parameters
    int stateDimn;
    int inputDimn;
    int relDegree;

    //current state and input
    double x;
    double u;
    Dynamics(double x0, int stateDim, int inputDim, int relDeg) {     // Constructor
      /*
      Initializes a dynamics object
      */
      stateDimn = stateDim;
      inputDimn = inputDim;
      relDegree = relDeg;

      //store the state and input
      x = x0;
      u = 0;
    }
        
    //Declare dynamics functions
    int get_state();
    double deriv(double x, double u, double t);
    double integrate(double u, double t, double dt);
    void get_plots(double x, double u, double t);
    void show_animation(double xHist, double uHist, double tHist); 
};