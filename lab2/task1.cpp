#include <iostream>
using namespace std;

void SwapValues(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 10, y = 20;
    cout << "Before Swap: x = " << x << ", y = " << y << endl;
    SwapValues(&x, &y);
    cout << "After Swap: x = " << x << ", y = " << y << endl;
    return 0;
}
