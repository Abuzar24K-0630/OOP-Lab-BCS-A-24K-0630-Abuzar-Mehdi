#include <iostream>
#include <string>
using namespace std;

class MobileAccount {
private:
    double balance;
    string phoneNumber;

public:
    MobileAccount() {
        balance = 50.0;
        phoneNumber = "";
    }

    MobileAccount(string number, double initialBalance) {
        phoneNumber = number;
        balance = initialBalance;
    }

    void display() {
        cout << "Phone Number: " << (phoneNumber == "" ? "Not set" : phoneNumber) << endl;
        cout << "Balance: " << balance << " PKR" << endl;
    }
};

int main() {
    MobileAccount acc1;  
    acc1.display();

    cout << endl;

    MobileAccount acc2("03001234567", 200.0);
    acc2.display();

    return 0;
}
