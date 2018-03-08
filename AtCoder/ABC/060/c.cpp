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

int main()
{
  ll ans = 0;
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  
  ll sum = 0;
  int N, T, tmp;
  cin >> N >> T;
  vector< int > t(N);
  REP(i, N) {
    cin >> t[i];
  }
  REP(i, N) {
    if (ans == 0) {
      ans += t[i] + T;
    } else {
      if (ans >= t[i]) {
        ans = (ans>t[i]+T) ? ans : t[i] + T;
      } else {
        cout << ans << endl;
        sum += ans;
        ans = 0;
      }
    }
  }
  sum += ans;
  cout << sum << endl;
  
  return 0;
}

