#include <iostream>
#include <string>
using namespace std;

void FirstAndLastIndex(string str, char ch, int *first, int *last)
{
  *first = -1;
  *last = -1;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == ch)
    {
      if (*first == -1)
      {
        *first = i;
      }
      else
      {
        *last = i;
      }
    }
  }
}

int main()
{
  string s = "programming";
  char c = 'g';
  int firstIndex, lastIndex;
  FirstAndLastIndex(s, c, &firstIndex, &lastIndex);
  cout << "First Index: " << firstIndex << endl;
  cout << "Last Index: " << lastIndex << endl;
  return 0;
}
