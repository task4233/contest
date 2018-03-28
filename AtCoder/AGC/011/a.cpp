// ------------------------------------
// Date:2018/ 3/15
// Problem:AGC 011 AirportBus a.cpp
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

static const int INF = 100000001;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, C, K;
  cin >> N >> C >> K;
  vector< int > T(N);
  REP(i, N) cin >> T[i];

  sort(ALL(T));

  int cnt = 0;
  int limit = 0;
  int ans = 0;
  REP(ti, T.size()) {
    if (ti != 0 and (limit < T[ti] or cnt >= C)) {
      // 境界値よりも次の人が遅い もしくは 乗車人数がMAXのとき
      ans++;
      cnt = 0;
    }
    if (cnt == 0) {
      limit = T[ti] + K;
    }
    cnt++;
    // debug(ti);
    // debug(ans);
  }
  if (cnt > 0) {
    ans++;
    cnt = 0;
  }
  cout << ans << endl;
  return 0;
}

