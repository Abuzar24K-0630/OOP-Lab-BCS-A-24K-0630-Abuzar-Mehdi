#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
  string name;

private:
  int rollNumber;

public:
  void setRollNo(int r)
  {
    rollNumber = r;
  }
  int getRollNo()
  {
    return rollNumber;
  }
};

int main()
{
  Student s;
  s.name = "Ali";
  s.setRollNo(101);
  cout << "Name: " << s.name << endl;
  cout << "Roll Number: " << s.getRollNo() << endl;
  return 0;
}
