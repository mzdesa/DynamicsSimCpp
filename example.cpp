#include <iostream>
#include <NumCpp.hpp>
using namespace std;

class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
    void myFunc();
    MyClass() {     // Constructor
      cout << "Hello World Constructor!";
    }
};

//define the function down here
void MyClass::myFunc() {
    cout << myNum << "\n";
}

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
  myObj.myFunc();
}