#include <iostream>
#include <string>
using namespace std;

class Kitchen {
    int size;
    string style;
public:
    Kitchen(int s, string st) {
        size = s;
        style = st;
    }
    void showKitchen() const {
        cout << "Kitchen Size: " << size << " sq ft, Style: " << style << endl;
    }
};

class Apartment {
    const int apartmentID;
    Kitchen kitchen;
    int rooms;
public:
    Apartment(int id, int r, int kSize, string kStyle) : apartmentID(id), kitchen(kSize, kStyle) {
        rooms = r;
    }
    void showApartment() const {
        cout << "Apartment ID: " << apartmentID << endl;
        cout << "Rooms: " << rooms << endl;
        kitchen.showKitchen();
    }
};

int main() {
    Apartment a1(101, 3, 120, "Modern");
    Apartment a2(102, 2, 90, "Traditional");

    a1.showApartment();
    cout << endl;
    a2.showApartment();

    return 0;
}
