// ------------------------------------
// Date:2018/ 2/18
// Problem:ARC 013 梱包できるかな？ a.cpp
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
  int ans = 0;
  int N,M,L;
  int P,Q,R;
  cin >> N >> M >> L;
  cin >> P >> Q >> R;
  
  ans = max(ans,(N/P)*(M/Q)*(L/R));
  ans = max(ans,(N/P)*(M/R)*(L/Q));
  ans = max(ans,(M/P)*(N/Q)*(L/R));
  ans = max(ans,(M/P)*(N/R)*(L/Q));
  ans = max(ans,(L/P)*(M/Q)*(N/R));
  ans = max(ans,(L/P)*(M/R)*(N/Q));
  cout << ans << endl;
  return 0;
}
