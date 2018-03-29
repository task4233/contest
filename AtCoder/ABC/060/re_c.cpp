// ------------------------------------
// Date:2018/ 3/ 4
// Problem:ABC 060 Sentou c.cpp
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

static const int MOD = 1000000007;

int N, T;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> T;
  vector< int > t(N + 1, 0);
  REP(i, N)
    cin >> t[i + 1];

  ll ans = T;
  REP(i, N) {
    ans += min(T, t[i + 1] - t[i]);
  }

  cout << ans << endl;
  
  return 0;
}

