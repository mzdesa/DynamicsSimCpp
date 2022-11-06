#include <iostream>
#include <math.h>
using namespace std;

#include "trajectory.h"

//IMPLEMENT the functionf from trajectory.h down here
double Trajectory::pos(double t) {
    //returns the position of a trajectory
    if (t > T) {
        return xF;
    }
    return (xF - x0)/2*sin(t*M_PI/T - M_PI/2)+(x0+xF)/2;
}

double Trajectory::vel(double t) {
    //returns desired velocity at time t
    if (t > T) {
        return 0;
    }
    double des_vel = (xF - x0)/2*cos(t*M_PI/T - M_PI/2)*M_PI/T;
    return des_vel;
}

double Trajectory::accel(double t) {
    /*
    Function to get the desired acceleration at time t
    Args:
        t: current time
    Returns:
        (Nx1 Numpy array): acceleration for the system to track at time t
    */
    if (t > T) { 
        return 0; 
    }
    double des_accel = -(xF - x0)/2 * sin((t*3.14/T) - 3.14/2)*3.14/T**2; 
    return des_accel; 
}

double Trajectory::getState(double t){
    // TODO: return an aray ( do later) 
    return pos(t); //vel(t), accel(t);    
}