#include <iostream>
#include <NumCpp.hpp>
#include "dynamics.h"
#include "controller.h"
#include "observer.h"
using namespace std;

//Class definition for a simulation enviornment
class Environment {
  public:   
    //PUBLIC INSTANCE VARIABLES          
    //store system parameters
    Dynamics dynamics; //classes have upper case names, object is lower case 
    Controller controller;
    Observer  observer;
    
    //define environment parameters
    int iter; //number of iterations
    double t; //time in seconds 
    bool done; //bool is true or false variable 

    //Store system state
    nc::NdArray<double> x; //actual state of the system (arrays should be set as double)
    nc::NdArray<double> x0; //initial condition for system
    nc::NdArray<double> xObsv; //state as read by the observer
    nc::NdArray<double> ptCloud; //point cloud state as read by vision
    
    //Define simulation parameters
    int simFreq; //integration frequency in Hz
    int controlFreq; //control frequency in Hz
    double simsPerStep;
    double totalSimTime;; //total simulation time in s
    
    //Define history arrays
    nc::NdArray<double> xHist;
    nc::NdArray<double> uHist;
    nc::NdArray<double> tHist;

    Environment(Dynamics dyn, Controller contr, Observer obsv) {
        /*
        Initializes a simulation environment
        Inputs:
        dynamics (Dynamics object)
        controller (Controller object)
        observer (Observer object)
        */

        //store input parameters
        dynamics = dyn;
        controller = contr;
        observer = obsv; 

        //set environment parameters
        iter = 0; //number of iterations
        t = 0; //time in seconds 
        done = false; //bool is true or false variable 

        //set system state
        x = dynamics.get_state(); //actual state of the system (arrays should be set as double)
        x0 = x; //initial condition for system
        xObsv = nc::zeros<double>(dynamics.stateDimn, 1); //state as read by the observer
        ptCloud = 0; //point cloud state as read by vision
    
        //set simulation parameters
        simFreq = 1000; //integration frequency in Hz
        controlFreq = 50; //control frequency in Hz
        simsPerStep = simFreq/controlFreq;
        totalSimTime = 12; //total simulation time in s
    
        //set history arrays
        xHist = nc::zeros<double>(dynamics.stateDimn, totalSimTime*controlFreq+1);
        uHist = nc::zeros<double>(dynamics.inputDimn, totalSimTime*controlFreq+1);
        tHist = nc::zeros<double>(1, totalSimTime*controlFreq+1);
    }

    //Declare our class methods
    void reset();
    void step();
    void updateData();
    void getObservation();
    int getReward();
    bool isDone();
    void run(int N);
    void visualize();
};