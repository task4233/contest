#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

  // O(|E||V|^2)
template< class Abel > class Dinic {
public:
  Dinic(int _V = 575) : V(_V) { init(_V); }

  void init(int _V) {
    G.resize(_V);
    level.resize(_V);
    iter.resize(_V);
  }
  
  // fromからtoに向かう容量capの辺グラフに追加する
  void add_edge(int _from, int _to, Abel _cap) {
    G[_from].emplace_back(Edge(_to, _cap, G[_to].size()));
    G[_to].emplace_back(Edge(_from, 0, G[_from].size() - 1));
  }

  // sからの最短距離をBFSで探す
  void bfs(int s) {
    level.assign(V, -1);
    queue< int > q;
    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
      int from = q.front(); q.pop();
      for (int i = 0; i < G[from].size(); ++i) {
	Edge &e = G[from][i];
	if (e.cap > 0 && level[e.to] < 0) {
	  level[e.to] = level[from] + 1;
	  q.push(e.to);
	}
      }
    }
  }


  // 増加パスをDFSで探す
  Abel dfs(int from, int to, int cost) {
    if (from == to) return cost;
    for (int &i = iter[from]; i < G[from].size(); ++i) {
      Edge &e = G[from][i];
      if (level[from] < level[e.to] && e.cap > 0) {
	Abel d = dfs(e.to, to, min(cost, e.cap));
	if (d > 0) {
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }


  // sからtへの最大流を求める
  Abel max_flow(int s, int t) {
    int flow = 0;
    for ( ; ; ) {
      bfs(s);
      if (level[t] < 0) return flow;
      iter.assign(V, 0);
      Abel f;
      while ((f = dfs(s, t, INF)) > 0) { 
	flow += f;
      }
    }
  }

private:
  struct Edge {
    Edge(int _to, Abel _cap, int _rev)
      : to(_to), cap(_cap), rev(_rev) {}
    int to;
    Abel cap; // 容量
    int rev; // 逆辺
  };

  int V;
  vector< vector< Edge > > G; // グラフの隣接リスト表現
  vector< int > level;        // sからの距離
  vector< int > iter;         // どこまで調べ終わったか

};

int main()
{
  int V, E, u, v, c;
  cin >> V >> E;

  Dinic< int > d(V + 1);
  while (E--) {
    cin >> u >> v >> c;
    d.add_edge(u, v, c);
  }
  cout << d.max_flow(0, V - 1) << endl;
  
  return 0;
}
