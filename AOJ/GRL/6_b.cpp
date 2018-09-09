#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

const int MAX_V = 1e5 + 1;
const int INF = 1e9 + 1;

typedef pair< int, int > P;

// O(|E||V|^2)
struct Edge {
  Edge(int _to, int _cap, int _cost, int _rev)
    : to(_to), cap(_cap), cost(_cost), rev(_rev) {}
  int to, cap, cost, rev; // 逆辺
};

int V;
vector< Edge > G[MAX_V]; // グラフの隣接リスト表現
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int _from, int _to, int _cap, int _cost) {
  G[_from].emplace_back(Edge(_to, _cap, _cost, G[_to].size()));
  G[_to].emplace_back(Edge(_from, 0, -_cost, G[_from].size() - 1));
}

// sからtへの流量fの最小費用流を求める
// 流せない場合は-1を返す
int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h, h + V, 0);
  while (f > 0) {
    // ダイクストラ法を用いてhを更新する
    priority_queue< P, vector< P >, greater< P > > q;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    q.push(P(0, s));
    while (!q.empty()) {
      P p = q.top(); q.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (int i = 0; i < (int)G[v].size(); ++i) {
	Edge &e = G[v][i];
	if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
	  dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
	  prevv[e.to] = v;
	  // cout << "v:" << v << endl;
	  preve[e.to] = i;
	  // cout << "i:" << i << endl;
	  q.push(P(dist[e.to], e.to));
	}
      }
    }
    if (dist[t] == INF) {
      return -1;
    }
    
    for (int v = 0; v < V; ++v) h[v] += dist[v];

    // cout << "f:" << f << endl;
    // s-t間最短経路に沿って目一杯流す
    int d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, G[prevv[v]][preve[v]].cap);
      /*
      cout << G[prevv[v]][preve[v]].cap << endl;
      cout << prevv[v] << endl;
      cout << "d:" <<  d << endl;
      */
    }
    f -= d;
    // cout << "f:" << f << endl;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      Edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
    // cout << "d:" <<  d << endl;
    // cout << 1 << endl;
  }
  return res;
}



int main()
{
  int E, F;
  cin >> V >> E >> F;
  for (int i = 0; i < E; ++i) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    add_edge(u, v, c, d);
  }
  cout << min_cost_flow(0, V - 1, F) << endl;
  return 0;
}
