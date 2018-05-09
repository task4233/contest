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
const int MAX_N = 55;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int H, W;
string S[MAX_N];
int d[MAX_N][MAX_N];

typedef pair< int, int > PI;

int dfs()
{
  REP(i, MAX_N) {
    fill_n(d[i], MAX_N, INF);
  }
  queue< PI > q;
  q.push(make_pair(0, 0));
  d[0][0] = 0;

  while(!q.empty()) {
    PI from = q.front(); q.pop();

    if (from.first == H - 1 && from.second == W - 1) break;
    
    REP(i, 4) {
      int nextY = from.first + dy[i];
      int nextX = from.second + dx[i];

      if (!(0 <= nextX && nextX < W and
	    0 <= nextY && nextY < H)) continue;
      if (S[nextY][nextX] == '#') continue;
      if (d[nextY][nextX] < INF) continue;

      d[nextY][nextX] = d[from.first][from.second] + 1;
      q.push(make_pair(nextY, nextX));
    }
  }

  return d[H - 1][W - 1] + 1;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  int ans = H * W;
  REP(hi, H) {
    cin >> S[hi];
    REP(wi, W) {
      if (S[hi][wi] == '#') {
	ans--;
      }
    }
  }

  ans -= dfs();
  if (ans < 0) ans = -1;
  
  cout << ans << endl;
  
  return 0;
}

