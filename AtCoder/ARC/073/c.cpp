// ------------------------------------
// Date:2018/ 3/ 9
// Problem:ARC 073 Sentou c.cpp
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

typedef long long ll;

// static const int MOD = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, T;
  cin >> N >> T;

  vector< ll > t(N);
  REP(i, N) {
    cin >> t[i];
  }

  ll ans = 0ll;
  REP(i, N - 1) {
    ans += min(t[i + 1] - t[i], T);
  }

  // 最後の一回は必ずT秒出る
  ans += T;
  
  cout << ans << endl;
  
  return 0;
}

