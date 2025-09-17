#include <iostream>
#include <string>
using namespace std;

class Vehicle {
  public:
  string type = "Car";
  string model = "2025";

  void displayInfo(){
    cout << "Vehical Type :" << type << endl;
    cout << "Vehical Model :" << model << endl;
  }
};

class Car : public Vehicle {
  public:
  Vehicle obj;
  string engineType = "Turbo" ;
  string engineNo = "0C8X65A321";
  void displayInfo(){
    obj.displayInfo();
    cout << "Engine Type :" << engineType << endl;
    cout << "Engine No :" << engineNo << endl;

  }
};

int main (){
  Car obj1;
  obj1.displayInfo();
}