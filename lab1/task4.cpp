#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        bool unique = true;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                unique = false;
                break;
            }
        }
        if (unique) return arr[i];
    }
    return arr[0];
}

int main() {
    int n;
    cout << "Enter size of arrays: ";
    cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) cin >> arr1[i];

    cout << "Enter elements of second array: ";
    for (int i = 0; i < n; i++) cin >> arr2[i];

    for (int i = 0; i < n; i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }

    cout << "\nAfter swapping:" << endl;
    cout << "First array: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

    cout << "Second array: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    int largest = arr1[0];
    for (int i = 1; i < n; i++) {
        if (arr1[i] > largest) largest = arr1[i];
    }
    cout << "\nLargest element in first array: " << largest << endl;

    int firstMax = arr2[0], secondMax = -1e9;
    for (int i = 1; i < n; i++) {
        if (arr2[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr2[i];
        } else if (arr2[i] > secondMax && arr2[i] != firstMax) {
            secondMax = arr2[i];
        }
    }
    if (secondMax == -1e9) secondMax = firstMax;
    cout << "Second largest element in second array: " << secondMax << endl;

    int uniqueElement = findUnique(arr1, n);
    cout << "Unique element in first array: " << uniqueElement << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
