#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  int a, b, c;
  a = b = c = 0;
  char turn = 'a';
  while (1) {
    switch(turn) {
    case 'a':
      if (a == s1.size()) {
	cout << 'A' << endl;
	return 0;
      }
      turn = s1[a++];
      break;
    case 'b':
      if (b == s2.size()) {
	cout << 'B' << endl;
	return 0;
      }
      turn = s2[b++];
      break;
    case 'c':
      
      if (c == s3.size()) {
	cout << 'C' << endl;
	return 0;
      }
      turn = s3[c++];
      break;
    }
  }
  
  return 0;
}
