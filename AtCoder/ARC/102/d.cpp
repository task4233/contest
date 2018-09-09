#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e5 + 1;
constexpr int MAX_M = 60;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout <<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<"\n";
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

struct Edge {
  int from;
  int to;
  int cost;
};

vector< Edge > e;

signed main() {
  INIT;

  VAR(int, L);
  int N = 1, tmp = L;
  while (tmp >>= 1) N++;

  int cnt = 0, s = 1;
  FOR(i, 1, N) {
    e.push_back(Edge{i, i + 1, 0});
    e.push_back(Edge{i, i + 1, s});
    cnt += s;
    s <<= 1;
  }

  int p = 1;
  tmp = 1;
  while (L > 1) {
    if (L % 2 == 1) {
      e.push_back(Edge{p, N, cnt + 1});
      cnt += tmp;
    }
    L >>= 1;
    p++;
    tmp <<= 1;
  }

  OUT(N)SP OUT(e.size())BR;

  EACH(ei, e) {
    OUT(ei.from)SP OUT(ei.to)SP OUT(ei.cost)BR;
  }
  
  return 0;
}
