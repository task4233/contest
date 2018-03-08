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
  int N,dt,dx,dy,d;
  cin >> N;
  vector<int> t(N),x(N),y(N);
  REP(i,N) {
    cin >> t[i] >> x[i] >> y[i];
  }
  REP(i,N-1) {
    {
      dt = t[i+1]-t[i];
      dx = abs(x[i]-x[i+1]);
      dy = abs(y[i]-y[i+1]);
    }
    d = dx + dy;
    if (d%2 != dt%2) break;
    if (i == N-2) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

