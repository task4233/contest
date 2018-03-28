// ------------------------------------
// Date:2018/ 3/17
// Problem:Not so Diverse b.cpp
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

int cnt[202020];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fill_n(cnt, 202020, 0);
  int N, K;
  cin >> N >> K;
  vector< pair< int, int > > a;
  REP(i, N) {
    int t;
    cin >> t;
    cnt[t - 1]++;
  }
  sort(cnt, cnt + 202020, greater< int >());

  ll ans = 0ll;
  FOR(i, K, 202020) {
    ans += cnt[i];
  }

  cout << ans << endl;
  
  return 0;
}

