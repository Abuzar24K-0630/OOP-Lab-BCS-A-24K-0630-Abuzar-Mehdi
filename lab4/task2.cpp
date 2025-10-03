#include <iostream>
#include <string>
using namespace std;

class NUCES_Student {
private:
    int id;
    string name;

public:
    NUCES_Student() {
        id = 0;
        name = "Not Registered";
    }

    NUCES_Student(int id) {
        this->id = id;
        name = "Name Pending";
    }

    NUCES_Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void display() {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};

int main() {
    NUCES_Student s1;
    NUCES_Student s2(2025);
    NUCES_Student s3(2026, "Abuzar");

    cout << "Default Constructor:" << endl;
    s1.display();

    cout << "\nParameterized Constructor (ID only):" << endl;
    s2.display();

    cout << "\nParameterized Constructor (ID + Name):" << endl;
    s3.display();

    return 0;
}
