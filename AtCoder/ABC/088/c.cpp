// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 088 _ c.cpp
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
  int C[3][3];
  int b2,b3,a2,a3,t,d,t1,t2,t3;
  REP(i,3) {
    REP(j,3) {
      cin >> C[i][j];
    }
  }
  b2 = C[0][0] - C[0][1];
  b3 = C[0][0] - C[0][2];
  a2 = C[0][0] - C[1][0];
  a3 = C[0][0] - C[2][0];
  
  REP(i,3) {
    REP(j,3) {
      if (i == 1) C[i][j] += b2;
      if (i == 2) C[i][j] += b3;
      if (j == 1) C[i][j] += a2;
      if (j == 2) C[i][j] += a3;
    }
  }
  
  REP(i,3) {
    if (i == 0) {
      t = C[i][0];
      continue;
    }
    if (t != C[i][0]) {
      d = t - C[i][0];
      REP(j,3) {
        C[i][j] += d;
      }
    }
    
  }
  
  t1 = C[0][0];
  t2 = C[0][1];
  t3 = C[0][2];
  FOR(i,1,3) {
    if (t1 == C[i][0] && t2 == C[i][1] && t3 == C[i][2]) {
    } else {
      cout << "No" << endl;
      return 0;
     }
  }
  cout << "Yes" << endl;
  
  return 0;
}

