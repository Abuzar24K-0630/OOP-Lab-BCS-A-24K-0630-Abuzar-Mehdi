#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string designation;
    int hoursWorked;
    double salary;
public:
    Employee(int i = 0, string n = "", string d = "") {
        id = i;
        name = n;
        designation = d;
        hoursWorked = 0;
        salary = 0.0;
    }
    Employee(int i, string n, string d, int h) {
        id = i;
        name = n;
        designation = d;
        hoursWorked = h;
        salary = 0.0;
    }
    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    int getHoursWorked() const { return hoursWorked; }
    double getSalary() const { return salary; }

    void incrementHours(int h) { hoursWorked += h; }
    void setSalary(double s) { salary = s; }

    void viewRecord() const {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Designation: " << designation
             << ", Hours Worked: " << hoursWorked
             << ", Salary: " << salary << endl;
    }
};

class Admin {
private:
    Employee** employees;
    int capacity;
    int count;
    static int nextId;
public:
    Admin(int cap = 20) {
        capacity = cap;
        count = 0;
        employees = new Employee*[capacity];
    }
    ~Admin() {
        for (int i = 0; i < count; i++) {
            delete employees[i];
        }
        delete[] employees;
    }
    void addEmployee(string name, string designation) {
        if (count >= capacity) {
            cout << "Capacity reached!" << endl;
            return;
        }
        employees[count] = new Employee(nextId++, name, designation);
        count++;
    }
    void addEmployee(string name, string designation, int hours) {
        if (count >= capacity) {
            cout << "Capacity reached!" << endl;
            return;
        }
        employees[count] = new Employee(nextId++, name, designation, hours);
        count++;
    }
    void recordAttendance(int id, int hours) {
        Employee* e = searchEmployee(id);
        if (e) {
            e->incrementHours(hours);
            cout << "Attendance marked for " << e->getName() << endl;
        } else {
            cout << "Employee not found." << endl;
        }
    }
    void calculateSalary(int id, double hourlyRate) {
        Employee* e = searchEmployee(id);
        if (e) {
            double s = e->getHoursWorked() * hourlyRate;
            e->setSalary(s);
            cout << "Salary calculated for " << e->getName() << ": " << s << endl;
        } else {
            cout << "Employee not found." << endl;
        }
    }
    void displayAllRecords() const {
        if (count == 0) {
            cout << "No employees available." << endl;
            return;
        }
        cout << "--- Employee Records ---" << endl;
        for (int i = 0; i < count; i++) {
            employees[i]->viewRecord();
        }
    }
    Employee* searchEmployee(int id) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getId() == id) {
                return employees[i];
            }
        }
        return 0;
    }
    void employeeView(int id) {
        Employee* e = searchEmployee(id);
        if (e) {
            cout << "--- Employee View ---" << endl;
            e->viewRecord();
        } else {
            cout << "Employee not found." << endl;
        }
    }
};

int Admin::nextId = 1;

int main() {
    Admin admin(10);

    admin.addEmployee("Ali", "Developer");
    admin.addEmployee("Sara", "Designer", 5);
    admin.addEmployee("Bilal", "Manager");

    admin.recordAttendance(1, 8);
    admin.recordAttendance(2, 6);

    admin.calculateSalary(1, 500);
    admin.calculateSalary(2, 400);

    admin.displayAllRecords();

    cout << "\nEmployee trying to view their record:" << endl;
    admin.employeeView(1);

    return 0;
}
