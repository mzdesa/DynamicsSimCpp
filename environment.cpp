#include <iostream>
using namespace std;
#include "environment.h"
#include <NumCpp.hpp>

//Implement our environment functions
void Environment::reset() {
    /*
    Reset the environment to its original state!
    */
    iter = 0; //number of iterations
    t = 0; //time in seconds
    done = false;
    
    //reset system state
    x = x0; //retrieves initial condition
    xObsv = 0; //reset observer state

    //define history arrays
    xHist = nc::zeros<double>(dynamics.stateDimn, 1);
    uHist = nc::zeros<double>(dynamics.inputDimn, 1);
    tHist = nc::zeros<double>(1, 1);
}

void Environment::step() {
    /* 
    Step the sim environment by one integration!
    */
    //retrieve current state information, update the observer
    getObservation();
    
    //solve for the controller input
    controller.get_input();

    //zero order hold over the control frequency
    for (int i = 0; i<simsPerStep; i++) {
        //integrate the system dynamics
        dynamics.integrate(controller.get_input(), t, 1/simFreq);
        //increment the time
        t = t + 1/simFreq;
    }
}

void Environment::updateData() {
    //update the history arrays
    xHist = nc::hstack({xHist, x}); 
    
    uHist = nc::hstack({uHist, controller.get_input()});
    
    //place t in an intermediate array to hstack correctly
    nc::NdArray<double> tTemp = {t};
    tHist = nc::hstack({tHist, tTemp});
    
    x = dynamics.get_state();

    iter++;
}

void Environment::getObservation() {
    xObsv = observer.get_state();
}

int Environment::getReward() {
    return 0; 
}

bool Environment::isDone() {
    if (t >= totalSimTime) {
        return true;
    }
    return false;
}

void Environment::run(int N) {
    /*
    Runs the simulation
    */

    for (int i = 0; i < N; i++){
        reset();
        while (isDone()){
            std::cout << "Simulation Time Remaining: "<<"\n";
        }
    }
}

void Environment::visualize() {

/*  def visualize(self):
    """
    Provide visualization of the environment
    """
    self.dynamics.show_animation(self.xHist, self.uHist, self.tHist)*/
    dynamics.show_animation(xHist, uHist, tHist);
}
    
int main() {
    //do nothing in main for now
}