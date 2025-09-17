#include <iostream>
#include <string>
using namespace std;

class Concrete
{
private:
  string message;

public:
  Concrete(string m)
  {
    message = m;
  }
  void displayMessage()
  {
    cout << message << endl;
  }
};

int main()
{
  Concrete obj("Abuzar Mehdi 24k-0630");
  obj.displayMessage();
  return 0;
}
