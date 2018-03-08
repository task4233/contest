// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 002 KnotPuzzle c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()

using ll = long long;

#define MOD 1000000007

int main()
{
  int N,L,sum;
  cin >> N >> L;
  vector<int> a(N);
  REP(i,N) cin >> a[i];
  
  // a[i]+a[i+1]>=Lの時にPossible
  REP(i,N-1) {
    if (a[i]+a[i+1]>=L) {
      cout << "Possible" << endl;
      FOR(j,1,i+1) cout << j << endl;
      RFOR(j,i+1,N) cout << j << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;
  return 0;
}

