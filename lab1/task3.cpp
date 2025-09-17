#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void findPrimesInRange(int start, int end) {
    for (int i = start + 1; i < end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start, end;
    cout << "Enter start: ";
    cin >> start;
    cout << "Enter end: ";
    cin >> end;

    cout << "Prime numbers between " << start << " and " << end << ": ";
    findPrimesInRange(start, end);

    return 0;
}
