//create a dynamics function in here
#include <iostream>
using namespace std;

#include "dynamics.h"

//IMPLEMENT the functionf from dynamics.h down here
int Dynamics::get_state() {
    /*
    Retrieve the state vector
    */
    return x;
}

double Dynamics::deriv(double x, double u, double t) {
  /*
  Returns derivative of the state vector
  */
  return 0;
}

double Dynamics::integrate(double u, double t, double dt) {
  x = get_state() + deriv(get_state(), u, t)*dt;
  return x;
}

void Dynamics::get_plots(double x, double u, double t) {
  /*
  Function to show the plots for a system
  */
  return;
}

void Dynamics::show_animation(double x, double u, double t) {
  /*
  Function to play animation specific to this dynamic system
  */
  return;
}

int main() {
  //do nothing for now
}


