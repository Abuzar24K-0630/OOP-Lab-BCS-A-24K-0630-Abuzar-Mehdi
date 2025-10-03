#include <iostream>
#include <string>
using namespace std;

class ClassSchedule {
    string days;
    string time;
public:
    ClassSchedule(string d, string t) {
        days = d;
        time = t;
    }
    void showSchedule() const {
        cout << "Schedule: " << days << " at " << time << endl;
    }
};

class Student {
    string name;
    const int enrollmentID;
public:
    Student(string n, int id) : enrollmentID(id) {
        name = n;
    }
    void showStudent() const {
        cout << "Student: " << name << ", Enrollment ID: " << enrollmentID << endl;
    }
};

class CourseSection {
    string sectionName;
    ClassSchedule schedule;  
    Student* students[50];   
    int studentCount;
    static int totalSections; 
public:
    CourseSection(string name, string d, string t) : sectionName(name), schedule(d, t) {
        studentCount = 0;
        totalSections++;
    }
    void addStudent(Student* s) {
        if (studentCount < 50) {
            students[studentCount] = s;
            studentCount++;
        }
    }
    void showSection() const {
        cout << "Course Section: " << sectionName << endl;
        schedule.showSchedule();
        for (int i = 0; i < studentCount; i++) {
            students[i]->showStudent();
        }
    }
    static void showTotalSections() {
        cout << "Total Sections Offered: " << totalSections << endl;
    }
};

int CourseSection::totalSections = 0;

int main() {
    Student s1("Ali", 101);
    Student s2("Sara", 102);
    Student s3("Ahmed", 103);

    CourseSection sec1("BCS-A", "Mon-Wed", "9:00 AM");
    CourseSection sec2("BCS-B", "Tue-Thu", "11:00 AM");

    sec1.addStudent(&s1);
    sec1.addStudent(&s2);
    sec2.addStudent(&s3);

    sec1.showSection();
    cout << endl;
    sec2.showSection();
    cout << endl;

    CourseSection::showTotalSections();

    return 0;
}
