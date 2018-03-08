// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 001 BBQEasy a.cpp
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
  int N,ans = 0;
  cin >> N;
  vector<int> L(2*N);
  REP(i,2*N) {
    cin >> L[i];
  }
  sort(ALL(L));
  REP(i,N) {
    ans += L[i*2];
  }
  cout << ans << endl;
  return 0;
}

