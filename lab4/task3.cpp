#include <iostream>
using namespace std;

class PropertyDeed {
private:
    int* ownerID;

public:
    PropertyDeed(int id) {
        ownerID = new int(id);
    }

    PropertyDeed(const PropertyDeed& other, bool shallow) {
        if (shallow) {
            this->ownerID = other.ownerID;
        } else {
            this->ownerID = new int(*other.ownerID); 
        }
    }

    void display(const string& objName) {
        cout << objName << " -> Value: " << *ownerID 
             << ", Address: " << ownerID << endl;
    }

    void setOwnerID(int newID) {
        *ownerID = newID;
    }

    ~PropertyDeed() {
        delete ownerID;
    }
};

int main() {
    PropertyDeed original(101);
    PropertyDeed shallowCopy(original, true);
    PropertyDeed deepCopy(original, false);  

    cout << "Initially:" << endl;
    original.display("Original");
    shallowCopy.display("Shallow Copy");
    deepCopy.display("Deep Copy");

    cout << "\nAfter modifying Original's ownerID to 202:" << endl;
    original.setOwnerID(202);

    original.display("Original");
    shallowCopy.display("Shallow Copy");
    deepCopy.display("Deep Copy");

    return 0;
}
