// ------------------------------------
// Date:2018/ 2/12
// Problem:ABC 002 罠 b.cpp
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

// ----------------------------------------------
void solve(string str)
{
  string ans;
  ans = "";
  for (char ch : str) {
    switch(ch) {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      break;
    default:
      ans += ch;
    }
  }
  cout << ans << endl;
}
// ----------------------------------------------

int main()
{
  string str;
  cin >> str;
  solve(str);
  return 0;
}

