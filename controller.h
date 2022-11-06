#include <iostream>
using namespace std;

#include "observer.h"
#include "trajectory.h"


class Controller {
  public:
    //store input parameters
    Observer observer;
    double lyapunov;
    Trajectory trajectory;
    double obstacleQueue;
    double uBounds;
        
    //store input
    double u;

    Controller(Observer obsv, double lyapunov0, Trajectory traj, double obstacleQ, double uBnd){
    
        /*
        initializes variables 
        Arguments:
            dynamics (Dynamics): system Dynamics object
            observer (Observer): state observer object
            lyapunov (LyapunovBarrier): lyapunov functions, LyapunovBarrier object
            trajectory (Trajectory): trajectory for the controller to track (could just be a constant point!)
            obstacleQueue (ObstacleQueue): ObstacleQueue object, stores all barriers for the system to avoid
            uBounds ((Dynamics.inputDimn x 2) numpy array): minimum and maximum input values to the system
        */


        observer = obsv;
        lyapunov = lyapunov0;
        trajectory = traj;
        obstacleQueue = obstacleQ;
        uBounds = uBnd;
        
        //store input
        u = NULL;



    }

    //Declare our class methods
    double evalInput(double t);
    double getInput();

} 


    
    /*
class Controller:
    def __init__(self, observer, lyapunov = None, trajectory = None, obstacleQueue = None, uBounds = None):
        """
        Skeleton class for feedback controllers
        Args:
            dynamics (Dynamics): system Dynamics object
            observer (Observer): state observer object
            lyapunov (LyapunovBarrier): lyapunov functions, LyapunovBarrier object
            trajectory (Trajectory): trajectory for the controller to track (could just be a constant point!)
            obstacleQueue (ObstacleQueue): ObstacleQueue object, stores all barriers for the system to avoid
            uBounds ((Dynamics.inputDimn x 2) numpy array): minimum and maximum input values to the system
        """
        #store input parameters
        self.observer = observer
        self.lyapunov = lyapunov
        self.trajectory = trajectory
        self.obstacleQueue = obstacleQueue
        self.uBounds = uBounds
        
        #store input
        self._u = None
    



*/