#include <iostream>
#include <string>
using namespace std;

class OrderDetails {
private:
    int orderID;
    string itemName;
    const double deliveryFee;
public:
    OrderDetails(int orderID, string itemName, double deliveryFee) 
        : deliveryFee(deliveryFee) {
        this->orderID = orderID;
        this->itemName = itemName;
    }
    ~OrderDetails() {
        cout << "Order " << orderID << " Archived and memory cleared." << endl;
    }
    void display() {
        cout << "Order ID: " << orderID << endl;
        cout << "Item: " << itemName << endl;
        cout << "Delivery Fee: " << deliveryFee << endl;
    }
};

int main() {
    OrderDetails order1(101, "Laptop", 250.0);
    order1.display();
    return 0;
}
