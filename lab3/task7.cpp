#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
  string name;
  int rollNo;
  double marks;
  string grade;

public:
  Student(string n, int r, double m)
  {
    name = n;
    rollNo = r;
    marks = m;
  }

  string calculateGrade()
  {
    if (marks >= 90 && marks <= 100)
    {
      grade = "A";
    }
    else if (marks >= 80 && marks < 90)
    {
      grade = "B";
    }
    else if (marks >= 70 && marks < 80)
    {
      grade = "B";
    }
    else if (marks >= 0 && marks < 70)
    {
      grade = "F";
    }
    return grade;
  }
  void displayStudentInfo()
  {
    cout << "Name : " << name << endl;
    cout << "RollNo : " << rollNo << endl;
    cout << "Marks : " << marks << endl;
    cout << "Grade : " << grade << endl;
  }
};

int main()
{
  cout << "Stuent Info" << endl;
  Student obj1("ali", 01, 83);
  obj1.calculateGrade();
  obj1.displayStudentInfo();
  Student obj2("Abuzar", 02, 91);
  obj2.calculateGrade();
  obj2.displayStudentInfo();
}