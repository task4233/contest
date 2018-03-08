// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 086 1_21 b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main()
{
  int a,b,t,d;
  cin >> a >> b;
  d = b;
  t = 0;
  while (d>0) {
    d /= 10;
    ++t;
  }
  REP(i,t) {
    a *= 10;
  }
  a += b;
  REP(i,500) {
    if (i*i>a) break;
    if (i*i == a) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

