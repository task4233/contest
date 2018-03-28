// ------------------------------------
// Date:2018/ 3/25
// Problem:_ _ _ c.cpp
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
static const int MAX_N = 1e2 + 1;

int N, a, b, M;

vector< int > e[MAX_N];
int d[MAX_N];
ll cnt[MAX_N];

int bfs()
{
  queue< int > q;
  q.push(a - 1);
  d[a - 1] = 0;
  cnt[a  - 1] = 1;
  
  while(!q.empty()) {
    int from = q.front(); q.pop();
    if (from == b - 1) break;

    EACH(to, e[from]) {
      if(d[to] == INF) {
	// 初到達
	d[to] = d[from] + 1;
	cnt[to] += cnt[from];
	q.push(to);
	d[to] %= MOD;
      } else {
	if (d[to] == d[from] + 1) {
	  cnt[to] += cnt[from];
	  // q.push(to);
	  d[to] %= MOD;
	}
      }
    }
  }

  return cnt[b - 1] % MOD;
}

int main()
{

  fill_n(d, MAX_N, INF);
  fill_n(cnt, MAX_N, 0);

  scanf("%d %d %d %d", &N, &a, &b, &M);
  // cin >> N >> a >> b >> M;
  REP(i, M) {
    CIN(x, y);
    e[x - 1].push_back(y - 1);
    e[y - 1].push_back(x - 1);
  }

  int ans = bfs();

  cout << ans << endl;
  
  return 0;
}

