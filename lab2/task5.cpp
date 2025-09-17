#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int size1, size2;
    cout << "Enter length of first string: ";
    cin >> size1;
    cout << "Enter length of second string: ";
    cin >> size2;

    char* str1 = new char[size1 + 1];
    char* str2 = new char[size2 + 1];

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    char* result = new char[size1 + size2 + 1];
    strcpy(result, str1);
    strcat(result, str2);

    cout << "\nFirst String: " << str1 << endl;
    cout << "Second String: " << str2 << endl;
    cout << "Concatenated String: " << result << endl;

    delete[] str1;
    delete[] str2;
    delete[] result;

    return 0;
}
