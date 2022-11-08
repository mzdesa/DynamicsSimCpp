#include <iostream>
using namespace std;
#include <NumCpp.hpp>
#include <dynamics.h>

class Observer {
  public:
    Dynamics dynamics;
    int stateDimn;
    int inputDimn;
    float mean;
    float sd;
    Observer(Dynamics dyn, float m, float s) {
      dynamics = dyn;
      stateDimn = dynamics.stateDimn;
      inputDimn = dynamics.inputDimn;
      mean = m;
      sd = s;

      //seed the random noise
      nc::random::seed(666);
    }

    //define funcs
    nc::NdArray<double> get_state();
};