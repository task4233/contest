// ------------------------------------
// Date:2018/ 2/25
// Problem:ABC 050 ContestWithDrinkEasy b.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

using ll = long long;

#define MOD 1000000007

int main()
{
  int N,M,P,X;
  ll ans;
  cin >> N;
  int T[111];
  REP(i,N) {
    cin >> T[i];
  }
  cin >> M;
  REP(mi,M) {
    ans = 0ll;
    cin >> P >> X;
    REP(ni,N) {
      if (ni == P-1) ans += X;
      else ans += T[ni];
    }
    cout << ans << endl;
  }
  return 0;
}

