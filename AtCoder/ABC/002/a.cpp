// ------------------------------------
// Date:2018/ 2/12
// Problem:ABC 002 正直者 a.cpp
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

int main()
{
  int X, Y;
  cin >> X >> Y;
  cout << max(X,Y) << endl;
  return 0;
}

