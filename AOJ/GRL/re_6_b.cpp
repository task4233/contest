#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_V = 1e4 + 1;

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
  int to, cap, cost, rev;
};

int V;
vector< Edge > G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
  G[from].push_back((Edge){to, cap, cost, (int)G[to].size()});
  G[to].push_back((Edge){from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h, h + V, 0);
  while (f > 0) {
    priority_queue< PAIR, vector< PAIR >, greater< PAIR > > q;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    q.push(PAIR(0, s));
    while (!q.empty()) {
      PAIR p = q.top(); q.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (int i = 0; i < (int)G[v].size(); ++i) {
	Edge &e = G[v][i];
	if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
	  dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
	  prevv[e.to] = v;
	  preve[e.to] = i;
	  q.push(PAIR(dist[e.to], e.to));
	}
      }
    }

    if (dist[t] == INF) return -1;
    for (int v = 0; v < V; ++v) h[v] += dist[v];

    int d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      Edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

signed main() {
  INIT;

  cin >> V;
  VAR(int, E, F);
  while (E--) {
    VAR(int, a, b, c, d);
    add_edge(a, b, c, d);
  }
  OUT(min_cost_flow(0, V - 1, F))BR;
  return 0;
}
