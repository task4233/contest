// ------------------------------------
// Date:2018/ 1/26
// Problem:SRM480 Div2 Level1 cryptography.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

class Cryptography {
public:
  long long encrypt(vector<int> numbers)
  {
    int size,m,num;
    long long ans;
    m = ans = 0;
    size = numbers.size();
    REP(i,size) {
      m = min(numbers[i],m);
      if (m == numbers[i]) num = i; 
    }
    ans = ++numbers[num];
    REP(i,size) {
      if (i == num) continue;
      ans *= numbers[i];
    }
    return ans;
  }
};

int main()
{
  Cryptography c;
  int n;
  vector<int> numbers;
  while(cin >> n) {
    if (n==0) break;
    numbers.push_back(n);
  }
  cout << c.encrypt(numbers) << endl;
  return 0;
}

