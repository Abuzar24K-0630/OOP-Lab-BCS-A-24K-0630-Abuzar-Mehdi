#include <iostream>
using namespace std;

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int denominations[] = {5000, 1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(denominations) / sizeof(denominations[0]);

    cout << "\nMinimum notes required:" << endl;
    for (int i = 0; i < n; i++) {
        int count = amount / denominations[i];
        if (count > 0) {
            cout << denominations[i] << " x " << count << endl;
            amount -= count * denominations[i];
        }
    }

    return 0;
}
