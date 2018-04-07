// ------------------------------------
// Date:2018/ 4/ 3
// Problem:grid repainting / e.cpp
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
const int MAX_N = 51;

typedef pair< int, int > P;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int H, W;
string s[MAX_N];

int d[MAX_N][MAX_N];

int bfs()
{
  REP(hi, H) fill_n(d[hi], W, INF);
  queue< P > q;
  q.push({0, 0});
  d[0][0] = 0;

  while(!q.empty()) {
    P from = q.front(); q.pop();
    if (from == make_pair(H - 1, W - 1)) return d[H - 1][W - 1];

    REP(i, 4) {
      P next;
      next.first = from.first + dx[i];
      next.second = from.second + dy[i];

      if (!(0 <= next.first && next.first < H &&
	    0 <= next.second && next.second < W)) continue;
      if (d[next.first][next.second] != INF) continue;
      if (s[next.first][next.second] == '#') continue;
      
      d[next.first][next.second] = d[from.first][from.second] + 1;
      q.push(next);
    }
  }
  return INF;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  
  int ans = H * W - 1;
  
  REP(hi, H) {
    cin >> s[hi];
    REP(wi, W)
      if (s[hi][wi] == '#') ans--;
  }

  ans -= bfs();
  if (ans < 0) ans = -1;
  
  cout << ans << endl;

  return 0;
}

