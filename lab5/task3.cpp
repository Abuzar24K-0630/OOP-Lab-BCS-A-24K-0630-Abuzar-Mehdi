#include <iostream>
#include <string>
using namespace std;

class Doctor {
    string name;
    string specialization;
public:
    Doctor(string n, string s) {
        name = n;
        specialization = s;
    }
    void display() const {
        cout << "Doctor: " << name << ", Specialization: " << specialization << endl;
    }
};

class Hospital {
    string hospitalName;
    Doctor* doctors[10];
    int count;
public:
    Hospital(string name) {
        hospitalName = name;
        count = 0;
    }
    void addDoctor(Doctor* d) {
        if (count < 10) {
            doctors[count] = d;
            count++;
        }
    }
    void showDoctors() const {
        cout << "Hospital: " << hospitalName << endl;
        for (int i = 0; i < count; i++) {
            doctors[i]->display();
        }
    }
};

int main() {
    Doctor d1("Dr. Ali", "Cardiologist");
    Doctor d2("Dr. Sara", "Neurologist");
    Doctor d3("Dr. Ahmed", "Orthopedic");

    Hospital h1("Lahore General Hospital");
    Hospital h2("Shaukat Khanum Hospital");

    h1.addDoctor(&d1);
    h1.addDoctor(&d2);
    h2.addDoctor(&d3);
    h2.addDoctor(&d1);

    h1.showDoctors();
    cout << endl;
    h2.showDoctors();

    return 0;
}
