// ------------------------------------
// Date:2018/ 2/20
// Problem:ABC 085 Otoshidama c.cpp
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
  int N,Y;
  cin >> N >> Y;
  REP(i10,N+1) {
    REP(i5,N-i10+1) {
      if (i10*10000 + i5*5000 + (N-i10-i5)*1000 == Y) {
        cout << i10 <<  " "  << i5 << " " << N-i10-i5 << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}

