// ------------------------------------
// Date:2018/ 4/ 2
// Problem:D- Grid Repainting re_d.cpp
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
const int MAX_N = 50;

int H, W;

string s[MAX_N];

int d[MAX_N][MAX_N];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs()
{
  queue< pair< int, int > > q;
  q.push({0, 0});
  REP(hi, H)
    fill_n(d[hi], W, INF);

  d[0][0] = 0;

  while(!q.empty()) {
    int fromX, fromY;
    tie(fromY, fromX) = q.front(); q.pop();
    if (fromY == H - 1 && fromX == W - 1) return d[H - 1][W - 1];

    REP(i, 4) {
      int nextX = fromX + dx[i];
      int nextY = fromY + dy[i];

      if (!(0 <= nextY && nextY < H &&
	    0 <= nextX && nextX < W)) continue;
      if (d[nextY][nextX] != INF) continue;
      if (s[nextY][nextX] == '#') continue;
      d[nextY][nextX] = d[fromY][fromX] + 1;
      q.push({nextY, nextX});
    }
  }
  return INF;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int cnt = 0;
  cin >> H >> W;
  REP(hi, H) {
    cin >> s[hi];
    REP(wi, W) {
      if (s[hi][wi] == '#') cnt++;
    }
  }
  int ans = H * W - cnt - bfs() - 1;
  if (ans < 0) ans = -1;
  cout << ans << endl;
  
  return 0;
}

