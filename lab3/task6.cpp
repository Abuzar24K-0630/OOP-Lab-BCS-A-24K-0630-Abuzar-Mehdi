#include <iostream>
#include <string>
using namespace std;

class Vehicle {
  public:
  string make;
  string model;

  void displayInfo(){
    cout << "Vehical Type :" << make << endl;
    cout << "Vehical Model :" << model << endl;
  }
};

class Car : public Vehicle {
  public:
  string engineType;
  void displayInfo(){
    Vehicle::displayInfo();
    cout << "Engine Type :" << engineType << endl;
  }
};

int main (){
  Car obj1;
  obj1.make="Toyota";
  obj1.model="Hilux 2025";
  obj1.engineType="Hybrid";
  obj1.displayInfo();
}