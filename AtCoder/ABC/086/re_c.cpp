// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 086 Traveling c.cpp
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
  int N;
  cin >> N;
  vector< int > t(N);
  vector< int > x(N);
  vector< int > y(N);
  REP(i, N) {
    cin >> t[i] >> x[i] >> y[i];
  }
  int dx, dy, dt;
  bool ok = true;
  REP(i, N) {
    if (i == 0) {
      dx = x[0];
      dy = y[0];
      dt = t[0];
    } else {
      dx = abs(dx - x[i]);
      dy = abs(dy - y[i]);
      dt = abs(dt - t[i]);
    }
    if ((dx + dy) %2 != dt % 2 || dx + dy > dt) {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

