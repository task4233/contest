// ------------------------------------
// Date:2018/ 3/25
// Problem:C - 壁抜け c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
static const int MOD = 1e9 + 7;
static const int MAX_N = 10;

typedef pair< int, int > P;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int H, W, T;
string m[MAX_N];

P s, g;
P dp[MAX_N][MAX_N];

int solve()
{
  int res = INF;
  queue< pair< P, int > > q;
  q.push({s, 0});
  while(!q.empty()) {
    P pos;
    int cnt;
    tie(pos, cnt) = q.front();
    q.pop();

    if (pos == g) {
      int tmp = T - dp[pos.second][pos.first].first;
      res = min(res, (tmp / cnt + tmp % cnt == 0 ? 0 : 1));
    }

    REP(dist, 4) {
      int toX = pos.first + dx[dist];
      int toY = pos.second + dy[dist];
      if (!(0 < toX and toX < W - 1) and
	  !(0 < toY and toY < H - 1)) continue;
      if (m[toY][toX] == '#') cnt++;
      if (dp[toY][toX].first <= dp[pos.second][pos.first].first + 1 or
	  dp[toY][toX].second >= cnt) continue;
      dp[toY][toX].second = cnt;
      q.push({{toX, toY}, cnt});
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> T;
  REP(hi, H) {
    cin >> m[hi];
  }
  
  REP(hi, H) {
    REP(wi, W) {
      if (m[hi][wi] == 'S') s = {wi, hi};
      if (m[hi][wi] == 'G') g = {wi, hi};
    }
  }

  
  int ans = solve();

  cout << ans << endl;

  return 0;
}

