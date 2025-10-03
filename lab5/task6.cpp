#include <iostream>
#include <string>
using namespace std;

class Employee {
    string name;
    string designation;
    static int totalEmployees;
public:
    Employee(string n, string d) {
        name = n;
        designation = d;
        totalEmployees++;
    }
    void showEmployee() const {
        cout << "Employee: " << name << ", Designation: " << designation << endl;
    }
    static void showTotalEmployees() {
        cout << "Total Employees in Company: " << totalEmployees << endl;
    }
};

int Employee::totalEmployees = 0;

class ClientProject {
    string projectName;
    Employee* team[10];
    int count;
public:
    ClientProject(string pname) {
        projectName = pname;
        count = 0;
    }
    void addEmployee(Employee* e) {
        if (count < 10) {
            team[count] = e;
            count++;
        }
    }
    void showTeam() const {
        cout << "Project: " << projectName << endl;
        for (int i = 0; i < count; i++) {
            team[i]->showEmployee();
        }
    }
};

int main() {
    Employee e1("Ali", "Developer");
    Employee e2("Sara", "Designer");
    Employee e3("Ahmed", "Tester");
    Employee e4("Nida", "Manager");

    ClientProject p1("E-Commerce Website");
    p1.addEmployee(&e1);
    p1.addEmployee(&e2);
    p1.addEmployee(&e3);

    p1.showTeam();
    cout << endl;
    Employee::showTotalEmployees();

    return 0;
}
