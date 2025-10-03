#include <iostream>
#include <string>
using namespace std;

class CurrencyExchange {
private:
    const double PKR_to_USD_Rate;
    string branchName;
    int totalTransactions;
public:
    CurrencyExchange(double rate, string branch, int transactions) 
        : PKR_to_USD_Rate(rate), branchName(branch), totalTransactions(transactions) {}

    double convertPKRtoUSD(double pkr) {
        totalTransactions++;
        return pkr / PKR_to_USD_Rate;
    }

    void display() {
        cout << "Branch: " << branchName << endl;
        cout << "Exchange Rate (PKR -> USD): " << PKR_to_USD_Rate << endl;
        cout << "Total Transactions: " << totalTransactions << endl;
    }
};

int main() {
    CurrencyExchange counter(277.5,"Karachi Main Branch", 0);

    counter.display();
    cout << "5000 PKR = " << counter.convertPKRtoUSD(5000) << " USD" << endl;
    counter.display();

    return 0;
}