// ------------------------------------
// Date:2018/ 3/ 4
// Problem:ABC 089 _ d.cpp
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

  // D: 進む量;
  int H, W, D;
  cin >> H >> W >> D;
  int t;
  vector< pair< int, int > > a(H * W, {0, 0});
  REP(hi, H) {
    REP(wi, W) {
      cin >> t;
      // a[i] = {x, y};
      a[t - 1].first = wi;
      a[t - 1].second = hi;
    }
  }

  // 足し算の表を作る;
  int tmp = H * W - 1;
  vector< int > d(H * W);
  REP(i, D) {
    d[tmp - i] = 0;
  }
  REP(i, H * W - 1 - D) {
    int dist;
    // from tmp - i to tmp - i + D;
    dist = abs(a[tmp - i].first - a[tmp - i + D].first) + abs(a[tmp - i].second - a[tmp - i + D].second);
    d[tmp - i] = d[tmp - i + D] + dist;
  }

  REP(i, H * W) {
    printf("d[%d] = %d\n", i, d[i]);
  }
  
  int Q;
  cin >> Q;
  REP(qi, Q) {
    int l, r;
    ll ans;
    cin >> l >> r;
    ans = d[l] - d[r];
    cout << ans << endl;
  }
  
  return 0;
}

