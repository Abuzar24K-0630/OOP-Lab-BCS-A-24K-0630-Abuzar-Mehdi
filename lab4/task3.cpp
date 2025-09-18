#include <iostream>
#include <string>
using namespace std;

struct Doctor {
    string name;
    string department;
    Doctor(string n = "", string d = "") {
        name = n;
        department = d;
    }
};

class Patient {
private:
    int id;
    string name;
    int age;
    string disease;
    Doctor doctorAssigned;
public:
    Patient(int i = 0, string n = "", int a = 0, string dis = "") {
        id = i;
        name = n;
        age = a;
        disease = dis;
        doctorAssigned = Doctor();
    }
    Patient(int i, string n, int a, string dis, Doctor doc) {
        id = i;
        name = n;
        age = a;
        disease = dis;
        doctorAssigned = doc;
    }
    int getId() const { return id; }
    void assignDoctor(Doctor d) { doctorAssigned = d; }
    void display() const {
        cout << "Patient ID: " << id
             << ", Name: " << name
             << ", Age: " << age
             << ", Disease: " << disease
             << ", Doctor: " << doctorAssigned.name
             << " (" << doctorAssigned.department << ")" << endl;
    }
};

class Hospital {
private:
    Patient** patients;
    int capacity;
    int count;
    static int nextId;
public:
    Hospital(int cap = 20) {
        capacity = cap;
        count = 0;
        patients = new Patient*[capacity];
    }
    ~Hospital() {
        for (int i = 0; i < count; i++) {
            delete patients[i];
        }
        delete[] patients;
    }
    void addPatient(string name, int age, string disease) {
        if (count >= capacity) {
            cout << "Hospital capacity reached!" << endl;
            return;
        }
        patients[count] = new Patient(nextId++, name, age, disease);
        count++;
    }
    void addPatient(string name, int age, string disease, Doctor doc) {
        if (count >= capacity) {
            cout << "Hospital capacity reached!" << endl;
            return;
        }
        patients[count] = new Patient(nextId++, name, age, disease, doc);
        count++;
    }
    void assignDoctorToPatient(int id, Doctor d) {
        Patient* p = searchPatient(id);
        if (p) {
            p->assignDoctor(d);
            cout << "Doctor assigned successfully." << endl;
        } else {
            cout << "Patient not found." << endl;
        }
    }
    void removePatient(int id) {
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                delete patients[i];
                for (int j = i; j < count - 1; j++) {
                    patients[j] = patients[j + 1];
                }
                count--;
                cout << "Patient removed successfully." << endl;
                return;
            }
        }
        cout << "Patient not found." << endl;
    }
    Patient* searchPatient(int id) {
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                return patients[i];
            }
        }
    }
    void displayPatients() const {
        if (count == 0) {
            cout << "No patients in the hospital." << endl;
            return;
        }
        cout << "--- Patient Records ---" << endl;
        for (int i = 0; i < count; i++) {
            patients[i]->display();
        }
    }
};

int Hospital::nextId = 1;

int main() {
    Hospital h(10);

    h.addPatient("Ali", 30, "Flu");
    h.addPatient("Sara", 25, "Fever", Doctor("Dr. Khan", "General Medicine"));
    h.addPatient("Bilal", 40, "Fracture");

    h.displayPatients();

    h.assignDoctorToPatient(1, Doctor("Dr. Ahmed", "ENT"));

    h.displayPatients();

    h.removePatient(2);

    h.displayPatients();

    Patient* p = h.searchPatient(3);
    if (p) {
        cout << "Patient found: ";
        p->display();
    } else {
        cout << "Patient not found." << endl;
    }

    return 0;
}
