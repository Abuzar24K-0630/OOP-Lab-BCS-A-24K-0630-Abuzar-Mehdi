#include <iostream>
using namespace std;

class PetrolPump {
    static double pricePerLiter;
    int pumpID;
    double litersFilled;
public:
    PetrolPump(int id, double liters) {
        pumpID = id;
        litersFilled = liters;
    }
    void printReceipt() {
        cout << "Pump ID: " << pumpID << endl;
        cout << "Liters Filled: " << litersFilled << endl;
        cout << "Price per Liter: " << pricePerLiter << endl;
        cout << "Total Amount: " << litersFilled * pricePerLiter << endl;
    }
};

double PetrolPump::pricePerLiter = 270;

int main() {
    PetrolPump p1(101, 15.5);
    p1.printReceipt();
    return 0;
}
