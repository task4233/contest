// ------------------------------------
// Date:2018/ 3/ 3
// Problem:ABC 038 単調増加 c.cpp
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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  scanf("%d", &N);
  vector< int > a(N);
  REP(i, N) {
    scanf("%d", &a[i]);
  }
  ll cnt = 0ll;
  int last = 0;
  ll ans = 0ll;
  REP(i, N) {
    if (last < a[i]) {
      ++cnt;
      last = a[i];
      // 保持
    } else {
      ans += ((1 + cnt) * cnt) / 2;
      cnt = 0;
      last = 0;
      --i;
    }
  }
  ans += ((1 + cnt) * cnt) / 2;
  cout << ans << endl;
  return 0;
}

