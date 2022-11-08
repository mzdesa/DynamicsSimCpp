#include <iostream>
using namespace std;
#include <NumCpp.hpp>
#include <observer.h>

//IMPLEMENT the functionf from observer.h down here
nc::NdArray<double> Observer::get_state() {    
    if (sd > 0) {
        //return an observation of the state vector with noise
        nc::NdArray<double> randVec = nc::random::rand<double>(nc::Shape(stateDimn,1)); //not sure if gaussian
        return dynamics.get_state() + randVec;
    }
    return dynamics.get_state();
}