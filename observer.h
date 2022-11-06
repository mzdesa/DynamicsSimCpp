#include <iostream>
using namespace std;

class Observer {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
    Observer() {     // Constructor
      myNum = 10;
    }

    //define funcs
    double get_state();
};