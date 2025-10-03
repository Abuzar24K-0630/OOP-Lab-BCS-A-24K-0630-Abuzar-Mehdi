#include <iostream>
#include <string>
using namespace std;

class SecureBankAccount {
private:
    int accountNumber;
    double balance;
    const string accountType;
    int* logHistory;
public:
    SecureBankAccount(int accountNumber, double balance, const string& accountType, int logSize) 
        : accountType(accountType) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        if (balance < 500.0) {
            cout << "Error: Initial balance cannot be less than 500 PKR." << endl;
        }
        logHistory = new int(logSize);
    }

    SecureBankAccount(const SecureBankAccount& other) 
        : accountType(other.accountType) {
        this->accountNumber = other.accountNumber;
        this->balance = other.balance;
        logHistory = new int(*other.logHistory);
    }

    ~SecureBankAccount() {
        delete logHistory;
        cout << "Account " << accountNumber << " memory released." << endl;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Log History Size: " << *logHistory << endl;
    }
};

int main() {
    SecureBankAccount acc1(12345, 1000.0, "Current", 5);
    acc1.display();

    cout << "\nCreating Deep Copy...\n";
    SecureBankAccount acc2 = acc1;
    acc2.display();

    return 0;
}