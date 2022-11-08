#include <iostream>
#include <math.h>
using namespace std;

#include "trajectory.h"
#include <NumCpp.hpp>


//IMPLEMENT the functionf from trajectory.h down here
nc::NdArray<double> Trajectory::pos(double t) {
    //returns the position of a trajectory
    if (t > T) {
        return xF;
    }
    nc::NdArray<double> des_pos = (xF - x0)*0.5*nc::sin(t*M_PI/T - M_PI/2)+(x0+xF)*0.5;
    return des_pos;
}

nc::NdArray<double> Trajectory::vel(double t) {
    //returns desired velocity at time t
    if (t > T) {
        return nc::zeros<double>((spatialDimn, 1));
    }
    nc::NdArray<double> des_vel = (xF - x0)*0.5*nc::cos(t*M_PI/T - M_PI/2)*M_PI/T;
    return des_vel;
}

nc::NdArray<double> Trajectory::accel(double t) {
    /*
    Function to get the desired acceleration at time t
    Args:
        t: current time
    Returns:
        (Nx1 Numpy array): acceleration for the system to track at time t
    */
    if (t > T) { 
        return nc::zeros<double>((spatialDimn, 1)); 
    }
    nc::NdArray<double> des_accel = -(xF - x0)*0.5* nc::sin((t*3.14/T) - 3.14/2) * nc::square(3.14/T); 
    return des_accel; 
}

nc::NdArray<double> Trajectory::getState(double t){
    // TODO: return an aray ( do later) 
    nc::NdArray<double> stackedDesStates = nc::hstack({pos(t), vel(t), accel(t)});
    return stackedDesStates;  
}