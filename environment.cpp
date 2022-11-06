#include <iostream>
using namespace std;
#include "environment.h"


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
    xHist = 0;
    uHist = 0;
    tHist = 0;
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
    /* 
    """
        Update history arrays and deterministic state data
        """
        #append the input, time, and state to their history queues
        self.xHist[:, self.iter] = self.x.reshape((self.dynamics.stateDimn, ))
        self.uHist[:, self.iter] = (self.controller.get_input()).reshape((self.dynamics.inputDimn, ))
        self.tHist[:, self.iter] = self.t
        
        #update the actual state of the system
        self.x = self.dynamics.get_state()
        
        #update the number of iterations of the step function
        self.iter +=1
    */
    double xHist; 
    double uHist; 
    double tHist; 
    
    double x; 

    int iter;  
}

void Environment::getObservation() {
    int xObsv 
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