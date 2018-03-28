// ------------------------------------
// Date:2018/ 3/27
// Problem:C - 壁抜け re_c.cpp
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
const int MAX_N = 10;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Pos {
  ll y;
  ll x;
};

ll H, W, T;
Pos S, G;
string m[MAX_N];

// d[hi][wi] = cost
ll d[MAX_N][MAX_N];

bool bfs(ll _cost)
{
  memset(d, INF, sizeof(d));

  queue< Pos > q;
  q.push(S);
  d[S.y][S.x] = 0;

  while(!q.empty()) {
    Pos from = q.front();
    q.pop();

    if (from.y == G.y && from.x == G.x) return true;

    REP(i, 4) {
      Pos next;
      next.y = from.y + dy[i];
      next.x = from.x + dx[i];
      if (!(0 <= next.y && next.y < H and
	    0 <= next.x && next.x < W)) continue;
      ll cnt;
      if (m[next.y][next.x] == '#') cnt = d[from.y][from.x] + _cost;
      else cnt = d[from.y][from.x] + 1;

      if (cnt > T) continue;
      if (cnt >= d[next.y][next.x]) continue;
      d[next.y][next.x] = cnt;
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
    cin >> m[hi];
    REP(wi, W) {
      if (m[hi][wi] == 'S') S = {hi, wi};
      if (m[hi][wi] == 'G') G = {hi, wi};
    }
  }

  ll lb = 0;
  ll ub = T;
  while (ub - lb > 1) {
    ll mid = (lb + ub) / 2;
    if (bfs(mid)) lb = mid;
    else ub = mid;
  }
  
  ll ans = lb;
  
  /*
  RFOR(i, 1, T + 1) {
    ans = i;
    if (bfs(i)) break; 
  }
  */
  
  cout << ans << endl;
  
  return 0;
}

