// ------------------------------------
// Date:2018/ 4/ 3
// Problem:壁抜け / / c.cpp
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
const int MOD = 1e9 + 7;
const int MAX_N = 11;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int H, W, T;
string s[MAX_N];

typedef pair< int, int > P;

P S, G;
int d[MAX_N][MAX_N];

bool bfs(int time)
{
  REP(hi, H) fill_n(d[hi], W, INF);
  queue< P > q;
  q.push({S});
  d[S.first][S.second] = 0;

  while(!q.empty()) {
    P from = q.front(); q.pop();
    if (from == G) return true;

    REP(i, 4) {
      P next;
      next.first = from.first + dy[i];
      next.second = from.second + dx[i];

      if (!(0 <= next.first && next.first < H &&
	    0 <= next.second && next.second < W)) continue;

      int cost = s[next.first][next.second] == '#' ? time : 1;

      if (d[next.first][next.second] < d[from.first][from.second] + cost) continue;
      if (d[from.first][from.second] + cost > T) continue;

      d[next.first][next.second] = d[from.first][from.second] + cost;
      q.push(next);
    }
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> T;
  REP(hi, H) {
    cin >> s[hi];
    REP(wi, W) {
      if (s[hi][wi] == 'S') S = {hi, wi};
      if (s[hi][wi] == 'G') G = {hi, wi};
    }
  }

  ll lb = 0;
  ll ub = INF;
  while(ub - lb > 1) {
    ll mid = (lb + ub) / 2;
    if (bfs(mid)) lb = mid;
    else ub = mid;
  }

  int ans = lb;
  cout << ans << endl;

  return 0;
}

