//create a dynamics function in here
#include <iostream>
using namespace std;

#include <NumCpp.hpp>
#include "dynamics.h"

//IMPLEMENT the functionf from dynamics.h down here
nc::NdArray<double> Dynamics::get_state() {
    /*
    Retrieve the state vector
    */
    return _x;
}

nc::NdArray<double> Dynamics::deriv(nc::NdArray<double> x, nc::NdArray<double> u, double t) {
  /*
  Returns derivative of the state vector
  */
  return nc::zeros<double>(stateDimn, 1);
}

nc::NdArray<double> Dynamics::integrate(nc::NdArray<double> u, double t, double dt) {
  _x = get_state() + deriv(get_state(), u, t)*dt;
  return _x;
}

void Dynamics::get_plots(nc::NdArray<double> xHist, nc::NdArray<double> uHist, nc::NdArray<double> tHist) {
  /*
  Function to show the plots for a system
  */
  return;
}

void Dynamics::show_animation(nc::NdArray<double> xHist, nc::NdArray<double> uHist, nc::NdArray<double> tHist) {
  /*
  Function to play animation specific to this dynamic system
  */
  return;
}

int main() {
  //do nothing for now
}


