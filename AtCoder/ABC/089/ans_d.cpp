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


// D: 進む量
int H, W, D;
pair< int, int > dist[90909];


int memo[90909];

int solve(int x)
{
  if (dist[x] != 0) return dist[x];
  if (x < D) return 0;

  int tmp = abs(dist[x].first - dist[x - D].first) + abs(dist[x].second - dist[x - D].second);
  int res = solve(x - D) + tmp;
  return memo[i] = res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> H >> W >> D;
  int t;
  REP(hi, H) {
    REP(wi, W) {
      cin >> t;
      dist[t - 1] = {wi, hi};
    }
  }
  int Q;
  cin >> Q;
  REP(qi, Q) {
    int l, r;
    ll ans;
    cin >> l >> r;
    ll ans = solve(r) - solve(l);
    cout << ans << endl;
  }
  
  return 0;
}

