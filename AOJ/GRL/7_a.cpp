#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e5 + 1;
constexpr int MAX_V = 575;

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

int V;
vector< int > G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to) {
  G[from].push_back(to);
  G[to].push_back(from);
}

bool dfs(int v) {
  used[v] = true;
  
  for (int i = 0; i < (int)G[v].size(); ++i) {
    int to = G[v][i], w = match[to];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[v] = to;
      match[to] = v;
      return true;
    }
  }
  return false;
}

signed main() {
  INIT;

  VAR(int, X, Y, E);
  REP(ei, E) {
    VAR(int, from, to);
    add_edge(from, X + to);
  }
  V = X + Y;

  // 二部グラフの最大マッチング
  auto bipartie_matching = []() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; ++v) {
      if (match[v] < 0) {
	memset(used, 0, sizeof(used));
	if (dfs(v) > 0) {
	  res++;
	}
      }
    }
    return res;
  };
  
  OUT(bipartie_matching())BR;

  
  return 0;
}
